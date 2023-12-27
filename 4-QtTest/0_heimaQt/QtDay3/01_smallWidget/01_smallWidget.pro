#-------------------------------------------------
#
# Project created by QtCreator 2022-03-07T10:59:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_smallWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    smallwidget.cpp

HEADERS  += widget.h \
    smallwidget.h

FORMS    += widget.ui \
    smallwidget.ui

CONFIG += C++11
