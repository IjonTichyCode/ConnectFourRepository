#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <string>
using std::string;

/**
 * @brief The NewGameSetup class is a data structure representing the setup
 * statistics data of a game. A game can be completely reconstructed by this data.
 */
class GameSetup
{
public:

    GameSetup();

    int gameId;
    // name of player0 (including the CPU player tag, if exists
    string player0;
    // id (database) of player0
    int player0Id;
    // name of player1 (including the CPU player tag, if exists
    string player1;
    // id (database) of player0
    int player1Id;
    // string of numbers representing the columns where tokens have fallen in
    string moveHistory;

    int startPlayer;
    int finished;
    // number of moves
    int moves;

    bool isCpu[2];
    int level[2];

    int columns;
    int rows;

    float time;
    int maxTime;
    bool useTimer;
};


#endif // GAMESETUP_H
