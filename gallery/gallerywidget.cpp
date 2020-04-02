#include "gallerywidget.h"

GalleryWidget::GalleryWidget(QWidget *parent) : QWidget(parent)
{

}

/**
 * 加载数据，初始化列表
 * 并且开启显示动画
 */
void GalleryWidget::loadData(QList<GalleryPhotoData> list)
{
    foreach (GalleryPhotoWidget* widget, widgets) {
        widget->deleteLater();
    }
    widgets.clear();

    foreach (GalleryPhotoData data, list)
    {
        widgets.append(new GalleryPhotoWidget(data, this));
    }
    startAnimation();
}

/**
 * 列表出现动画
 */
void GalleryWidget::startAnimation()
{

}
