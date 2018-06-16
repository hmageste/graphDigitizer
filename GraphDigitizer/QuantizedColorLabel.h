#pragma once

#include <QImage>
#include <QLabel>


class QuantizedColorLabel : public QLabel
{
    Q_OBJECT
public:
    QuantizedColorLabel(QWidget *parent = Q_NULLPTR);
    virtual ~QuantizedColorLabel();

    inline const QPixmap& image() const { return pixmap_; };

    void setImage(const QImage& image);
    void setImage(const QPixmap& pixmap);
    void setColors(const QVector<QColor>&);
protected:
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;

protected:
    QPixmap pixmap_;
    QVector<QColor> quantizedColors_;
};
