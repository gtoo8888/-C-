#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include "Utils.h"

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();

private slots:
    void on_productBtn_clicked();

private:
    Ui::Form1 *ui;

    SDL_mutex *mMutex = nullptr;
    SDL_cond *mCond = nullptr;

    std::list<QString> *mList = nullptr;
    int mIndex = 0;
};

#endif // FORM1_H
