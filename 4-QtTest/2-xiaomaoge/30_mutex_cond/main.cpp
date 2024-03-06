#include "Widget.h"
#include <QApplication>
#include "Utils.h"

#undef main

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    SDL_version version;
    SDL_VERSION(&version);
    qDebug() << version.major << version.minor << version.patch;

//    if(SDL_Init(SDL_INIT_VIDEO)) {
//        qDebug() << "can not int SDL error！！！";
//        return -1;
//    }
//    else {
//        qDebug() << "success！！！" ;
//    }
//    SDL_Quit();
    w.show();
    return a.exec();
}
