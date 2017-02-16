#-------------------------------------------------
#
# Project created by QtCreator 2017-02-14T07:44:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = learnPatterns
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    warrior.cpp \
    infantryman.cpp \
    horseman.cpp \
    archer.cpp \
    logger.cpp \
    loggerimpl.cpp \
    logui.cpp \
    swordman.cpp \
    ui_logger_impl.cpp \
    game.cpp \
    command.cpp \
    creategamecommand.cpp \
    opengamecommand.cpp \
    savegamecommand.cpp \
    movegamecommand.cpp \
    uiadapter.cpp \
    adapter.cpp

HEADERS  += mainwindow.h \
    warrior.h \
    infantryman.h \
    horseman.h \
    archer.h \
    logger.h \
    loggerimpl.h \
    logui.h \
    swordman.h \
    ui_logger_impl.h \
    game.h \
    command.h \
    creategamecommand.h \
    opengamecommand.h \
    savegamecommand.h \
    movegamecommand.h \
    uiadapter.h \
    adapter.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS="-std=gnu++14"
