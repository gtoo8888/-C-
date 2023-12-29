#ifndef DLGSTUADD_H
#define DLGSTUADD_H

#include <QDialog>
#include "StuSql.h"

namespace Ui {
class DlgStuAdd;
}

class DlgStuAdd : public QDialog
{
    Q_OBJECT

public:
    enum ModType{
        Update = 1,
        Add
    };

    explicit DlgStuAdd(QWidget *parent = nullptr);
    ~DlgStuAdd();
    void setType(ModType type,StuInfo *info = nullptr);

public slots:
    void slotBtnCancel(void);
    void slotBtnSave(void);

private:
    void initUi(void);
    void initConnect(void);
    Ui::DlgStuAdd *ui;
    qint8 mType;
    StuInfo* mStuInfo = nullptr;
};

#endif // DLGSTUADD_H
