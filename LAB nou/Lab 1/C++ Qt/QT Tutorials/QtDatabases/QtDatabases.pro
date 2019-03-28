#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T14:54:44
#
#-------------------------------------------------

QT += core gui widgets
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDatabases
TEMPLATE = app


QTPLUGIN += QSQLMYSQL

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
