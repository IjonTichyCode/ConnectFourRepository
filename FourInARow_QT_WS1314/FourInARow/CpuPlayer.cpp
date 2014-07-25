#include "CpuPlayer.h"
#include <cstdlib>
#include "fourinarowboard.h"

#include <QDebug>

CpuPlayer::CpuPlayer():
    level(1)
{
}

int CpuPlayer::getCpuMove(FourInARowGame &game)
{
    FourInARowGame privGame(game);
    int columIndex;
    MoveResult res;
    do {
        columIndex = rand() % privGame.getColumnCount();
        res = privGame.move(columIndex);
    } while(! (res==MoveResult::SUCCESS || res==MoveResult::WIN || res==MoveResult::TIE)) ;


    return columIndex;
}

void CpuPlayer::setLevel(int level)
{
    this->level = level;
}
