TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    source/game.cpp \
    source/player.cpp

HEADERS += \
    include/game.h \
    include/player.h \
    include/colors.h
