#ifndef UTILS_H
#define UTILS_H

#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>

#define myDebug() qDebug()<<QString("[%1]:%2 %3").arg(__FILE__).arg(__LINE__).arg(__FUNCTION__)


#endif // UTILS_H
