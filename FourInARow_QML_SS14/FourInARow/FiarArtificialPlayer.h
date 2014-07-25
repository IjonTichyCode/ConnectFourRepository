#ifndef FIARARTIFICIALPLAYER_H
#define FIARARTIFICIALPLAYER_H

#include "rowfield.h"

class FiarArtificialPlayer
{
public:
    FiarArtificialPlayer();

    void setDifficulty(int difficulty);

    int getMove(RowField rowField, int player);


private:
    int difficulty;
};

#endif // FIARARTIFICIALPLAYER_H
