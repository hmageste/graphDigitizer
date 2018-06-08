#include "GraphDigitizer.h"

#include <iostream>

namespace bg = boost::geometry;
constexpr std::size_t operator "" _sz (unsigned long long n)
{
    return n;
}

GraphDigitizer::GraphDigitizer ()
    : pxAxisCoords_(4)
{}


GraphDigitizer::~GraphDigitizer ()
{}


QList<QPointF> GraphDigitizer::getXYPixelCoords () const
{
    QList<QPointF> pointList;
    for (point2d pxPoint : pxPickedPoints_)
        pointList.push_back (QPointF(pxPoint.get<0>(), pxPoint.get<1>()));

    return pointList;
}


QList<QPointF> GraphDigitizer::getXYWorldCoords () const
{
    QList<QPointF> pointList;
    for (point2d pxPoint : pxPickedPoints_)
    {
        QPointF point(pxPoint.get<0>(), pxPoint.get<1>());
        pointList.push_back(transform_.map(point));
    }

    return pointList;
}


void GraphDigitizer::setPxAxisCoords (const QVector<QPointF>& pxAxisCoords)
{
    if (pxAxisCoords.size () != 4)
    {
        std::cerr << "Wrong list size! Size must be equal to 4!" << std::endl;
        return;
    }

    for (size_t idx = 0; idx < std::size_t{4}; ++idx)
    {
        const float& x = pxAxisCoords[idx].x();
        const float& y = pxAxisCoords[idx].y();
        pxAxisCoords_[idx] = bg::make<point2d>(x, y);
        //boost::geometry::assign_values(pnt, 0.0, 0.0);
    }
}

void GraphDigitizer::setTransform()
{
    const point2d x1Px = pxAxisCoords_[0];
    const point2d x2Px = pxAxisCoords_[1];
    const point2d y1Px = pxAxisCoords_[2];
    const point2d y2Px = pxAxisCoords_[3];

    const float xScale = (x2WorldAxis_ - x1WorldAxis_) / (x2Px.get<0>() - x1Px.get<0>());
    const float yScale = (y2WorldAxis_ - y1WorldAxis_) / (y2Px.get<1>() - y1Px.get<1>());
    const float dx = x1WorldAxis_ - xScale * x1Px.get<0>();
    const float dy = y1WorldAxis_ - yScale * y1Px.get<1>();

    transform_.setMatrix (xScale, 0, 0, 0, yScale, 0, dx, dy, 1);

    //transform_.scale(xScale, yScale);
    //transform_.translate(dx, dy);
}


void GraphDigitizer::addPoint(const QPointF& point)
{
    pxPickedPoints_.push_back(bg::make<point2d>(point.x(), point.y()));
}
