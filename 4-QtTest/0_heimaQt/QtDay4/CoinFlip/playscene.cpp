#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>
#include <QPropertyAnimation>

#include "dataconfig.h"

//playscene::playscene(QWidget *parent) : QMainWindow(parent)
//{

//}

playscene::playscene(int levelNum){
    QString str = QString("您选择的是%1关").arg(levelNum);
    qDebug() << str;
    this->levelindex = levelNum;


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

    // 返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);
    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);


    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){//点击返回
        backSound->play();//播放返回按钮音效
        qDebug() << "翻金币场景中，点击了返回按钮";
        QTimer::singleShot(500,this,[=](){
            emit this->playsceneBack();
        });
    });

    //显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelindex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30,this->height() - 50,120,50);

    //初始化每个关卡的二维数组
    dataConfig config;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            this->gameArray[i][j] = config.mData[this->levelindex][i][j];
        }
    }


    QLabel *winlabel = new QLabel;
    QPixmap tmppix;
    tmppix.load(":/res/LevelCompletedDialogBg.png");
    winlabel->setGeometry(0,0,tmppix.width(),tmppix.height());
    winlabel->setPixmap(tmppix);
    winlabel->setParent(this);
    winlabel->move((this->width()-tmppix.width())*0.5,-tmppix.height());    // 先加载好，藏在界面上面

    //显示金币背景图案
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            //绘制背景图片
            QLabel *label = new QLabel;
            label->setParent(this);
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->move(57+i*50,200+j*50);

            // 创建金币
            QString str;
            if(gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            }else{
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);

            //给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];//1正面0反面

            //将金币放入到金币的二维教组里,以便以后期的维护
            coinBtn[i][j] = coin;

            //点击金币 进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                flipSound->play();//翻金币音效

                // 游戏开始禁止所有按钮按下，防止有人手快连续点两个
                for(int i = 0;i < 4;i++){
                    for(int j = 0;j < 4;j++){
                        this->coinBtn[i][j]->isFobiden = true;
                    }
                }


                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j]== 0 ? 1 : 0;

                //翻转周围硬币
                QTimer::singleShot(100,this,[=](){  // 提供一个翻转延时
                    if(coin->posX + 1 <= 3){//周围的右侧金币翻转的条件
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posX - 1 >= 0){//周围的左侧金币翻转的条件
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posY + 1 <= 3){//周围的上侧金币翻转的条件
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                    }
                    if(coin->posY - 1 >= 0){//周围的下侧金币翻转的条件
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                    }

                    // 判断胜利的时候解开按钮禁止
                    for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++){
                            this->coinBtn[i][j]->isFobiden = false;
                        }
                    }


                    //判断是否胜利
                    this->isWin = true;
                    for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++){
                            if(coinBtn[i][j]->flag == false){//只要有一个是反面，那就算失败
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true){
                        winSound->play();//胜利音效
                        qDebug() << "游戏胜利";
                        for(int i = 0;i < 4;i++){//将所有按钮的胜利标志改为true;如果再次点击按钮，直接return，不做响应
                            for(int j = 0;j < 4;j++){
                                coinBtn[i][j]->isWin = true;
                            }
                        }

                        QPropertyAnimation *animation = new QPropertyAnimation(winlabel,"geometry");
                        animation->setDuration(1000);//设置时间间隔
                        animation->setStartValue(QRect(winlabel->x(),winlabel->y(),winlabel->width(),winlabel->height()));//设置开始位置
                        animation->setEndValue(QRect(winlabel->x(),winlabel->y()+130,winlabel->width(),winlabel->height()));//设置结束位置
                        animation->setEasingCurve(QEasingCurve::OutBounce);//设置缓和曲线
                        animation->start();//执行动画

                    }

                });
            });
        }
    }
}


void playscene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png"); //加载标题
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}


