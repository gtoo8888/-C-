#include "Login.h"
#include "ui_login.h"
#include "ChatWindows.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    initUi();
    initConnect();
}

void Login::initUi(void){
    this->setWindowIcon(QIcon(":/images/qq.png"));
    this->setWindowTitle("QQ 2023");

    for(int i = 0;i < mNameList.size();i++){
        QToolButton *userAvatar = new QToolButton(this);
        QString avatarImgPath = QString(":/images/Avatar/%1.png").arg(mIconNameList[i]);
        QPixmap avatarImg = QPixmap(avatarImgPath);
        userAvatar->setIcon(avatarImg);  //加载图标
        userAvatar->setIconSize(avatarImg.size()); //设置图片大小
        userAvatar->setText(mNameList[i]); //设置为透明
        userAvatar->setAutoRaise(true);
        userAvatar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置显示格式
        ui->vlayout->addWidget(userAvatar); //放到vlayout布局中
        mvUserAvatar.push_back(userAvatar);
        mbShowChatWnd.push_back(false);
    }
}

void Login::initConnect(void){
    for(int i = 0;i < mNameList.size();i++){
        connect(mvUserAvatar[i],&QToolButton::clicked,this,&Login::openChatWnd);
    }
}

void Login::openChatWnd(){
    QToolButton* senderButton = qobject_cast<QToolButton*>(sender()); // 通过sender()函数获取发送信号的对象

    if (senderButton) {
        int idx = -1;
        for (int i = 0; i < mvUserAvatar.size(); ++i) {
            if (senderButton == mvUserAvatar[i]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            qDebug() << QString("userIdx: %1 error").arg(idx);
            return;
        }
        qDebug() << QString("userIdx: %1, userName: %2").arg(idx).arg(mNameList[idx]);

        if(mbShowChatWnd[idx]){
            QMessageBox::warning(this,"警告","该聊天框已被打开!");
            return;
        }

        ChatWindows* chatWnd = new ChatWindows(nullptr,mvUserAvatar[idx]->text());
        chatWnd->setWindowTitle(mvUserAvatar[idx]->text());
        chatWnd->setWindowIcon(mvUserAvatar[idx]->icon());
        mbShowChatWnd[idx] = true;
        chatWnd->show();

        connect(chatWnd,&ChatWindows::sigCloseChatWnd,this,[=](){
            mbShowChatWnd[idx] = false;
        });

    }
}

Login::~Login()
{
    delete ui;
}
