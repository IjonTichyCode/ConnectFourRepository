#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlProperty>

#include "fourinarowapplication.h"

#include "qmlmainwindow.h"
#include "QMLBoard.h"
#include "QMLBoardTile.h"
#include "QMLPlayScreen.h"
#include "QMLHighscoreScreen.h"
#include "QMLLoadScreen.h"
#include "QMLSQLScreen.h"

int main(int argc, char *argv[])
{
    FourInARowApplication * fiarApp = FourInARowApplication::getInstance();
    int exitState = fiarApp->exec(argc, argv);
    delete fiarApp;
    return exitState;
}
