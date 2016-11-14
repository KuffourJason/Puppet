QT += core
QT -= gui

CONFIG += c++11

TARGET = Puppet
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Commands_cpp/commands.cpp \
    Commands_cpp/signoff.cpp

HEADERS += \
    Commands_h/commands.h \
    Commands_h/signoff.h
