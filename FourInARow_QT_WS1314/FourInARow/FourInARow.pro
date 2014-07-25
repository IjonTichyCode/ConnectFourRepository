#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T18:16:42
#
#-------------------------------------------------

QT       += core gui\
    sql\
    opengl\
    svg\
    printsupport\
    multimedia\

CONFIG  += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FourInARow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fourinarowgame.cpp \
    fourinarowboard.cpp \
    rowfield.cpp \
    fiartextview.cpp \
    SimpleGameScene.cpp \
    tilegraphicsitem.cpp \
    GameScene.cpp \
    GameView.cpp \
    tokenfallanimation.cpp \
    NewGameDialog.cpp \
    NewGameSetup.cpp \
    GameDatabase.cpp \
    sqladminframe.cpp \
    HighscoreTableView.cpp \
    LoadGameTableView.cpp \
    TablePushButton.cpp \
    TileBoardGraphicsItem.cpp \
    TilePixmapGraphicsItem.cpp \
    PrimitivesGameScene.cpp \
    TilePrimitivesGraphicsItem.cpp \
    SvgGameScene.cpp \
    TileSvgGraphicsItem.cpp \
    tokenfallsound.cpp \
    CpuPlayer.cpp

HEADERS  += mainwindow.h \
    fourinarowgame.h \
    fourinarowboard.h \
    rowfield.h \
    fiartextview.h \
    SimpleGameScene.h \
    tilegraphicsitem.h \
    GameScene.h \
    GameView.h \
    tokenfallanimation.h \
    NewGameDialog.h \
    NewGameSetup.h \
    GameDatabase.h \
    sqladminframe.h \
    HighscoreTableView.h \
    LoadGameTableView.h \
    TablePushButton.h \
    TileBoardGraphicsItem.h \
    TilePixmapGraphicsItem.h \
    PrimitivesGameScene.h \
    TilePrimitivesGraphicsItem.h \
    SvgGameScene.h \
    TileSvgGraphicsItem.h \
    tokenfallsound.h \
    CpuPlayer.h

FORMS    += mainwindow.ui \
    NewGameDialog.ui \
    sqladminframe.ui

TRANSLATIONS = MyProject_de.ts \
    MyProject_en.ts

OTHER_FILES += \
    MyProject_de.ts \
    MyProject_en.ts \
    MyProject_en.qm
