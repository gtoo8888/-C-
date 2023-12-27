#include "widget.h"
#include "ui_widget.h"

//绘图设备是指继承QPainterDevice,的子类。一共提供了四个这样的类，分别是QPixmap、QBitmap、QImage、QPictuxe
//QPixmap,专门为图像在屏幕上的显示做了优化
//QBitmap,是QRixmap,的一个子类，它的色深限定为1，可以使用QPixmap,的isQBitmap()函数来确定这个QPixmap,是不是一个QBitmap
//QImage,专门为图像的像素级访问做了优化。
//QPicture,则可以记录和重现QPicture的各条命令


#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    // Pixmap绘图设备专门为平台做了显示的优化
//    QPixmap pix(300,300);

//    //填充颜色
//    pix.fill(Qt::white);

//    // 声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    // 保存
//    pix.save("./pix.png");


//    //QImage绘图设备可以对像素进行访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    img.save("./img.png");

    //QPicture绘图设备, 可以记录和重新绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);    //开始往pic上画
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,100),100,100);
    painter.end();//结束画画

    //保存到磁盘,文件名任意指定
    pic.save("./pic.zt");
}

//绘图事件
void Widget::paintEvent(QPaintEvent *){
//    QPainter painter(this);
//    //利用QImage对像素进行修改
//    QImage img;
//    img.load(":/Image/Luffy.png");
//    //修改像素点
//    for(int i = 50;i < 100;i++){
//        for(int j = 50;j <100;j++){
//            QRgb value = qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }
//    painter.drawImage(0,0,img);

    QPainter painter(this);
    //重现Picture的绘图指令
    QPicture pic;
    pic.load("./pic.zt");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}








