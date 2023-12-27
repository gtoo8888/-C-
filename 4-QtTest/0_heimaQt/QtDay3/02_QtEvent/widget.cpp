#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    id1 = startTimer(1000);//参数1 间隔 单位 毫秒

    id2 = startTimer(2000);

    //定时器第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        //label4每隔0.5秒+1
        ui->label_4->setText(QString::number(num++));
    });

    //点击暂停按钮实现停止定时器
    connect(ui->btn,&QPushButton::clicked,[=](){
        timer->stop();
    });

    //给label1安装事件过滤器
    //步骤1安装事件过滤器
    ui->label->installEventFilter(this);
}

//步骤2 重写eventfilter事件
bool Widget::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->label){
        if(e->type() == QEvent::MouseButtonPress){
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);
            QString str = QString( "事件过滤器函数中：鼠标移动了 x=%1 y=%2 globalX=%3 Y=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;

            return true;//true代表用户自己处理这个
        }
    }

    //其他默认处理
    return QWidget::eventFilter(obj,e);
}

void Widget::timerEvent(QTimerEvent *ev){
    if(ev->timerId() == id1){
        static int num1 = 1;
        // label2 每隔1秒+1
        ui->label_2->setText(QString::number(num1++));
    }

    if(ev->timerId() == id2){
        static int num2 = 1;
        // label3每隔2秒+1
        ui->label_3->setText(QString::number(num2++));
    }
}

Widget::~Widget()
{
    delete ui;
}
