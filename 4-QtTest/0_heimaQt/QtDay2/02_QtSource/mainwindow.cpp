#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionNew->setIcon(QIcon("C:/Users/HP/Desktop/tool/qttest/qt2/02_QtSource/Image/Luffy.png"));

    //使用Qt资源  " : + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionOpen->setIcon(QIcon(":/Image/butterfly.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
