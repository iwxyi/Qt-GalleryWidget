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

    main_vlayout = new QVBoxLayout(this);
    pixmap_label = new QLabel("", this);
    title_label = new QLabel(data.title, this);
    subTitle_label = new QLabel(data.subTitle, this);

    main_vlayout->addWidget(pixmap_label);
    main_vlayout->addWidget(title_label);
    main_vlayout->addWidget(subTitle_label);
    main_vlayout->setMargin(19);

    pixmap_label->setPixmap(data.pixmap);
    pixmap_label->setScaledContents(true);
    pixmap_label->setFixedSize(pixmap_width, pixmap_height);

    QPalette pa(title_label->palette());
    pa.setColor(QPalette::WindowText, title_color);
    title_label->setPalette(pa);

    pa = subTitle_label->palette();
    pa.setColor(QPalette::WindowText, subTitle_color);
    subTitle_label->setPalette(pa);

    setFixedSize(fixed_width, fixed_height);

    this->show();
}
