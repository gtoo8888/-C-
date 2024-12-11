#include <SDL2/SDL.h>
#include <QApplication>
#include <QDebug>
#include "XVPlayerWidget.h"

#undef main
void testSDL(void) {
    SDL_version version;
    SDL_VERSION(&version);
    qDebug() << version.major << version.minor << version.patch;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        qDebug() << "can not int SDL error!!!";
    } else {
        qDebug() << "success!!!";
    }
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //    testSDL();

    XVPlayerWidget w;
    w.show();
    return a.exec();
}
