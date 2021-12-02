#-------------------------------------------------
#
# Project created by QtCreator 2021-11-26T15:28:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chiphers_lab3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    magic.cpp \
    empreror.cpp \
    winston.cpp

HEADERS  += mainwindow.h \
    magic.h \
    empreror.h \
    winston.h \
    dependence_qt.h \
    const.h

FORMS    += mainwindow.ui \
    magic.ui \
    empreror.ui \
    winston.ui
