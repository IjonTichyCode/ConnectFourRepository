#include "QMLPlayScreen.h"
#include <QDebug>
#include "fourinarowapplication.h"
#include "GameDataModel.h"
#include "FiarGameListenerForQMLGui.h"
#include <QTranslator>

QMLPlayScreen::QMLPlayScreen(QQuickItem *parent) :
    QQuickItem(parent),
    loadGameFlag(false)
{
    gameListener = new FiarGameListenerForQMLGui(this);

//    FIARNetworkGame  * game = new FIARNetworkGame(0,7,6);
    FourInARowApplication::getInstance()->setGameListener(gameListener);
    //    connect(this, &QMLPlayScreen::makeMove, this, &QMLPlayScreen::receiveMove);
}

QMLPlayScreen::~QMLPlayScreen()
{
    delete gameListener;
}

void QMLPlayScreen::gameTokenAdded(int player, int column, int row)
{
    if (loadGameFlag) {
        setupToken(player, column, row);
    }else{
        dropToken(column, row);
    }

}

void QMLPlayScreen::gamePlayersTurn(int player, int time)
{
    if (!loadGameFlag) {
        bool isCpu = GameDataModel::getInstance()->getGameSetup().isCpu[player];
        newInteractiveToken(player, isCpu);
        setTimer(time);
        GameSetup & gameSetup = GameDataModel::getInstance()->getGameSetup();
        QString statusMsg(player==0 ? gameSetup.player0.c_str() : gameSetup.player1.c_str());
        setStatusMessage(tr("turn: ") + statusMsg);

        if (isCpu) {
            FourInARowApplication::getInstance()->getGame()->move(0, PlayerTypeTag::CPU, 0);
        }
    }
}

void QMLPlayScreen::gamePlayerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3)
{
    GameDataModel * data = GameDataModel::getInstance();
    GameSetup & gameSetup = data->getGameSetup();
    map<int, PlayerData> & players = data->getPlayers();

    int winnerId = player==0 ? gameSetup.player0Id : gameSetup.player1Id;
    int loserId =  player==0 ? gameSetup.player1Id : gameSetup.player0Id;

    qDebug() << players.at(winnerId).name.c_str() << " - wins: " << players.at(winnerId).wins;
    qDebug() << players.at(loserId).name.c_str() << " - looses: " << players.at(loserId).losses;

    ++players.at(winnerId).wins;
    ++players.at(loserId).losses;

    qDebug() << players.at(winnerId).name.c_str() << " - wins: " << players.at(winnerId).wins;
    qDebug() << players.at(loserId).name.c_str() << " - looses: " << players.at(loserId).losses;

    data->updatePlayer(players.at(winnerId));
    data->updatePlayer(players.at(loserId));

    highscoreChanged();

    QString statusMsg( player==0 ? gameSetup.player0.c_str() : gameSetup.player1.c_str() );
    setStatusMessage(statusMsg + + " " + tr("wins"));
    qDebug() << "winrow: " << col0 << "," << row0 << "," << col1 << "," << row1 << "," << col2 << "," << row2 << "," << col3 << "," << row3;
    playerWon(player, col0, row0, col1, row1, col2, row2, col3, row3);
}

void QMLPlayScreen::gameEndedDrawn()
{
    GameDataModel * data = GameDataModel::getInstance();
    GameSetup & gameSetup = data->getGameSetup();
    map<int, PlayerData> & players = data->getPlayers();

    ++players.at(gameSetup.player0Id).ties;
    ++players.at(gameSetup.player1Id).ties;

    data->updatePlayer(players.at(gameSetup.player1Id));
    data->updatePlayer(players.at(gameSetup.player0Id));

    highscoreChanged();
    setStatusMessage(tr("tie"));
    tie();
}

void QMLPlayScreen::gameTriedIllegalColumn(int player, int column)
{
    rejectMove();
}

void QMLPlayScreen::gameTriedFullColumn(int player, int column)
{
    rejectMove();
}

void QMLPlayScreen::makeMove(int column, int time)
{
    FIARNetworkGame * game = FourInARowApplication::getInstance()->getGame();
    game->move(column, PlayerTypeTag::LOCAL, time);
}

void QMLPlayScreen::saveGame(int time)
{
    GameSetup & gameSetup = GameDataModel::getInstance()->getGameSetup();
    gameSetup.time = time;

    if (!gameSetup.finished && gameSetup.moves>0) {
        GameDataModel::getInstance()->saveGame(gameSetup);
        emit gameSaved();
    }
}

void QMLPlayScreen::showGame()
{

}

void QMLPlayScreen::startLoadGame()
{
    emit clear();
    loadGameFlag = true;
}

void QMLPlayScreen::endLoadGame()
{
    loadGameFlag = false;

    const GameSetup & gameSetup = GameDataModel::getInstance()->getGameSetup();
    FIARNetworkGame * game = FourInARowApplication::getInstance()->getGame();
    int player = game->getPlayerToMoveNext();
    gamePlayersTurn(player, (gameSetup.useTimer && !gameSetup.isCpu[player]) ? gameSetup.time : 0 );
}

void QMLPlayScreen::timerExpired()
{
    qDebug() << "QMLPlayScreen::timerExpired()";
    FIARNetworkGame * game = FourInARowApplication::getInstance()->getGame();
    game->move(0,PlayerTypeTag::LOCAL,0);
}
