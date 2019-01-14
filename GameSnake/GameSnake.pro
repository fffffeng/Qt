#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T10:30:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameSnake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamecontroller.cpp

HEADERS  += mainwindow.h \
    gamecontroller.h

FORMS    += mainwindow.ui
