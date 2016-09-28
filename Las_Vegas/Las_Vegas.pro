TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tDeck.cpp \
    casino.cpp

QMAKE_CXXFLAGS += -std=c++14 -pedantic-errors


HEADERS += \
    tDeck.h \
    casino.h \
    player.h

