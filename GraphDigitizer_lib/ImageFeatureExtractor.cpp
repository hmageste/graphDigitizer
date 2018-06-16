#include "ImageFeatureExtractor.h"

#include <boost/algorithm/clamp.hpp>

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/flann/flann.hpp"
#include "opencv2/ximgproc.hpp"

#include <set>
#include <math.h> //round
#include <algorithm>
//#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()

using namespace cv;

ImageFeatureExtractor::ImageFeatureExtractor(const QImage& qImage)
{
    originalImage_ = fromQImage(qImage);
}


ImageFeatureExtractor::ImageFeatureExtractor(const std::string& imagePath)
{
    originalImage_ = cv::imread(imagePath, IMREAD_COLOR);
}


ImageFeatureExtractor::~ImageFeatureExtractor()
{
}

QImage ImageFeatureExtractor::toQImage(const Mat& image)
{
    QImage qImage = QImage((uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888).rgbSwapped();
    return qImage;
    //return QPixmap::fromImage(qimage);
}

Mat ImageFeatureExtractor::fromQImage(const QImage& image)
{
    Mat matImage(image.height(), image.width(), CV_8UC3, image.bytesPerLine()); //, image.bytesPerLine());
    cv::cvtColor(matImage, matImage, COLOR_RGB2BGR);
    return matImage;
}


float ImageFeatureExtractor::colorDistance(const QColor& color1, const QColor& color2)
{
    float dr = color1.red() - color2.red();
    float dg = color1.green() - color2.green();
    float db = color1.blue() - color2.blue();

    return sqrt(dr*dr + dg * dg + db * db);
}


std::vector<QColor> ImageFeatureExtractor::getColors() const
{
    std::vector<QColor> colors(_quant_colors.rows);

    for (int i = 0; i < _quant_colors.rows; i++) {
        int r = boost::algorithm::clamp(round(_quant_colors.at<float>(i, 2)), 0.f, 255.f); // OpenCV uses BGR instead of RGB
        int g = boost::algorithm::clamp(round(_quant_colors.at<float>(i, 1)), 0.f, 255.f);
        int b = boost::algorithm::clamp(round(_quant_colors.at<float>(i, 0)), 0.f, 255.f);
        colors[i].setRgb(r, g, b);
    }

    return colors;
}

QColor ImageFeatureExtractor::getClosestColor(QColor color) const
{
    std::vector<QColor> colors = getColors();
    float min_dist = 500.0; // The maximum distance in the used metric is around 442
    QColor closest_color;

    for (QColor quant_color : colors) {
        float dist = colorDistance(color, quant_color);
        if (dist < min_dist) {
            min_dist = dist;
            closest_color = quant_color;
        }
    }

    return closest_color;
}

std::vector<QColor> ImageFeatureExtractor::getColorsAroundPoint(const point2d& point, float pick_radius, float threshold) const
{
    std::vector<QColor> quant_colors = getColors();
    std::vector<QColor> selected_colors;

    const float x_coord = point.get<0>();
    const float y_coord = point.get<1>();
    int closest_x = round(x_coord);
    int closest_y = round(y_coord);
    int pixel_radius = ceil(pick_radius);

    int i_start = std::max(0, closest_y - pixel_radius - 1);
    int i_end = std::min(quantizatedImage_.rows, closest_y + pixel_radius + 2);
    int j_start = std::max(0, closest_x - pixel_radius - 1);
    int j_end = std::min(quantizatedImage_.cols, closest_x + pixel_radius + 2);

    std::vector<float> local_hist(_quant_colors_hist.size());
    int n_points = 0;

    for (int i = i_start; i < i_end; ++i) {
        for (int j = j_start; j < j_end; j++) {
            float dx = x_coord - j;
            float dy = y_coord - i;
            float dist = sqrt(dx*dx + dy * dy);

            if (dist <= pick_radius) {
                int label = quantizatedImage_.at<unsigned char>(i, j);
                local_hist[label] += 1.0;
                n_points++;
            }
        }
    }

    for (int i = 0; i < quant_colors.size(); ++i) {
        if (local_hist[i] / _quant_colors_hist[i] / n_points > threshold) {
            selected_colors.push_back(quant_colors[i]);
        }
    }

    // If no color is higher than the threshold pick the color of the picked pixel
    if (selected_colors.empty()) {
        int label = quantizatedImage_.at<unsigned char>(closest_y, closest_x);
        selected_colors.push_back(quant_colors[label]);
    }

    return selected_colors;
}

void ImageFeatureExtractor::quantize(int n_colors)
{
    // From: http://answers.opencv.org/question/27808/how-can-you-use-k-means-clustering-to-posterize-an-image-using-c/

    Mat samples(originalImage_.rows * originalImage_.cols, 3, CV_32F);
    for (int y = 0; y < originalImage_.rows; y++)
        for (int x = 0; x < originalImage_.cols; x++)
            for (int z = 0; z < 3; z++)
                samples.at<float>(y + x * originalImage_.rows, z) = originalImage_.at<cv::Vec3b>(y, x)[z];

    //    int n_colors = 16;
    int attempts = 5;
    Mat labels;
    _quant_colors_hist.resize(n_colors);

    cv::kmeans(samples, n_colors, labels, cv::TermCriteria(TermCriteria::MAX_ITER | TermCriteria::EPS, 10000, 0.0001), attempts, cv::KMEANS_PP_CENTERS, _quant_colors);
    quantizatedImage_.create(originalImage_.rows, originalImage_.cols, CV_8UC1);

    for (int y = 0; y < originalImage_.rows; y++)
        for (int x = 0; x < originalImage_.cols; x++)
        {
            int label = labels.at<int>(y + x * originalImage_.rows, 0);
            quantizatedImage_.at<unsigned char>(y, x) = label;
            _quant_colors_hist[label] += 1.0;
        }

    // Normalize the histogram
    for (int i = 0; i < n_colors; i++) {
        _quant_colors_hist[i] /= originalImage_.rows * originalImage_.cols;
    }
}

// TODO:: this function should be the one called multiple times not the opposite
void ImageFeatureExtractor::binarize(QColor color)
{
    std::vector<QColor> colors(1, color);
    binarize(colors);
}

void ImageFeatureExtractor::binarize(std::vector<QColor> colors)
{
    std::set<unsigned char> labels;

    std::vector<QColor> qtcolors = getColors();

    for (int i = 0; i < colors.size(); i++)
        for (int j = 0; j < qtcolors.size(); j++) {
            if (colors[i] == qtcolors[j]) {
                labels.insert(j);
                break;
            }
        }

    for (int y = 0; y < quantizatedImage_.rows; y++)
        for (int x = 0; x < quantizatedImage_.cols; x++)
        {
            if (labels.find(quantizatedImage_.at<unsigned char>(y, x)) != labels.end()) {
                quantizatedImage_.at<unsigned char>(y, x) = 255;
            }
            else {
                quantizatedImage_.at<unsigned char>(y, x) = 0;
            }
        }
}


// If we want to do the propagator from pick position we need to reimplement this
// Also, the order of the pixels is very important. This will work properly only in
// proper bijective functions (i.e. one y per x)
void ImageFeatureExtractor::extractPixels()
{
    for (int x = 0; x < quantizatedImage_.cols; ++x)
    {
        for (int y = 0; y < quantizatedImage_.rows; ++y)
        {
            if (quantizatedImage_.at<unsigned char>(y, x) == 255) {
                _extracted_pixels_x.push_back(x);
                _extracted_pixels_y.push_back(y);
            }
        }
    }
}

// Doing what Yuval suggested: just skipping points
void ImageFeatureExtractor::extractData(int step)
{
    for (int i = 0; i < _extracted_pixels_x.size(); i += step)
    {
        _x.push_back(_extracted_pixels_x[i]);
        _y.push_back(_extracted_pixels_y[i]);
    }
}

void ImageFeatureExtractor::binarizeFromColor(QColor color)
{
    QColor closest_color = getClosestColor(color);
    binarize(closest_color);
}

void ImageFeatureExtractor::binarizeFromPick(const point2d& point, float pick_radius, float threshold)
{
    std::vector<QColor> colors = getColorsAroundPoint(point, pick_radius, threshold);
    binarize(colors);
}

void ImageFeatureExtractor::processImageFromColor(int n_colors, QColor color, int step)
{
    quantize(n_colors);
    binarizeFromColor(color);
    cv::ximgproc::thinning(quantizatedImage_, quantizatedImage_, cv::ximgproc::THINNING_ZHANGSUEN); //cv::ximgproc::THINNING_GUOHALL
    extractPixels();
    extractData(step);
}

void ImageFeatureExtractor::processImageFromPick(int n_colors, const point2d& point, float pick_radius, float threshold, int step)
{
    quantize(n_colors);
    binarizeFromPick(point, pick_radius, threshold);
    cv::ximgproc::thinning(quantizatedImage_, quantizatedImage_, cv::ximgproc::THINNING_ZHANGSUEN); //cv::ximgproc::THINNING_GUOHALL
    extractPixels();
    extractData(step);
}


static float distanceFromPointToLine(float point_x, float point_y, float line_start_x, float line_start_y, float line_end_x, float line_end_y) {
    float delta_x = line_end_x - line_start_x;
    float delta_y = line_end_y - line_start_y;
    float c = line_end_x * line_start_y - line_start_x * line_end_y;
    float length = sqrt(delta_x*delta_x + delta_y * delta_y);

    float distance = abs(point_x*delta_y - point_y * delta_x + c) / length;

    return distance;
}


static void simplifyDouglasPecker(float epsilon, int idx_start, int idx_end, const std::vector<float>& x, const std::vector<float>& y, std::vector<float>& out_x, std::vector<float>& out_y) {
    // https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm
    float max_dist = 0.0;
    int idx_max = 0;

    for (int i = idx_start + 1; i < idx_end - 1; ++i) {
        float dist = distanceFromPointToLine(x[i], y[i], x[idx_start], y[idx_start], x[idx_end], y[idx_end]);
        if (dist > max_dist) {
            max_dist = dist;
            idx_max = i;
        }
    }

    if (max_dist > epsilon) {
        std::vector<float> x_right;
        std::vector<float> y_right;
        simplifyDouglasPecker(epsilon, idx_start, idx_max, x, y, out_x, out_y);
        simplifyDouglasPecker(epsilon, idx_max, idx_end, x, y, x_right, y_right);
        out_x.insert(out_x.end(), std::next(x_right.begin()), x_right.end());
        out_y.insert(out_y.end(), std::next(y_right.begin()), y_right.end());
    }
    else {
        out_x.push_back(x[idx_start]);
        out_x.push_back(x[idx_end]);
        out_y.push_back(y[idx_start]);
        out_y.push_back(y[idx_end]);
    }
}

static void linearInterpolation(float delta_x, const std::vector<float>& x, const std::vector<float>& y, std::vector<float>& out_x, std::vector<float>& out_y) {
    float x0 = x.front();
    float xn = x.back();
    float xp = x0;

    for (int i = 0; i < x.size() - 1; i++) {
        while (xp < x[i + 1]) {
            out_x.push_back(xp);
            out_y.push_back(y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i])*(xp - x[i]));
            xp += delta_x;
        }
    }
}

void ImageFeatureExtractor::extractDataSimplifyDouglasPecker(float delta_x, float epsilon) {
    _x.clear();
    _y.clear();

    std::vector<float> x;
    std::vector<float> y;

    std::vector<float> x_convert(std::make_move_iterator(_extracted_pixels_x.begin()), std::make_move_iterator(_extracted_pixels_y.end()));
    std::vector<float> y_convert(_extracted_pixels_y.begin(), _extracted_pixels_y.end());
    simplifyDouglasPecker(epsilon, 0, _extracted_pixels_x.size() - 1, x_convert, y_convert, x, y);
    linearInterpolation(delta_x, x, y, _x, _y);
}
