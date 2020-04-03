#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interactivebuttonbase.h"

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
    srand(time(0));
    int count = rand() % 10 + 5;
    for (int i = 0; i < count; i++)
    {
        QPixmap pixmap(":/pictures/picture");
        QString title = "凤翎谱" + QString::number(i);
        QString subTitle = "作者：北宫懒懒" + QString::number(i);
        GalleryPhotoData data{pixmap, title, subTitle};
        list.append(data);
    }
    ui->widget->loadData(list);
}
