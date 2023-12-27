#include "mycoin.h"
#include <QPixmap>
#include <QDebug>
//MyCoin::MyCoin(QWidget *parent) : QWidget(parent)
//{

//}


MyCoin::MyCoin(QString btnImg){
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
    this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
    this->setIcon(pix);//设置图标
    this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    //监听正面翻反面的信号，并且翻转金币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
        this->setIcon(pix);//设置图标
        this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小
        //判断如果翻完了，将min重置为1
        if(this->min > this->max){
            this->min = 1;
            this->isAnimation = false;// 动画结束了
            timer1->stop();
        }
    });

    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        this->setStyleSheet("QPushButton{border:0px}");//设置不规则图片样式,去掉图片边框
        this->setIcon(pix);//设置图标
        this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小

        if(this->max < this->min){
            this->max = 8;
            this->isAnimation = false;  // 动画结束了
            timer2->stop();
        }
    });
}

void MyCoin::mousePressEvent(QMouseEvent *e){
    // 如果胜利了，要屏蔽用户继续操作，也不做任何动作
    // 禁止按钮，有的时候禁止所有按钮按下
    if(this->isAnimation | this->isWin | this->isFobiden){  // 如果正在执行动画，就直接返回
        return;
    }else{  // 如果动画执行完了，就把消息传递下去，继续执行动画
        QPushButton::mousePressEvent(e);
    }
}

void MyCoin::changeFlag(){
    if(this->flag){
        timer1->start(30);
        this->isAnimation = true;   // 可以开始动画了
        this->flag = false;
    }else{
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}








