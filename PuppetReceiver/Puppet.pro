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
    Commands_cpp/browserdownload.cpp

HEADERS += \
    Commands_h/commands.h \
    Commands_h/signoff.h \
    Commands_h/browsersearch.h \
    Commands_h/pcstatus.h \
    test.h \
    Commands_h/turnoff.h \
    Commands_h/reboot.h \
    Commands_h/browserdownload.h \
    macros.h \
