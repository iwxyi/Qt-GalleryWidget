#include "galleryphotowidget.h"

int GalleryPhotoWidget::fixed_width = 140;
int GalleryPhotoWidget::fixed_height = 240;
int GalleryPhotoWidget::content_width = 100;
int GalleryPhotoWidget::content_height = 200;
int GalleryPhotoWidget::pixmap_width = 100;
int GalleryPhotoWidget::pixmap_height = 150;
QColor GalleryPhotoWidget::title_color = Qt::black;
QColor GalleryPhotoWidget::subTitle_color = Qt::gray;

GalleryPhotoWidget::GalleryPhotoWidget(GalleryPhotoData data, QWidget *parent) : WaterZoomButton("", parent)
{
    setObjectName("GalleryPhotoWidget");
    setNormalColor(Qt::white);
    setHoverColor(Qt::white);
    setChoking(10);
    setRadius(5, 10);

    this->pixmap = data.pixmap;
    this->title = data.title;
    this->subTitle = data.subTitle;

    setFixedSize(fixed_width, fixed_height);
    pixmap.scaled(pixmap_width, pixmap_height);

    this->show();
}

void GalleryPhotoWidget::paintEvent(QPaintEvent *event)
{
    WaterZoomButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath path;

    // 获取图片路径
    int c;
    int r;
    if (!hover_progress)
    {
        c = choking;
        r = radius_x;
    }
    else
    {
        c = choking * (1 - getNolinearProg(hover_progress, hovering?FastSlower:SlowFaster));
        r = radius_zoom < 0 ? radius_x :
                              radius_x + (radius_zoom-radius_x) * hover_progress / 100;
    }
    const int margin = 10;

    path.addRoundedRect(QRect(c+margin,c+margin,size().width()-c*2-margin*2,(size().width()-c*2-margin*2)*pixmap_height/pixmap_width), r, r);
    painter.setClipPath(path, Qt::IntersectClip);
    painter.drawPixmap(QRect(0,0,width(), height()), pixmap);

    // 画文字
}
