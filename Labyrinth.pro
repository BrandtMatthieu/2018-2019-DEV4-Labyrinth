TEMPLATE = app
CONFIG += debug\
    qt \
    console \
    warn_on \
    c++11 \

SUBDIRS += \
    core \
    console \
    gui \

DESTDIR = build

QMAKE += --Wall
