#-------------------------------------------------
#
# Project created by QtCreator 2022-03-07T11:25:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_QtEvent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp

HEADERS  += widget.h \
    mylabel.h

FORMS    += widget.ui

CONFIG  += C++11
