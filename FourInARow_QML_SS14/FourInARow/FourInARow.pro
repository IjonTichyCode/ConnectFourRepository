TEMPLATE = app

QT += qml quick sql

CONFIG += c++11

SOURCES += main.cpp \
    QMLBoard.cpp \
    QMLBoardTile.cpp \
    qmlmainwindow.cpp \
    fourinarowboard.cpp \
    fourinarowgame.cpp \
    QMLPlayScreen.cpp \
    rowfield.cpp \
    FiarArtificialPlayer.cpp \
    QMLHighscoreScreen.cpp \
    QMLLoadScreen.cpp \
    GameDatabase.cpp \
    GameSetup.cpp \
    QMLSQLScreen.cpp \
    fourinarowapplication.cpp \
    GameDataModel.cpp \
    playerdata.cpp \
    QMLNewGameScreen.cpp \
    FIARNetworkGame.cpp \
    FIARApplicationSetup.cpp \
    FiarGameListener.cpp \
    FiarGameListenerForQMLGui.cpp \
    QMLOptions.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = ""

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
    FiarArtificialPlayer.h \
    QMLHighscoreScreen.h \
    QMLLoadScreen.h \
    GameDatabase.h \
    GameSetup.h \
    QMLSQLScreen.h \
    fourinarowapplication.h \
    GameDataModel.h \
    playerdata.h \
    QMLNewGameScreen.h \
    FIARNetworkGame.h \
    FIARApplicationSetup.h \
    FiarGameListener.h \
    FiarGameListenerForQMLGui.h \
    QMLOptions.h

TRANSLATIONS += \
    tr_de.ts \
    tr_en.ts


OTHER_FILES +=

lupdate_only {
#    SOURCES += *.qml
}
