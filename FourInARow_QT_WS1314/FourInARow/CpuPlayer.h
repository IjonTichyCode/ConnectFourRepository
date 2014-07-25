#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "fourinarowgame.h"

/**
 * @brief The CpuPlayer class provides artifical intelligence
 * for the FourInTheRow Game.
 */
class CpuPlayer
{
public:
    CpuPlayer();

    /**
     * @brief getCpuMove The CpuPlayer selects a column to
     * put a token into based on the game passed to the method
     * @param game The game the CPUPlayers move is based on.
     * @return
     */
    int getCpuMove(FourInARowGame &game);

    /**
     * @brief setLevel Sets  the difficulty of the player. Higher Level means a better player
     * @param level CPU player´s difficulty level
     */
    void setLevel(int level);

private:
    int level;
};

#endif // CPUPLAYER_H
