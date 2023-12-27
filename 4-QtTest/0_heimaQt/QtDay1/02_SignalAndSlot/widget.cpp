#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

// Teacher类老师类
// Student类学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    this -> zt = new Teacher(this);//创建一个老师对象
    this -> st = new Student(this);//创建一个学生对象

//    connect(zt,&Teacher::hungry,st,&Student::treat);//老师饿了学生请客的连接
//    //先做好连接，再触发下课函数
//    classisover();//调用下课函数


    //连接带参数的信号和槽
    //指针->地址
    //函数指针->函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;//函数指针
    void(Student:: *studentSignal)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,studentSignal);
    classisover();

    //点击一个下课的按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);
    this -> resize(600,400);//点击一个下课的按钮，再触发下课
//    connect(btn,&QPushButton::clicked,this,&Widget::classisover);//点击按钮触发下课

    //无参信号和槽连接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSignal2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSignal2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);

    //断开信号
    disconnect(zt,teacherSignal2,st,studentSignal2);

    //拓展
    // 1、信号是可以连接信号
    // 2、一个信号可以连接多个槽函数
    // 3、多个信号可以连接同一个槽函数
    // 4、信号和槽函数的参数必须类型―—对应
    // 5、信号和槽的参数个数﹑是不是要一致﹖信号的参数个数可以多余槽函数的参数个数
    // Qt4版本以前的信号和槽连接方式
    // 利用qt4信号槽连接无参版本
    // Qt4版本底层SIGNAL ( "hungry")SLOT ("treat")
    //connect (zt,SIGNAL(hungry(),st_,SLOT(treat()) );
    // Qt4版本优点:参数直观，缺点:类型不做检测
    // Qt5以上支持Qt4的版本写法，反之不支持

    [=](){
        btn -> setText("aaaa");
    }//上面是函数声明，小括号是函数调用
    ();

//    QPushButton *btn2 = new QPushButton;
//    [btn](){
//        btn -> setText("aaaa");
//        btn2 -> setText("bbbb");//作用域是btn1 btn2看不到
//    }();


//    QPushButton * myBtn = new QPushButton (this);
//    QPushButton * myBtn2 = new QPushButton (this);
//    myBtn2->move(100,100);
//    int m = 10;
//    //connect(myBtn,&QPushButton::clicked,this,[m] ()mutable { m = 100 + 10; qDebug() << m; });
//    //connect(myBtn2,&QPushButton::clicked,this,[=] ()  { qDebug() << m; });
//    qDebug() << m;

//    int ret = []()->{return 1000;}();
//    QDebug() << ret;

}

void Widget::classisover(){
//    emit zt->hungry();//下课函数，调用后触发老师饿了的信号
    //emit触发信号的关键字
    emit zt->hungry("宫保鸡丁");
}



Widget::~Widget()
{
    delete ui;
}

