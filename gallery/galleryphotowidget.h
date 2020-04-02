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
    QLabel* pixmap_label, *title_label, *subTitle_label;
};

#endif // GALLERYPHOTOWIDGET_H
