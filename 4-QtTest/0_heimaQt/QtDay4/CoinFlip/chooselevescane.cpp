#include "chooselevescane.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QLabel>
#include <QSound>
ChooseLeveScane::ChooseLeveScane(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);//设置固定大小
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));//设置应用图片
    this->setWindowTitle("选择关卡场景");//设置窗口标题

    QMenuBar *bar = menuBar();//创建菜单栏
    setMenuBar(bar);

    QMenu *starMenu = bar->addMenu("开始");//创建开始菜单
    QAction *quitstartMenu= starMenu->addAction("退出");//创建按钮菜单项

    connect(quitstartMenu,&QAction::triggered,[=](){ //点击退出 退出游戏
        this->close();
    });

    // 选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    // 返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){//点击返回
        backSound->play();//播放返回按钮音效
        qDebug() << "点击了返回按钮";
        //告诉主场景我返回了，主场景监听chooseLevelscene的返回按钮
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSecneBack();
        });
    });


    // 创建选择关卡的按钮
    for(int i = 0;i < 20;i++){
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70, 130+i/4*70);

        // 监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            chooseSound->play();//播放选择关卡音效
            this->hide();//将选关场景隐藏掉
            play = new playscene(i+1);//创建游戏场景

            //设置play场景的位置
            play->setGeometry(this->geometry());
            play->show();//显示游戏场景



            connect(play,&playscene::playsceneBack,[=](){
                this->setGeometry(play->geometry());    // 回来的时候还是老位置
                this->show();
                delete play;        // 每次都开一个新的场景就行，所以就直接删掉了
                play = NULL;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70, 130+i/4*70);

        // 设置labe1上的文字对齐方式水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 设置让鼠标进行穿透        51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChooseLeveScane::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png"); //加载标题
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
