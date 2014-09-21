#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlProperty>
#include <QDebug>

#include "fourinarowapplication.h"
#include "GameDatabase.h"
#include "GameDataModel.h"

#include "qmlmainwindow.h"
#include "QMLBoard.h"
#include "QMLBoardTile.h"
#include "QMLPlayScreen.h"
#include "QMLHighscoreScreen.h"
#include "QMLLoadScreen.h"
#include "QMLSQLScreen.h"
#include "QMLNewGameScreen.h"
#include "QMLOptions.h"

FourInARowApplication * FourInARowApplication::instance(NULL);

FourInARowApplication * FourInARowApplication::getInstance()
{
    if (!instance) {
        instance = new FourInARowApplication();
    }
    return instance;
}

FourInARowApplication::FourInARowApplication():
    game(NULL),
    gameListener(NULL),
    germanLocal(QLocale::German, QLocale::Germany),
    englishLocale(QLocale::English, QLocale::UnitedKingdom)
{
    instance = this;
}

FourInARowApplication::~FourInARowApplication()
{
    delete GameDatabase::getInstance();
    delete GameDataModel::getInstance();
    if (game) delete game;
    instance = NULL;
}

int FourInARowApplication::exec(int &argc, char **argv)
{
    GameDatabase * db = GameDatabase::getInstance();
    GameDataModel * gameDataModel = GameDataModel::getInstance();
    gameDataModel->init();

    QGuiApplication app(argc, argv);
    this->app = &app;

//    QLocale::setDefault(germanLocal);

//    QTranslator translator;
    deTranslator.load("tr_de");
    ukTranslator.load("tr_en");

    setLanguage(gameDataModel->getAppSetup().language);

    qmlRegisterType<QMLMainWindow>("FourInARow", 1, 0, "QMLMainWindow");
    qmlRegisterType<QMLBoard>("FourInARow", 1, 0, "QMLBoard");
    qmlRegisterType<QMLBoardTile>("FourInARow", 1, 0, "QMLBoardTile");
    qmlRegisterType<QMLPlayScreen>("FourInARow", 1, 0, "QMLPlayScreen");
    qmlRegisterType<QMLHighscoreScreen>("FourInARow", 1, 0, "QMLHighscoreScreen");
    qmlRegisterType<QMLLoadScreen>("FourInARow", 1, 0, "QMLLoadScreen");
    qmlRegisterType<QMLSQLScreen>("FourInARow", 1, 0, "QMLSQLScreen");
    qmlRegisterType<QMLNewGameScreen>("FourInARow", 1, 0, "QMLNewGameScreen");
    qmlRegisterType<QMLOptions>("FourInARow", 1, 0, "QMLOptions");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:///MainWindow.qml")));

    return app.exec();
}

FIARNetworkGame *FourInARowApplication::getGame()
{
    return game;
}

void FourInARowApplication::setGame(FIARNetworkGame *newGame)
{
    if (game) delete game;
    game = newGame;
}

void FourInARowApplication::setGameListener(FiarGameListener *gameListener)
{
    this->gameListener = gameListener;
}

void FourInARowApplication::setLanguage(int language)
{
    qDebug() << "setTranslaotr: " << language;
//    QLocale::setDefault(language==0 ? germanLocal : englishLocale);
    app->installTranslator(language==0 ? &deTranslator : &ukTranslator);
}

const FiarGameListener &FourInARowApplication::getGameListener() const
{
    return *gameListener;
}
