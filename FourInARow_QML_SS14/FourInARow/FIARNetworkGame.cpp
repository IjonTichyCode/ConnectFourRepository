#include <QDebug>
#include <string>
#include <random>

#include "FIARNetworkGame.h"
#include "fourinarowapplication.h"
#include "GameDataModel.h"
#include "FiarGameListener.h"


FIARNetworkGame::FIARNetworkGame(int startPlayer):
    FourInARowGame(startPlayer),
    generator((int)this),
    randomizer(0, getColumnCount()-1)
{
    aiPlayer.setDifficulty(3);
}

FIARNetworkGame::FIARNetworkGame(int startPlayer, int columns, int rows):
    FourInARowGame(startPlayer, columns, rows),
    generator((int)(this)),
    randomizer(0, getColumnCount()-1)
{
    aiPlayer.setDifficulty(3);
}

MoveResult FIARNetworkGame::move(int column, PlayerTypeTag playerTypeTag, int time)
{
    const FiarGameListener & gameListener = FourInARowApplication::getInstance()->getGameListener();
    GameSetup & gameSetup = GameDataModel::getInstance()->getGameSetup();


    int lastPlayer = getPlayerToMoveNext();

    MoveResult res;
    // human player doesn´t finished move in time -> random move
    if (!gameSetup.isCpu[lastPlayer] && gameSetup.useTimer && time<=0) {
        res = randomMove(column);
    }else if (playerTypeTag==PlayerTypeTag::CPU){
        aiPlayer.setDifficulty(gameSetup.level[lastPlayer]+1);
//        qDebug() << "aiMove: " << gameSetup.level[lastPlayer];
        column = aiPlayer.getMove(*this, lastPlayer);
        res = FourInARowGame::move(column);
    }else{
        res = FourInARowGame::move(column);
    }


    int currentPlayer = getPlayerToMoveNext();

    //    qDebug() << "latest Row: " << game->getLatestTokenRow();
    int * winRow;

    int maxTime = gameSetup.maxTime;

    switch (res) {
    case MoveResult::SUCCESS:
        ++gameSetup.moves;
        gameSetup.moveHistory.append(std::to_string(column));

        if (gameSetup.useTimer) {

            if (!gameSetup.isCpu[currentPlayer] && gameSetup.isCpu[lastPlayer]) {
                time = maxTime*60;
            }else if (!gameSetup.isCpu[0] && !gameSetup.isCpu[1]) {
                time = 2*maxTime*60-time;
            }else{
                time = 0;
            }
        }

        gameListener.tokenAdded(lastPlayer, column, getLatestTokenRow());
        gameListener.playersTurn(currentPlayer, time);
        break;

    case MoveResult::WIN:
        gameSetup.moveHistory.append(std::to_string(column));
        gameSetup.finished=1;
        ++gameSetup.moves;
        qDebug() << "win";
        winRow = getWinRow();
        gameListener.tokenAdded(lastPlayer, column, getLatestTokenRow());
        gameListener.playerWon(lastPlayer, winRow[0], winRow[1], winRow[2], winRow[3], winRow[4], winRow[5], winRow[6], winRow[7]);
        break;

    case MoveResult::TIE:
        gameSetup.moveHistory.append(std::to_string(column));
        gameSetup.finished=2;
        ++gameSetup.moves;
        qDebug() << "tie";
        gameListener.tokenAdded(lastPlayer, column, getLatestTokenRow());
        gameListener.gameEndedDrawn();
        break;

    case MoveResult::INVALID_COLUMN:
        gameListener.triedIllegalColumn(lastPlayer, column);
        break;

    case MoveResult::FULL_COLUMN:
        gameListener.triedFullColumn(lastPlayer, column);
        break;
    }

    return res;
}

MoveResult FIARNetworkGame::randomMove(int & column)
{
    MoveResult res;
    for (int i=0; i<50; ++i) {
        qDebug() << randomizer(generator);
    }

    do
    {
        column = randomizer(generator);
        res = FourInARowGame::move(column);
    } while (res==MoveResult::INVALID_COLUMN || res==MoveResult::FULL_COLUMN);

    return res;
}
