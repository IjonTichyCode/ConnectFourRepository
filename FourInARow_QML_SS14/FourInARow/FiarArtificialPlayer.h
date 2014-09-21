#ifndef FIARARTIFICIALPLAYER_H
#define FIARARTIFICIALPLAYER_H

//#include <random>
#include "rowfield.h"
#include "fourinarowgame.h"

/**
 * @brief The FiarArtificialPlayer class implements an artificial player, who
 * is able to select a move on a FourInARowGame.
 */
class FiarArtificialPlayer
{
public:
    FiarArtificialPlayer();
    ~FiarArtificialPlayer();


    /**
     * @brief setDifficulty Sets the difficulty, or from the Artificial Players point of view
     * the smartness of this player. Higher difficulty means, that the recursive algorithm will
     * search deeper.
     * @param difficulty
     */
    void setDifficulty(int difficulty);

    /**
     * @brief getMove Select a move on a FourInARowGame.
     * It may cause errors, if no move is possible on the game
     * @param game The game the AI should evaluate
     * @param player The player who makes the move (0,1)
     * @return
     */
    int getMove(const FourInARowGame & game, int player);

private:

    /**
     * @brief recursiveValue Recursive method to evaluate a move on the game. The value
     * is used to select an appropriate move.
     * @param column The column, where the token is placed
     * @param depth The depths of the recursive invokation of this method. On 0 it will not search any deeper.
     * @return
     */
    float recursiveValue(int column, int depth);

    int difficulty;

    FourInARowGame * game;
    RowField * rowField;
    int maxColumn;
    float columns;
    float treeDepthPenalty;
    float winMultiplier;
    bool allowedColumns[9];

//    std::default_random_engine generator;
};

#endif // FIARARTIFICIALPLAYER_H
