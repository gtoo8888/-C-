#include "mainscane.h"
#include "ui_mainscane.h"
#include "mypushbutton.h"

#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>   // 多媒体模块

MainScane::MainScane(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScane)
{
    ui->setupUi(this);

    setFixedSize(320,588);//设置固定大小
    setWindowIcon(QIcon(":/res/Coin0001.png"));//设置应用图片
    setWindowTitle("翻金币主场景");//设置窗口标题

    //退出按钮实现
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    // 准备开始按钮的音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->play();
//    startSound->setLoops(10);

    //创建开始按钮
    MyPushButton *startBTN = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBTN->setParent(this);
    startBTN->move(this->width()*0.5 - startBTN->width()*0.5,this->height()*0.7);

    chooseScane = new ChooseLeveScane;

    connect(startBTN,&MyPushButton::clicked,[=](){
//        qDebug() << "点击了就开始";
        //播放开始音效资源
        startSound->play();
        //做弹起特效
        startBTN->zoom_up();
        startBTN->zoom_down();

        //监听选择关卡的返回按钮的信号
        connect(chooseScane,&ChooseLeveScane::chooseSecneBack,this,[=](){
           this->setGeometry(chooseScane->geometry());
           chooseScane->hide();//将选择关卡场景隐藏掉
           this->show();//重新显示主场景
        });

//        this->hide();  // 如果直接消失的话，就看不到弹跳的动画了
//        chooseScane->show();
        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){  // 给一个500ms的延时，可以看动画
            //设置choosescene场景的位置
            chooseScane->setGeometry(this->geometry());

            this->hide();   // 自身隐藏
            chooseScane->show();//显示选择关卡场景
        });

    });
}


void MainScane::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //为了让背景能和界面框贴合，需要直接指定图片的长宽和界面的一致
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");
//    pix = pix.scaled(pix.width(),pix.height());// 使用原始图片太大了
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}


MainScane::~MainScane()
{
    delete ui;
}

