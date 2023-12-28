#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QAction>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    virtual void keyPressEvent(QKeyEvent *event);

public slots:
    void slotOpenStuManage(void);
    void slotExitLogin(void);

private:
    void initUi(void);
    void initConnect(void);
    QAction *enterAction = new QAction(this);
    Ui::Login *ui;
};

#endif // LOGIN_H
