#include <QtWidgets/QApplication>
#include "GtooPlayer.h"
#include "RemWordWdg.h"
#include "gtest/gtest.h"
// #include <QTest>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();

    //GtooPlayer w;
    //w.show();

    RemWordWdg* remWordWdg = new RemWordWdg();
    remWordWdg->show();


    return a.exec();
}
