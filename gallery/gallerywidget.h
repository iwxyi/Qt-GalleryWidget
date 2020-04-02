#ifndef GALLERYWIDGET_H
#define GALLERYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include "galleryphotowidget.h"

class GalleryWidget : public QWidget
{
    Q_OBJECT
public:
    GalleryWidget(QWidget *parent = nullptr);

    void loadData(QList<GalleryPhotoData> list);
    void startAnimation();

signals:
    void signalPictureClicked(GalleryPhotoWidget* bean);

public slots:

private:
    QList<GalleryPhotoWidget*> widgets;
};

#endif // GALLERYWIDGET_H
