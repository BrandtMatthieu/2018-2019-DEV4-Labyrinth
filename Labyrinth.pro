TEMPLATE = app
CONFIG += debug\
    qt \
    console \
    warn_on \
    c++11 \

SOURCES += core\main_console.cpp

SUBDIRS += \
    core \
    console \
    gui \

INCLUDEPATH += \
    . \
    core \
    console \
    gui \

DESTDIR = build

QMAKE += --Wall

message($$SOURCES)
