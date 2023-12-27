#ifndef CHOOSELEVESCANE_H
#define CHOOSELEVESCANE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include "playscene.h"


class ChooseLeveScane : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLeveScane(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);//重写绘图事件

    playscene* play = NULL;

signals:
    void chooseSecneBack();//写一个自定义信号，告诉主场景点击了返回
};

#endif // CHOOSELEVESCANE_H
