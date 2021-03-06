#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T08:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Las_Vegas_GUI
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
    titleWindow.cpp \
    tDeck.cpp \
    subject.cpp \
    player.cpp \
    game.cpp \
    formulaireWindow.cpp \
    casino.cpp \
    gamewindow.cpp

HEADERS  += \
    casino.h \
    formulaireWindow.h \
    game.h \
    observer.h \
    player.h \
    subject.h \
    tDeck.h \
    titleWindow.h \
    gamewindow.h

FORMS    +=

RESOURCES +=
