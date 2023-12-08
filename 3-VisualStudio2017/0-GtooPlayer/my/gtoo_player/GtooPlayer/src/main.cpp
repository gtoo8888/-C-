#include "GtooPlayer.h"
#include <QtWidgets/QApplication>
#include "gtest/gtest.h"
//#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    GtooPlayer w;
    w.show();
    return a.exec();
}
