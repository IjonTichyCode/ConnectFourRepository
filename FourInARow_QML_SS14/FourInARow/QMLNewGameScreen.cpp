#include "QMLNewGameScreen.h"

#include <QDebug>
#include <map>
#include "GameDataModel.h"
#include "playerdata.h"
#include "fourinarowapplication.h"
#include "FIARNetworkGame.h"
#include "FIARApplicationSetup.h"

using std::map;

QMLNewGameScreen::QMLNewGameScreen(QQuickItem *parent) :
    QQuickItem(parent)
{

}

void QMLNewGameScreen::populate()
{
    const map<int, PlayerData> & players =  GameDataModel::getInstance()->getPlayers();
//    for (int i=0; i<players.size(); ++i) {
//        const PlayerData & player = players.at(i);

//        emit addEntry(player.index, QString(player.name.c_str()), player.isCpu, player.level);
//    }

    for (const auto & playerEntry : players) {
        const PlayerData & player = playerEntry.second;
        emit addEntry(player.index, QString(player.name.c_str()), player.isCpu, player.level);
    }
}

void QMLNewGameScreen::addNewPlayer(QString name, bool isCpu, int level)
{
    PlayerData player;
    player.name = name.toStdString();
    player.isCpu = isCpu;
    player.level = level;

    int index = GameDataModel::getInstance()->addPlayer(player);
    if (index>=0) {
        emit addEntry(player.index, name, player.isCpu, player.level);
        emit newPlayerAdded();
    }
}

void QMLNewGameScreen::setupNewGame()
{
   GameDataModel::getInstance()->newGameSetup();
}

void QMLNewGameScreen::setTimer(bool useTimer, int time)
{
    GameSetup & setup = GameDataModel::getInstance()->getGameSetup();
    setup.useTimer = useTimer;
    setup.maxTime = time;
    setup.time = time * 60;

    FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
    appSetup.useTimer = useTimer;
    appSetup.maxTime = time;
}

void QMLNewGameScreen::setPlayers(int player0Id, int player1Id)
{
    qDebug() << "player0Id: " << player0Id;
    qDebug() << "player1Id: " << player1Id;

    GameSetup & setup = GameDataModel::getInstance()->getGameSetup();
    const map<int, PlayerData> & players = GameDataModel::getInstance()->getPlayers();

    setup.player0Id = player0Id;
    setup.player1Id = player1Id;
    setup.player0 = players.at(player0Id).name;
    setup.player1 = players.at(player1Id).name;
    setup.isCpu[0] = players.at(player0Id).isCpu;
    setup.isCpu[1] = players.at(player1Id).isCpu;
    setup.level[0] = players.at(player0Id).level;
    setup.level[1] = players.at(player1Id).level;

    FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
    appSetup.player0Id = player0Id;
    appSetup.player1Id = player1Id;
}

void QMLNewGameScreen::setBoardSize(int columns, int rows)
{
    GameSetup & setup = GameDataModel::getInstance()->getGameSetup();
    setup.columns = columns;
    setup.rows = rows;


    FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
    appSetup.columns = columns;
    appSetup.rows = rows;

    qDebug() << "QMLNewGameScreen::setBoardSize: " << appSetup.columns << ", " << appSetup.rows;
}

void QMLNewGameScreen::startGame()
{
   FourInARowApplication * gameApp = FourInARowApplication::getInstance();
   const GameSetup & gameSetup = GameDataModel::getInstance()->getGameSetup();

   FIARNetworkGame * game = new FIARNetworkGame(0, gameSetup.columns, gameSetup.rows);
   gameApp->setGame(game);
}

void QMLNewGameScreen::qmlComponentCompleted()
{
     const FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
     selectPlayers(appSetup.player0Id, appSetup.player1Id);
     setBoardSizeOption(appSetup.columns, appSetup.rows);
     setTimerOption(appSetup.useTimer, appSetup.maxTime);
}
