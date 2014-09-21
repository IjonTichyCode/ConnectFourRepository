#ifndef FIARNETWORKGAME_H
#define FIARNETWORKGAME_H

#include <random>

#include "fourinarowgame.h"
#include "FiarArtificialPlayer.h"

enum PlayerTypeTag {
    LOCAL,
    REMOTE,
    CPU
};

/**
  Extends the FourInARowGame implementing a method to receive moves from different types of players:
  remote, cpu or local.
  The base class only implements the logic of playing a game. This class is aware of the different actors.
  The [remote interface], the (local) GUI and the AI can call methods on objects of this class.
  In Addition this Game knows the move timer, which the Base implementation don´t know.
 * @brief The FIARNetworkGame class
 */
class FIARNetworkGame : public FourInARowGame
{
public:

    /**
     * @brief FIARNetworkGame Construct a new FIARNetworkGame object of standard size (7x6)
     * @param startPlayer
     */
    FIARNetworkGame(int startPlayer = 0);

    FIARNetworkGame(int startPlayer, int columns, int rows);

    /**
     * @brief move tries to put a token into a column on the board.
     * Column indices start with 0 for the left most column.
     * playerTypeTag identifies which type of player is trying to make the move
     * (network, local or cpu).
     * The game FIARNetworkGame knows, which type of player is allowed to do the next move and will reject
     * illegal players.
     *
     * @param column column index
     * @param playerTypeTag - defines which type of player makes the move
     * @param time The time this player has left on his/her timer.
     * If 0 and a timer is used a random turn instead of the specified will be made
     * @return moveresult - feedback about the move.
     * Only the return code SUCCESS changes the player to move next.
     */
    MoveResult move(int column, PlayerTypeTag playerTypeTag, int time);

    /**
     * @brief setupPlayerTypes define the players of this game. (remote, local, cpu)
     * @param playerTypeTag0
     * @param playerTypeTag1
     */
    void setupPlayerTypes(int playerTypeTag0, int playerTypeTag1);

private:
    MoveResult randomMove(int & column);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> randomizer;
    FiarArtificialPlayer aiPlayer;

};

#endif // FIARNETWORKGAME_H
