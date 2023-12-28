#include "StuManage.h"
#include "ui_StuManage.h"
#include "Utils.h"
#include <QFile>


StuManage::StuManage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUi();
    initConnect();
}

StuManage::~StuManage()
{
    delete ui;
}

void StuManage::initUi(void)
{
    tmpExample = ui->menubar->addMenu("example");
    tmpSimulationData = tmpExample->addAction("模拟数据");
}

void StuManage::initConnect()
{

}

void StuManage::keyPressEvent(QKeyEvent *event)
{
    int keyType = event->key();
    switch(keyType){
    case Qt::Key::Key_F6:
        qDebug() << "F6";
        QFile file;
        file.setFileName("://StuManage.qss");
        file.open(QIODevice::ReadOnly);
        QString strQss = file.readAll();
//        myDebug() << strQss;
//        this->setStyleSheet(strQss);
        break;
    }
}




