#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include "Utils.h"

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

private slots:
    void on_productBtn_clicked();

private:
    Ui::Form2 *ui;

    SDL_mutex *mMutex = nullptr;
    SDL_cond *mCond = nullptr;

    std::list<QString> *mList = nullptr;
    int mIndex = 0;
};

#endif // Form2_H
