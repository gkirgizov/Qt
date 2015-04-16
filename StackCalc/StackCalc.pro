QT += core gui
QT += testlib

TARGET = StackCalc
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

CONFIG += c++11

SOURCES += main.cpp \
    calcstack.cpp \
    staccalctest.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    calcstack.h \
    linkedstack.h \
    stack.h \
    staccalctest.h
