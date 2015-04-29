#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T02:27:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Howitzer
TEMPLATE = app


SOURCES += main.cpp\
        gungui.cpp \
    guncore.cpp \
    gungraphicsitem.cpp \
    targetgraphicsitem.cpp

HEADERS  += gungui.h \
    guncore.h \
    gungraphicsitem.h \
    targetgraphicsitem.h

FORMS    += gungui.ui

CONFIG += c++11
