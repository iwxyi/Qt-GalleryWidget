#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initData()
{
    QList<GalleryPhotoData> list;
    for (int i = 0; i < 7; i++)
    {
        QPixmap pixmap(":/pictures/a");
        QString title = "Title" + QString::number(i);
        QString subTitle = "SubTitle" + QString::number(i);
        GalleryPhotoData data{pixmap, title, subTitle};
        list.append(data);
    }

}
