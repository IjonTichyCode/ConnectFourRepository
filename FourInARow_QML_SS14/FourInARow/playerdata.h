#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>
using std::string;

/**
 * @brief The PlayerData struct stores all relevant data about a player.
 */
struct PlayerData
{
    PlayerData();

    int index;
    string name;
    bool isCpu;
    int level;

    double wins;
    double losses;
    double ties;

};

#endif // PLAYERDATA_H
