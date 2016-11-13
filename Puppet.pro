QT += core
QT -= gui

CONFIG += c++11

TARGET = Puppet
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    commands.cpp \
    signoff.cpp

HEADERS += \
    commands.h \
    signoff.h
