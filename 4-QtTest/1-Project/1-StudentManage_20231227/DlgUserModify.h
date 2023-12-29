#ifndef DlgUserModify_H
#define DlgUserModify_H

#include <QDialog>

namespace Ui {
class DlgUserModify;
}

class DlgUserModify : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUserModify(QWidget *parent = nullptr);
    ~DlgUserModify();

    void slotBtnCancel(void);
    void slotBtnSave(void);

private:
    void initUi(void);
    void initConnect(void);
    Ui::DlgUserModify *ui;
};

#endif // DlgUserModify_H
