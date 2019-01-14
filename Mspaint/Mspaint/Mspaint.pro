#-------------------------------------------------
#
# Project created by QtCreator 2018-12-24T11:00:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mspaint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintshap.cpp \
    shap.cpp \
    lines.cpp \
    line.cpp \
    rect.cpp \
    ellipse.cpp \
    text.cpp \
    eraser.cpp

HEADERS  += mainwindow.h \
    paintshap.h \
    shap.h \
    lines.h \
    line.h \
    rect.h \
    ellipse.h \
    text.h \
    eraser.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
