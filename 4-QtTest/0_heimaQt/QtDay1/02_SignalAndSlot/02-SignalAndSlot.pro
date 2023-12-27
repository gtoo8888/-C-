#-------------------------------------------------
#
# Project created by QtCreator 2021-11-07T12:47:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02-SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    student.cpp \
    teacher.cpp

HEADERS  += widget.h \
    student.h \
    teacher.h

FORMS    += widget.ui
