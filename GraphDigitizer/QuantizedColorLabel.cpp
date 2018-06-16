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
    // TODO: Preview Data
    QLabel::mouseMoveEvent(event);
}

void QuantizedColorLabel::mousePressEvent(QMouseEvent* event)
{
    // TODO: Set data based on the color(s) selected
    QLabel::mousePressEvent(event);
}


void QuantizedColorLabel::paintEvent(QPaintEvent* paintEvent)
{
    QLabel::paintEvent(paintEvent);

    const int nrColors = quantizedColors_.size();
    if (nrColors == 0)
        return;

    QPainter painter(this);
    const int matrix_dim = ceil(sqrt(nrColors));

    // calculate side of each color square
    const QSize& paintAreaSize = sizeHint();
    const float height = paintAreaSize.height() / (float)matrix_dim;
    const float width = paintAreaSize.width() / (float)matrix_dim;

    for (int idx = 0; idx < nrColors; idx++)
    {
        div_t divresult = div(idx, matrix_dim);
        QRectF rect(width*divresult.rem, height*divresult.quot, width, height);
        painter.fillRect(rect, quantizedColors_[idx]);
    }
}
