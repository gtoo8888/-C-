#include "Form1.h"
#include "ui_Form1.h"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);

    mMutex = SDL_CreateMutex(); // 创建互斥锁
    mCond = SDL_CreateCond();   // 创建条件变量

    mList = new std::list<QString>();
    std::thread([this](){
        SDL_LockMutex(mMutex);

        while(true){
            qDebug() << "消费者拿到锁";
            while(!mList->empty()){
                qDebug() << mList->front();
                mList->pop_front();
            }
            // 链表是空的，进入等待
            // 1.释放互斥锁
            // 2.等待条件mCond
            // 3.等到了条件mCond,加锁
            qDebug() << "消费者进入等待";
            SDL_CondWait(mCond,mMutex);
        }
        SDL_UnlockMutex(mMutex);
    }).detach();

}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_productBtn_clicked()
{
    SDL_LockMutex(mMutex);
    mList->push_back(QString("%1").arg(++mIndex));
    SDL_CondSignal(mCond);      // 唤醒条件变量
//    SDL_CondBroadcast(mCond); // 广播，唤起所有等待的线程，会把所有条件信号都唤醒
    SDL_UnlockMutex(mMutex); // 这种情况下，可以先解锁再发送信号，但是需要注意，一旦解锁了，锁被其他低优先级的进程抢占的情况

}
