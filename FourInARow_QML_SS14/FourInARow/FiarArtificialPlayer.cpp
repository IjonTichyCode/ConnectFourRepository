#include <QDebug>

#include "fiarartificialplayer.h"

using namespace std;

FiarArtificialPlayer::FiarArtificialPlayer():
    difficulty(0),
//    generator((int)this),
    game(NULL),
    winMultiplier(25),
    treeDepthPenalty(.5)
{
}

FiarArtificialPlayer::~FiarArtificialPlayer()
{
    if (game) delete game;
}

void FiarArtificialPlayer::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

float FiarArtificialPlayer::recursiveValue(int column, int depth)
{
    MoveResult res = game->move(column);

    if (res==MoveResult::SUCCESS) {
        float val = rowField->getValue();

        if (depth>0) {
            for (int i=0; i<=maxColumn;++i) {
                val += recursiveValue(i, depth-1)/columns * treeDepthPenalty;
            }
        }

        game->removeToken(column);

        return val;
    }else if (res==MoveResult::WIN) {
        game->removeToken(column);
        return (game->getPlayerToMoveNext()*2-1) * winMultiplier*columns + rowField->getValue();
    }else if (res==MoveResult::TIE) {
        return 0;
    }else {
        if (depth==difficulty) {
            allowedColumns[column] = false;
        }
        return 0;
    }

}

int FiarArtificialPlayer::getMove(const FourInARowGame & pGame, int player)
{
    if (game) delete game;
    game = new FourInARowGame(pGame);
    rowField = &game->getBoard()->rowField;


    maxColumn = rowField->getColumns()-1;
    columns = rowField->getColumns();

    for (int i=0; i<=maxColumn;++i) {
        allowedColumns[i]=true;
    }

    float values[rowField->getColumns()];

    for (int i=0; i<=maxColumn; ++i) {
        values[i] = recursiveValue(i, difficulty) * /*sign*/(player*2-1);
    }

    int move = 0;
    while (!allowedColumns[move]) {
        ++move;
    }
    for (int i=move+1; i<=maxColumn; ++i) {
        if (allowedColumns[i] && values[i]>values[move]) {
            move=i;
        }
    }

    return move;

//    uniform_int_distribution<int> distribution(0, pGame.getColumnCount()-1);
//    return distribution(generator);
}
