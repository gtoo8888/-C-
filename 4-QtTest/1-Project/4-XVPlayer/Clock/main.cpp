#include <SDL2/SDL.h>
#include <QApplication>
#include <QDebug>
#include "StopwatchWdg.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //    MainWindow w;
    //    w.show();

    StopwatchWdg w;
    w.show();
    return a.exec();
}
