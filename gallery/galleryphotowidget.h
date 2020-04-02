#ifndef GALLERYPHOTOWIDGET_H
#define GALLERYPHOTOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>

struct GalleryPhotoData
{
    QPixmap pixmap;
    QString title;
    QString subTitle;
};

class GalleryPhotoWidget : public QWidget
{
    Q_OBJECT
public:
    GalleryPhotoWidget(QWidget *parent = nullptr);
    GalleryPhotoWidget(GalleryPhotoData data, QWidget* parent = nullptr);

    void updateWidgetsPosition();

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    static int fixed_width;
    static int fixed_height;
    static QColor title_color;
    static QColor subTitle_color;

private:
    QPixmap pixmap;
    QString title, subTitle;

    QLabel* pixmap_label, *title_label, *subTitle_label;
};

int GalleryPhotoWidget::fixed_width = 100;
int GalleryPhotoWidget::fixed_height = 150;
QColor GalleryPhotoWidget::title_color = Qt::black;
QColor GalleryPhotoWidget::subTitle_color = Qt::gray;

#endif // GALLERYPHOTOWIDGET_H
