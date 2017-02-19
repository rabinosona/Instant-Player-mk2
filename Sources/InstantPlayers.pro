#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T11:37:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InstantPlayers
TEMPLATE = app

@
QT += multimedia
QT += multimediawidgets
QT += widgets
@

SOURCES += main.cpp\
        mainwindow.cpp \
    videowindow.cpp

HEADERS  += mainwindow.h \
    videowindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    graphics.qrc
