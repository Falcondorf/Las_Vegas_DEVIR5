#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T08:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Las_Vegas_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titleWindow.cpp \
    tDeck.cpp \
    subject.cpp \
    player.cpp \
    game.cpp \
    formulaireWindow.cpp \
    casino.cpp \
    gamewindow.cpp

HEADERS  += mainwindow.h \
    casino.h \
    formulaireWindow.h \
    game.h \
    observer.h \
    player.h \
    subject.h \
    tDeck.h \
    titleWindow.h \
    gamewindow.h

FORMS    += mainwindow.ui

RESOURCES +=
