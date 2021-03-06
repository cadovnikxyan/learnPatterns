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
    bridge.cpp \
    ui_bridge.cpp \
    chainbase.cpp \
    composite.cpp \
    templatemethod.cpp \
    decorator.cpp \
    sortalgorithms.cpp \
    findalgorithms.cpp \
    node.cpp \
    tree.cpp \
    mainArch.cpp \
    huffmanalgorithm.cpp \
    threadspatterns.cpp \
    singlton.cpp \
    pyrun.cpp \
    moveconstructor.cpp

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
    bridge.h \
    ui_bridge.h \
    chainbase.h \
    composite.h \
    templatemethod.h \
    decorator.h \
    sortalgorithms.h \
    findalgorithms.h \
    node.h \
    tree.h \
    huffmanalgorithm.h \
    threadspatterns.h \
    singlton.h \
    pyrun.h \
    moveconstructor.h

FORMS    += mainwindow.ui
LIBS     += -lboost_system

INCLUDEPATH += /usr/include/python3.5m

LIBS += -L/usr/lib/x86_64-linux-gnu

LIBS += -Wl,-Bstatic -lpython3.5m -Wl,-Bdynamic

LIBS += -lz -lexpat -ldl -lutil

#QMAKE_CXXFLAGS="-std=gnu++14"

DISTFILES += \
    PyTest.py \
    PyTest.py.codeobj

CONFIG += no_keywords c++14
