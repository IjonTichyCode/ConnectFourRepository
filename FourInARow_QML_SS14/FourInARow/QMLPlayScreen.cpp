#include "QMLPlayScreen.h"
#include <QDebug>


QMLPlayScreen::QMLPlayScreen(QQuickItem *parent) :
    QQuickItem(parent)
{
    connect(this, &QMLPlayScreen::makeMove, this, &QMLPlayScreen::receiveMove);    
}

void QMLPlayScreen::receiveMove(int column)
{
    int player = game.getPlayerToMoveNext();

//    if (gameSetup->isCpu[player]) {
//        columnIndex = cpuPlayers[player].getCpuMove(*game);
//    }

    MoveResult res = game.move(column);
    QString message;
    qDebug() << "latest Row: " << game.getLatestTokenRow();

    switch (res) {
    case MoveResult::SUCCESS:
        emit dropToken(column, game.getLatestTokenRow());
        emit newInteractiveToken(game.getPlayerToMoveNext(), false);

//        gameSetup->moveHistory.append(QString::number(columnIndex));
//        ++gameSetup->moves;
//        printNextPlayer();
        break;

    case MoveResult::WIN:
        emit dropToken(column, game.getLatestTokenRow());
//        gameSetup->moveHistory.append(QString::number(columnIndex));
//        gameSetup->startPlayer=player;
//        gameSetup->finished=1;
//        ++gameSetup->moves;
//        mainWindow->setStatusMessage( (game->getPlayerToMoveNext()==0 ? gameSetup->player0 : gameSetup->player1)
//            + "wins with "
//            + QString::number(gameSetup->moves+1)
//            + " moves!"
//        );
//        gameScene->playerWins( player, game->getWinRow() );
//        mainWindow->saveGame();
        qDebug() << "win";
        break;

    case MoveResult::TIE:
        emit dropToken(column, game.getLatestTokenRow());
//        gameSetup->moveHistory.append(QString::number(columnIndex));
//        gameSetup->finished=2;
//        ++gameSetup->moves;
//        gameScene->tie();
//        mainWindow->saveGame();
        qDebug() << "tie";
//        mainWindow->setStatusMessage("Game finished with a tie!");
        break;

    case MoveResult::INVALID_COLUMN:
//        gameScene->failToken(player, columnIndex, game->getLatestTokenRow());
        break;

    case MoveResult::FULL_COLUMN:
//        gameScene->failToken(player, columnIndex, game->getLatestTokenRow());
//        mainWindow->setStatusMessage( "Column is full, try another one "
//            + (game->getPlayerToMoveNext()==0 ? gameSetup->player0 : gameSetup->player1)
//            + "!"
//        );
        break;
    }

    // if game isnt finished and next player is cpu, begin next turn immediately
//    if (!game->isFinished() && gameSetup->isCpu[game->getPlayerToMoveNext()]) {
//        move();
//    }

    qDebug() << "move" << column << "received";
}
