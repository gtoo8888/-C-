#include "mywidget.h"//这是一个窗口文件
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

//命名规范
//类名首字母大写，单词和单词之间首字母大写
//函数名变量名称首字母小写，单词和单词之间首字母大写

//快捷键
//注释ctrl +/
//运行ctrl + r
//编译ctrl + b
//字体缩放ctrl +鼠标滚轮
//查找ctrl + f
//整行移动ctrl + shift +↑或者↓
//自动对齐ctrl + i;
//同名之间的.h和.cpp切换F4

//帮助文档第一种方式 F1 第二种左侧按钮 第三种 c:\gt\gt5.6.0\5.6\mingw49_32\bin
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)//初始化列表
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
//    btn -> show();//show以顶层方式弹出窗口控件
    btn -> setParent(this);//让btn对象依赖在mywidget窗口中
    btn -> setText("第一个按钮");//显示文本

    //创建第二个按钮按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("第二个按钮",this);

    btn2 -> move(100,100);//移动btn2按钮
    btn2 -> resize(50,50);//按钮重新制定大小
    resize(600,400);//重置窗口大小
    setFixedSize(600,400);//设置固定窗口大小
    setWindowTitle("第一个窗口");//设置窗口标题



    //创建一个自己的按钮对象
    myPushButton *myBtn = new myPushButton;
    myBtn ->setText("我自己的按钮");
    myBtn ->move(200,0);
    myBtn ->setParent(this);//设置到对象树中



    //需求 点击我的按钮 关团窗口
    //参数1 信号的发送者 参数2 发送的信号(函数的地址) 参数3 信号的接受者 参数4 处理的槽函数
    connect(myBtn,&myPushButton::clicked,this,&myWidget::close);
//    connect(myBtn,&QPushButton::clicked,this,&QWidget::close);//用父类实现


}

myWidget::~myWidget()
{
    qDebug() << "myWidget析构函数的调用" ;
}
