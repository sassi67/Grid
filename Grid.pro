QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grid

TEMPLATE = app

SOURCES += main.cpp \
    gridmodel.cpp \
    grid.cpp \
    gridmodbus.cpp \
    mainwindow.cpp \
    tableview.cpp

HEADERS += \
    gridmodel.h \
    grid.h \
    gridmodbus.h \
    mainwindow.h \
    utils.h \
    tableview.h
