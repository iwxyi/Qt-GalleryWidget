#include "galleryphotowidget.h"

GalleryPhotoWidget::GalleryPhotoWidget(QWidget *parent) : QWidget(parent)
{
    pixmap_label = title_label = subTitle_label = nullptr;
}

GalleryPhotoWidget::GalleryPhotoWidget(GalleryPhotoData data, QWidget *parent) : QWidget(parent)
{
    this->pixmap = data.pixmap;
    this->title = data.title;
    this->subTitle = data.subTitle;

    pixmap_label = new QLabel("", this);
    pixmap_label->setPixmap(pixmap);
    title_label = new QLabel(title, this);
    subTitle_label = new QLabel(subTitle, this);
    updateWidgetsPosition();
}

void GalleryPhotoWidget::updateWidgetsPosition()
{

}

void GalleryPhotoWidget::paintEvent(QPaintEvent *event)
{


    QWidget::paintEvent(event);
}
