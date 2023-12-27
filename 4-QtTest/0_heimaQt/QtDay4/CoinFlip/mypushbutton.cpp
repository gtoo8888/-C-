#include "mypushbutton.h"

#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug() << "图片加载失败";
        return;
    }

    this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
    this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
    this->setIcon(pix);//设置图标
    this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小
}

void MyPushButton::zoom_up(){
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");//创建动画对象
    animation->setDuration(200);//设置动画时间间隔
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//创建起始位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//创建结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce); //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->start();//开始执行动画
}

void MyPushButton::zoom_down(){
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");//创建动画对象
    animation->setDuration(200);//设置动画时间间隔
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//创建起始位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));//创建结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce); //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->start();//开始执行动画
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(this->pressImgPath != ""){   // 通过第二个参数来判断是不是有特殊的执行
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret){
            qDebug() << "mousePressEvent图片加载失败";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
        this->setIcon(pix);//设置图标
        this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小
    }
    return QPushButton::mousePressEvent(e); // 一定要将这个返回，不然按下没有反应
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret){
            qDebug() << "mouseReleaseEvent图片加载失败";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
        this->setIcon(pix);//设置图标
        this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小
    }
    return QPushButton::mouseReleaseEvent(e);
}

