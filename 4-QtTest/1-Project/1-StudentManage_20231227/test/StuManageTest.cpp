#include "StuManageTest.h"

StuManageTest::StuManageTest(QObject *parent) : QObject(parent)
{

}

void StuManageTest::case1Serialnum()
{
    //测试编号
    int a = 1;
    int b = 2;
    QVERIFY((a+b) == 3);
}


