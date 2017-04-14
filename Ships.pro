#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T13:37:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ships
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ship.cpp \
    port.cpp \
    base.cpp

HEADERS  += mainwindow.h \
    ship.h \
    port.h \
    base.h

FORMS    += mainwindow.ui
