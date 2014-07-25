TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    QMLBoard.cpp \
    QMLBoardTile.cpp \
    qmlmainwindow.cpp \
    fourinarowboard.cpp \
    fourinarowgame.cpp \
    QMLPlayScreen.cpp \
    rowfield.cpp \
    FiarArtificialPlayer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    QMLBoard.h \
    QMLBoardTile.h \
    qmlmainwindow.h \
    fourinarowboard.h \
    fourinarowgame.h \
    QMLPlayScreen.h \
    rowfield.h \
    FiarArtificialPlayer.h
