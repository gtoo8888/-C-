#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QToolButton>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void initUi(void);
    void initConnect(void);

public slots:
    void openChatWnd();

private:
    Ui::Login *ui;
    QVector<QString> mNameList = {"性感小飞侠","闷骚男","韩国欧巴","神经病一枚","笨笨猪","狗头","蛇精病","尼古拉斯赵四","本山兄弟"};
    QVector<QString> mIconNameList = {"spqy", "ymrl" ,"qq" ,"Cherry", "dr","jj","lswh","qmnn","spqy"};//图标资源列表
    QVector<QToolButton *> mvUserAvatar;
    QVector<bool> mbShowChatWnd;
};

#endif // LOGIN_H
