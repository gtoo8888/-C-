#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QAction>
#include "StuSql.h"
#include "StuManage.h"

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
    void slotReShowLogin(void);


    bool eventFilter(QObject *watched, QEvent *event);

private:
    void initUi(void);
    void initConnect(void);
    void slotlabelAddUser(void);
    void slotForgetPwd(void);
    QAction *enterAction = new QAction(this);
    Ui::Login *ui;
    StuSql* mpSql;
    StuManage* mpStuManage = nullptr;
};

#endif // LOGIN_H
