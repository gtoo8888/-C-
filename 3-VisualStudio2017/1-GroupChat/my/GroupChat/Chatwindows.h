#ifndef CHATWINDOWS_H
#define CHATWINDOWS_H

#include <QWidget>
#include <QUdpSocket>
namespace Ui {
class ChatWindows;
}

class ChatWindows : public QWidget
{
    Q_OBJECT

public:
    enum MsgType{
        Msg, // 普通信息
        UserEnter, // 用户进入
        UserLeft // 用户离开
    };
    explicit ChatWindows(QWidget *parent = nullptr,QString userName = QString(""));
    void closeEvent(QCloseEvent *event);
    ~ChatWindows();
    void initUi(void);
    void initConnect(void);
    void sendMsg(MsgType type); //广播udp信息
    void closeWnd(void);
    void userEnterAction(QString username);//处理用户进入
    void userLeftAction(QString username,QString time);//处理用户离开
    QString getMsg(void);//获取聊天信息,html格式

signals:
    void sigCloseChatWnd(void);

public slots:
    void slotReceiveMsg(void);
    void slotSendMsg(void);
    void slotExitWnd(void);

    void slotSetFontType(const QFont &font);
    void slotSetFontSize(const QString &text);
    void slotSetFontBold(bool checked);
    void slotSetFontItalic(bool checked);
    void slotSetFontUnderLine(bool checked);
    void slotSetFontColor(void);
    void slotSetTextSave(void);
    void slotSetFontClear(void);

private:
    Ui::ChatWindows *ui;
    QString mChatUserName;
    uint64_t mPort;
    QUdpSocket *mpUdpSocket = nullptr;
};

#endif // CHATWINDOWS_H
