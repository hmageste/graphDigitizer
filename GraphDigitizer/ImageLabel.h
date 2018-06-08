#pragma once

#include <QImage>
#include <QLabel>

class GraphDigitizer;

class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    ImageLabel(QWidget *parent = Q_NULLPTR);
    virtual ~ImageLabel();

    void clearAxisPoints();
    void displayAxis(bool);
    void pickMode(bool);

    GraphDigitizer& getModel() const { return model_; };

    inline bool displayAxis() const { return displayAxis_; }

    inline QVector<QPointF> getPxAxisPoints() const { return pxAxisPoints_; };
    inline const QImage& image() const { return image_; };

    void setImage(const QImage &newImage);
    float scaleImage(float factor);

    inline void setScaleFactor(float factor) { scaleFactor_ = factor; };

protected:
    void mouseMoveEvent (QMouseEvent*) override;
    void mousePressEvent (QMouseEvent*) override;
    void paintEvent (QPaintEvent*) override;

signals:
    void statusEvent(const QString&);

protected:
    QImage image_;
    QVector<QPointF> pxAxisPoints_;
    float scaleFactor_ = 1.f;
    bool displayAxis_ = true;
    bool pickMode_ = false;

    GraphDigitizer& model_;
};

