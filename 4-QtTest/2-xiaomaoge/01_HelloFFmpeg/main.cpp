#include "Widget.h"

#include <QApplication>

extern "C"{
    #include "libavcodec/avcodec.h"
}

int main(int argc, char *argv[])
{
    qDebug("------------------------------------------------------------------------");
    qDebug("%s", avcodec_configuration());
    qDebug("version: %d", avcodec_version());
    qDebug("------------------------------------------------------------------------");


    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
