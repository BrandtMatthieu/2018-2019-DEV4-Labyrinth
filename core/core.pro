TEMPLATE = subdirs
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt warn_on release

SOURCES += main_console.cpp

SUBDIRS += \
    model \
    controller \
