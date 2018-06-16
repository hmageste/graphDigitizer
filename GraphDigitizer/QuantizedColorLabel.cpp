#include "QuantizedColorLabel.h"

#include <QPixmap>
#include <QtWidgets>



QuantizedColorLabel::QuantizedColorLabel(QWidget* parent)
    : QLabel(parent)
    , pixmap_(sizeHint())
{
    setBackgroundRole(QPalette::Base);
    pixmap_.fill();
    setPixmap(pixmap_);
}


QuantizedColorLabel::~QuantizedColorLabel() {}


void QuantizedColorLabel::setImage(const QImage& image)
{
    pixmap_ = QPixmap::fromImage(image);
    setPixmap(pixmap_);
}


void QuantizedColorLabel::setImage(const QPixmap& pixmap)
{
    pixmap_ = pixmap;
    setPixmap(pixmap_);
}


void QuantizedColorLabel::setColors(const QVector<QColor>& colors)
{
    quantizedColors_ = colors;
    update();
}


void QuantizedColorLabel::mouseMoveEvent(QMouseEvent* event)
{
    QLabel::mouseMoveEvent(event);
}

void QuantizedColorLabel::mousePressEvent(QMouseEvent* event)
{
    QLabel::mousePressEvent(event);
}


void QuantizedColorLabel::paintEvent(QPaintEvent* paintEvent)
{
    QLabel::paintEvent(paintEvent);

    QPainter painter(this);

    if (quantizedColors_.size() == 0)
        return;

    int nrColors = quantizedColors_.size();
    int matrix_dim = ceil(sqrt(nrColors));

    // calculate side of each color square
    const QSize& paintAreaSize = sizeHint();
    const float height = paintAreaSize.height() / matrix_dim;
    const float width = paintAreaSize.width() / matrix_dim;

    for (int idy = 0; idy < matrix_dim; ++idy)
        for (int idx = 0; idx < matrix_dim; ++idx)
        {
            if (idy*matrix_dim + idx == nrColors)
                return;
            QRectF rect(width*idx, height*idy, width, height);
            painter.fillRect(rect, quantizedColors_[idy*matrix_dim + idx]);
        }
}
