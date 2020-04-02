#ifndef GALLERYPHOTOWIDGET_H
#define GALLERYPHOTOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "waterzoombutton.h"

struct GalleryPhotoData
{
    QPixmap pixmap;
    QString title;
    QString subTitle;
};

class RoundCornerWidget : public QWidget
{
public:
    RoundCornerWidget(QPixmap pixmap, int radius, QWidget* parent = nullptr)
        : QWidget(parent), pixmap(pixmap), radius(radius)
    {
    }

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QPainterPath path;
        path.addRoundedRect(QRect(0,0,width(),height()),radius,radius);
        painter.setClipPath(path, Qt::IntersectClip);
        painter.drawPixmap(QRect(0,0,width(), height()), pixmap);
    }

private:
    QPixmap pixmap;
    int radius;
};

class GalleryPhotoWidget : public WaterZoomButton
{
    Q_OBJECT
public:
    GalleryPhotoWidget(GalleryPhotoData data, QWidget* parent = nullptr);

public:
    static int fixed_width, fixed_height;
    static int content_width, content_height;
    static int pixmap_width, pixmap_height;
    static QColor title_color;
    static QColor subTitle_color;

private:
    QVBoxLayout* main_vlayout;
    RoundCornerWidget* rc_widget;
    QLabel *title_label, *subTitle_label;
};

#endif // GALLERYPHOTOWIDGET_H
