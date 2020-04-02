#include "galleryphotowidget.h"

int GalleryPhotoWidget::fixed_width = 100;
int GalleryPhotoWidget::fixed_height = 200;
int GalleryPhotoWidget::pixmap_width = 100;
int GalleryPhotoWidget::pixmap_height = 150;
QColor GalleryPhotoWidget::title_color = Qt::black;
QColor GalleryPhotoWidget::subTitle_color = Qt::gray;

GalleryPhotoWidget::GalleryPhotoWidget(GalleryPhotoData data, QWidget *parent) : QWidget(parent)
{
    main_vlayout = new QVBoxLayout(this);
    pixmap_label = new QLabel("", this);
    title_label = new QLabel(data.title, this);
    subTitle_label = new QLabel(data.subTitle, this);

    main_vlayout->addWidget(pixmap_label);
    main_vlayout->addWidget(title_label);
    main_vlayout->addWidget(subTitle_label);

    pixmap_label->setPixmap(data.pixmap);
    pixmap_label->setScaledContents(true);
    pixmap_label->setFixedSize(pixmap_width, pixmap_height);

    setFixedSize(fixed_width, fixed_height);

    this->show();
}

void GalleryPhotoWidget::paintEvent(QPaintEvent *event)
{


    QWidget::paintEvent(event);
}
