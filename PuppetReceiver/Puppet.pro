QT += core
QT -= gui

CONFIG += c++11

TARGET = Puppet
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Commands_cpp/commands.cpp \
    Commands_cpp/signoff.cpp \
    Commands_cpp/browsersearch.cpp \
    Commands_cpp/pcstatus.cpp \
    test.cpp \
    Commands_cpp/turnoff.cpp \
    Commands_cpp/reboot.cpp \
    Commands_cpp/openprogram.cpp \
    Commands_cpp/movefof.cpp \
    Commands_cpp/searchfolder.cpp

HEADERS += \
    Commands_h/commands.h \
    Commands_h/signoff.h \
    Commands_h/browsersearch.h \
    Commands_h/pcstatus.h \
    test.h \
    Commands_h/turnoff.h \
    Commands_h/reboot.h \
    macros.h \
    Commands_h/openprogram.h \
    Commands_h/movefof.h \
    Commands_h/searchfolder.h
