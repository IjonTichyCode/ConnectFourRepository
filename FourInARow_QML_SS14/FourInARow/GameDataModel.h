#ifndef GAMEDATAMODEL_H
#define GAMEDATAMODEL_H

#include <vector>
#include <map>
#include "playerdata.h"
#include "GameSetup.h"
#include "FIARApplicationSetup.h"

using std::vector;
using std::map;

/**
 * @brief The GameDataModel class is an abstraction class between the database and other classes,
 * that need game data. It holds, updates and writes data into C++ like representation,
 * not database like.
 */
class GameDataModel
{
public:
    /**
     * @brief getInstance get the current instance of GameDataModel. If no instance exists,
     * it will be created a the pointer returned.
     * @return
     */
    static GameDataModel * getInstance();
    ~GameDataModel();

    /**
     * @brief init Initially populate this with Data from the backing database
     */
    void init();

    /**
     * @brief getPlayers
     * @return Get a reference to the current map of players.
     */
    map<int, PlayerData> & getPlayers();

    /**
     * @brief getHighscore Get a reference to the current vector of players in the highscore
     * @return
     */
    const vector<PlayerData> & getHighscore() const;

    /**
     * @brief getSavedGames Get a reference to the current vector of saveGames
     * @return
     */
    const vector<GameSetup> & getSavedGames() const;

    /**
     * @brief addPlayer Adds the player to the DataModel (updating the Database as well).
     * Returns the (new) playerId of this player.
     * @param player Reference to the player to add
     * @return
     */
    int addPlayer(PlayerData &player);

    /**
     * @brief updatePlayer Updates the playerData with the passed PlayerData object.
     * @param playerId
     */
    void updatePlayer(const PlayerData & playerData);

    /**
     * @brief saveGame save the current game to the Database. Adds a gameId to gameSetup if neccessary.
     * Will overwrite old record of this game, if existing
     * @param gameSetup
     */
    void saveGame(GameSetup & gameSetup);

    /**
     * @brief loadGame Load the game with the passed id and return a reference to the GameSetup
     * @param gameId
     * @return
     */
    GameSetup & loadGame(int gameId);

    /**
     * @brief getGameSetup Get a reference to the gameSetup of the current game
     * @return
     */
    GameSetup & getGameSetup();

    /**
     * @brief newGameSetup create a new GameSetup for a new Game
     * @return reference to the new Game Setup
     */
    GameSetup & newGameSetup();

    /**
     * @brief getAppSetup Get a reference to appSetup of this application
     * @return
     */
    FIARApplicationSetup & getAppSetup();

    /**
     * @brief saveAppSetup Save the current state of the appSetup to the database
     */
    void saveAppSetup();

private:

    /**
     * @brief GameDataModel private constructor to ensure that always only one instance
     * of GameDataModel exists.
     */
    GameDataModel();

    static GameDataModel * instance;

    map<int, PlayerData> players;
    vector<PlayerData> highscore;
    vector<GameSetup> games;
    GameSetup gameSetup;
    FIARApplicationSetup appSetup;
};

#endif // GAMEDATAMODEL_H
