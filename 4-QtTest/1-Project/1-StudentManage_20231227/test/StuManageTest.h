#ifndef STUMANAGETEST_H
#define STUMANAGETEST_H

#include <QObject>
#include <QTest>

class StuManageTest : public QObject
{
    Q_OBJECT
public:
    explicit StuManageTest(QObject *parent = nullptr);

signals:

private slots:
    void case1Serialnum();
};

//QTEST_MAIN(StuManageTest)

#endif // STUMANAGETEST_H
