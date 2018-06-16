#pragma once
#include <QtGui/QImage>
#include <QtCore/QPointF>
#include <QtGui/QColor>

#include "opencv2/highgui/highgui.hpp"
#include <boost/geometry.hpp>

#include <vector>
#include <string>

typedef boost::geometry::model::point<float, 2, boost::geometry::cs::cartesian> point2d;

class ImageFeatureExtractor
{
public:
    ImageFeatureExtractor() {};
    ImageFeatureExtractor(const QImage&);
    ImageFeatureExtractor(const std::string& imagePath);
    ~ImageFeatureExtractor();

    static QImage toQImage(const cv::Mat&);
    static cv::Mat fromQImage(const QImage&);
    static float colorDistance(const QColor& color1, const QColor& color2);

    void quantize(int n_colors);
    std::vector<QColor> getColors() const;

    std::vector<float> getX() const { return _x; }
    std::vector<float> getY() const { return _y; }

    QColor getClosestColor(QColor color) const;

    std::vector<QColor> getColorsAroundPoint(const point2d&, float pick_radius = 10.f, float threshold = 20.f) const;

    // Higher level methods
    void binarizeFromColor(QColor color);
    void binarizeFromPick(const point2d& point, float pick_radius, float threshold);
    // These two do the whole process
    void processImageFromColor(int n_colors, QColor color, int step);
    void processImageFromPick(int n_colors, const point2d& point, float pick_radius, float threshold, int step);
    void extractDataSimplifyDouglasPecker(float delta_x, float epsilon);

    void setExtractedX(std::vector<int> x) { _extracted_pixels_x = x; }
    void setExtractedY(std::vector<int> y) { _extracted_pixels_y = y; }


private:
    void binarize(QColor color);
    void binarize(std::vector<QColor> colors);
    void extractPixels();
    void extractData(int step);

    cv::Mat originalImage_;
    cv::Mat quantizatedImage_;

    cv::Mat _quant_colors;
    std::vector<float> _quant_colors_hist;

    std::vector<QPointF> pickedPoints;

    std::vector<int> _extracted_pixels_x;
    std::vector<int> _extracted_pixels_y;

    std::vector<float> _x;
    std::vector<float> _y;
};

