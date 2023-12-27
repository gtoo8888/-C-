#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);

    //构造函数 参数1 正常显示的图片路径 参数2 按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg="");

    //成员属性保存用户传入的默认显示路径以及按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    void zoom_up();
    void zoom_down();

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:

};

#endif // MYPUSHBUTTON_H
