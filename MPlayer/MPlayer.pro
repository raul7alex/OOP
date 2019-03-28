QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MPlayer
TEMPLATE = app


SOURCES += main.cpp \
    mplayer.cpp

HEADERS  += \
    mplayer.h

FORMS    += \
    mplayer.ui
QT += multimediawidgets
QT += multimedia

CONFIG += mobility
MOBILITY =

