QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Clock/ClockConfig.cpp \
    Clock/ClockWdg.cpp \
    Clock/GLogger.cpp \
    Clock/StopwatchClockWdg.cpp \
    Clock/StopwatchSetShortKey.cpp \
    Clock/StopwatchSetWdg.cpp \
    Clock/StopwatchWdg.cpp \
    Clock/cJSON.c \
    VXPlayer/CondMutex.cpp \
    VXPlayer/XVPlayer.cpp \
    VXPlayer/VideoPlayerAudio.cpp \
    VXPlayer/VideoPlayerVideo.cpp \
    VXPlayer/VideoSlider.cpp \
    VXPlayer/VideoWdg.cpp \
    VXPlayer/XVPlayerWidget.cpp \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    Clock/ClockConfig.h \
    Clock/ClockWdg.h \
    Clock/GLogger.h \
    Clock/StopwatchClockWdg.h \
    Clock/StopwatchSetShortKey.h \
    Clock/StopwatchSetWdg.h \
    Clock/StopwatchWdg.h \
    Clock/cJSON.h \
    CondMutex.h \
    Utils.h \
    XVPlayer.h \
    VideoSlider.h \
    VideoWdg.h \
    XVPlayerWidget.h \
    MainWindow.h

FORMS += \
    Clock/ClockWdg.ui \
    Clock/StopwatchClockWdg.ui \
    Clock/StopwatchSetShortKey.ui \
    Clock/StopwatchSetWdg.ui \
    Clock/StopwatchWdg.ui \
    MainWindow.ui \
    XVPlayerWidget.ui

RC_ICONS = ./Clock/pic/Stopwatch.ico


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32{
#    FFMPEG_HOME = E:/Desktop/languguetest/Cplusplustest/4-QtTest/2-xiaomaoge/lib/ffmpeg
    FFMPEG_HOME = ../lib/ffmpeg
}

mac{
}

ubuntu{
}

INCLUDEPATH += ../3rdparty/ffmpeg
INCLUDEPATH += ../3rdparty/

LIBS += -L ../lib/QMakeAll \
        -lavcodec \
        -lavformat \
        -lavutil \
        -lSDL2 \
        -lswresample \
        -lswscale

DISTFILES += \
    Clock/ClockCfg.json \
    README.md

RESOURCES += \
    Clock/Stopwatch.qrc
