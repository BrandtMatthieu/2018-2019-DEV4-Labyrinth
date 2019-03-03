TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    source/board.cpp \
    source/game.cpp \
    source/objectiveCard.cpp \
    source/player.cpp \
    source/tile.cpp \

HEADERS += \
    include/board.h \
    include/colors.h \
    include/game.h \
    include/objectiveCard.h \
    include/objectivesTypes.h \
    include/player.h \
    include/tile.h
