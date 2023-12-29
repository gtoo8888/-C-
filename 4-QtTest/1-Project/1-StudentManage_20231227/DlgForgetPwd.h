#ifndef DLGFORGETPWD_H
#define DLGFORGETPWD_H

#include <QDialog>
#include "StuSql.h"

namespace Ui {
class DlgForgetPwd;
}

class DlgForgetPwd : public QDialog
{
    Q_OBJECT

public:
    explicit DlgForgetPwd(QWidget *parent = nullptr);
    ~DlgForgetPwd();

    void slotBtnCancel(void);
    void slotBtnSave(void);
    void slotBtnExitUserName(void);

private:
    void initUi(void);
    void initConnect(void);
    Ui::DlgForgetPwd *ui;
    StuSql* sql = nullptr;
};

#endif // DLGFORGETPWD_H
