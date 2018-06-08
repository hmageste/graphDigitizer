#include "ImageLabel.h"

#include "GraphDigitizer.h"

#include <algorithm>

#include <QPixmap>
#include <QtWidgets>


ImageLabel::ImageLabel (QWidget* parent)
    : QLabel(parent)
    , model_(*new GraphDigitizer)
{
    setBackgroundRole (QPalette::Base);
}


ImageLabel::~ImageLabel ()
{
    delete &model_;
}


void ImageLabel::clearAxisPoints()
{
    pxAxisPoints_.clear();
    QVector<QPointF>().swap(pxAxisPoints_);
    Q_ASSERT(pxAxisPoints_.capacity() == 0);
    update();
}


void ImageLabel::displayAxis(bool yn)
{
    displayAxis_ = yn;
    update();
}


void ImageLabel::pickMode(bool yn)
{
    pickMode_ = yn;
    update();
}


void ImageLabel::setImage(const QImage& newImage)
{
    image_ = newImage;
    setPixmap(QPixmap::fromImage(image_));
    scaleFactor_ = 1.0;
}


float ImageLabel::scaleImage(float factor)
{
    scaleFactor_ *= factor;
    resize(scaleFactor_ * pixmap()->size());

    std::transform(pxAxisPoints_.begin(), pxAxisPoints_.end(), pxAxisPoints_.begin(),
                   [factor](QPointF d) -> QPointF { return d * factor; });

    return scaleFactor_;
}


void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    QLabel::mouseMoveEvent(event);

    QPointF mousePos = event->localPos();

    QString mousePosStr = QString("Px: (%1, %2)").arg(mousePos.x()).arg(mousePos.y());
    mousePosStr += "  \t";

    QPointF mousePosTransf = model_.getTransform().map(event->localPos());
    mousePosStr += QString("World: (%1, %2)").arg(mousePosTransf.x()).arg(mousePosTransf.y());
    emit statusEvent(mousePosStr);
}

void ImageLabel::mousePressEvent (QMouseEvent* event)
{
    QLabel::mousePressEvent(event);

    if (pxAxisPoints_.size () < 4)
    {
        pxAxisPoints_.push_back (event->pos());
        update ();
    }

    if (pickMode_)
    {
        model_.addPoint (event->pos());
        update();
    }
}


void ImageLabel::paintEvent (QPaintEvent* paintEvent)
{
    QLabel::paintEvent (paintEvent);

    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter.setPen(pen);
    if (displayAxis_)
    {
        painter.drawPoints(pxAxisPoints_);
        for (size_t idx = 0; idx < pxAxisPoints_.size (); ++idx)
        {
            QString text = (idx < 2 ? "X" + QString::number(idx) : "Y" + QString::number (idx-2));
            painter.drawText (pxAxisPoints_[idx], text);
        }
    }

    pen.setColor(Qt::green);
    painter.setPen(pen);
    if (pickMode_)
    {
        for (const QPointF& qpoint : model_.getXYPixelCoords())
            painter.drawPoint(qpoint);
    }
}
