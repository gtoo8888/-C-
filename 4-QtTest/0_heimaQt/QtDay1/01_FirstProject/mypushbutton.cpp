#include "mypushbutton.h"
#include <QDebug>//QT中用来显示信息


myPushButton::myPushButton(QWidget *parent) :QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用" ; //<< endl;不需要，自己会换行
}



myPushButton::~myPushButton(){
    qDebug() << "我的按钮类析构调用";
}
