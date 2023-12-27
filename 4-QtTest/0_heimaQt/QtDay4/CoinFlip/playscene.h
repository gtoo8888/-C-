#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include "mycoin.h"
class playscene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit playscene(QWidget *parent = nullptr);

    playscene(int levelNum);

    void paintEvent(QPaintEvent *);//重写绘图事件

    int levelindex;

    int gameArray[4][4];//二维数组维护每个关卡的 具体数据

    MyCoin* coinBtn[4][4];

    bool isWin; // 是否胜利的标志
signals:
    void playsceneBack();

};

#endif // PLAYSCENE_H
