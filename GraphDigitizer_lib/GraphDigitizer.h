#pragma once

#include <vector>
#include <boost/geometry.hpp>

#include <QtCore/QPointF>
#include <QtGUI/QList>
#include <QtGUI/QTransform>

typedef boost::geometry::model::point<float, 2, boost::geometry::cs::cartesian> point2d;

class GraphDigitizer
{
public:
    GraphDigitizer ();
    ~GraphDigitizer ();

    QList<QPointF> getXYPixelCoords () const;
    QList<QPointF> getXYWorldCoords () const;
    inline const QTransform& getTransform () const { return transform_; };
    void addPoint(const QPointF&);

    void setPxAxisCoords (const QVector<QPointF>&);
    void setTransform();

    inline float getX1Axis() const { return x1WorldAxis_; };
    inline float getX2Axis() const { return x2WorldAxis_; };
    inline float getY1Axis() const { return y1WorldAxis_; };
    inline float getY2Axis() const { return y2WorldAxis_; };

    inline void setX1Axis(const float& x) { x1WorldAxis_ = x; };
    inline void setX2Axis(const float& x) { x2WorldAxis_ = x; };
    inline void setY1Axis(const float& x) { y1WorldAxis_ = x; };
    inline void setY2Axis(const float& x) { y2WorldAxis_ = x; };

private:
    std::list<point2d> pxPickedPoints_;
    std::vector<point2d> pxAxisCoords_;

    float x1WorldAxis_;
    float x2WorldAxis_;
    float y1WorldAxis_;
    float y2WorldAxis_;
    QTransform transform_;
};

