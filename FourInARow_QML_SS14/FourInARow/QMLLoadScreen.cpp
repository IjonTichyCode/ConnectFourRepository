#include <QDebug>
#include <vector>
#include <string>

#include "QMLLoadScreen.h"
#include "GameDataModel.h"
#include "GameSetup.h"
#include "fourinarowapplication.h"
#include "FIARNetworkGame.h"

using std::vector;


QMLLoadScreen::QMLLoadScreen(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void QMLLoadScreen::loadGame(int index)
{
    GameSetup & gameSetup = GameDataModel::getInstance()->loadGame(index);

    qDebug() << "load game: " << QString(gameSetup.moveHistory.c_str());

    string moveHistory = gameSetup.moveHistory;
    gameSetup.moveHistory = "";

    emit startLoadGame();
    emit setBoardDimension(gameSetup.columns, gameSetup.rows);

    FIARNetworkGame * game = new FIARNetworkGame(0, gameSetup.columns, gameSetup.rows);
    FourInARowApplication::getInstance()->setGame(game);

    for (int i=0; i<moveHistory.length(); ++i) {
        string digit;
        digit.push_back(moveHistory.at(i));
        int column = std::stoi(digit);
        game->move(column, PlayerTypeTag::LOCAL, 1);
    }

    emit endLoadGame();
}

void QMLLoadScreen::loadLatestGame()
{
   const vector<GameSetup> & savedGames = GameDataModel::getInstance()->getSavedGames();
   if (savedGames.size()>0) {
       loadGame(savedGames.at(0).gameId);
   }
}

void QMLLoadScreen::populate()
{
    const vector<GameSetup> & savedGames = GameDataModel::getInstance()->getSavedGames();

    for (const GameSetup & game : savedGames) {
        addEntry(QString(game.player0.c_str()), QString(game.player1.c_str()), game.gameId);
    }
}
