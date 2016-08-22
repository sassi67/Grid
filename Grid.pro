QT += core
QT -= gui

CONFIG += c++11

TARGET = Grid
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    gridmodel.cpp \
    gridmodelitem.cpp

HEADERS += \
    gridmodel.h \
    gridmodelitem.h
