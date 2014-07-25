#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlProperty>

#include "qmlmainwindow.h"
#include "QMLBoard.h"
#include "QMLBoardTile.h"
#include "QMLPlayScreen.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QMLMainWindow>("FourInARow", 1, 0, "QMLMainWindow");
    qmlRegisterType<QMLBoard>("FourInARow", 1, 0, "QMLBoard");
    qmlRegisterType<QMLBoardTile>("FourInARow", 1, 0, "QMLBoardTile");
    qmlRegisterType<QMLPlayScreen>("FourInARow", 1, 0, "QMLPlayScreen");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:///MainWindow.qml")));

    return app.exec();
}
