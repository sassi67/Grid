QT += core
QT -= gui

CONFIG += c++11

TARGET = Grid
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    gridmodel.cpp \
    grid.cpp \
    gridmodbus.cpp

HEADERS += \
    gridmodel.h \
    grid.h \
    gridmodbus.h
