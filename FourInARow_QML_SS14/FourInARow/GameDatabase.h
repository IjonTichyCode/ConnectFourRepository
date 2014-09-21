#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QRegExp>
#include <vector>
#include <map>

#include "GameSetup.h"
#include "playerdata.h"
#include "FIARApplicationSetup.h"

using std::vector;
using std::map;

/**
 * @brief The GameDatabase class encapsulates all necessary Queries
 * to an SQLLite Database. It ensures, that other classes don´t need
 * to manipulate or query data directly on the database.
 */
class GameDatabase : public QObject
{
    Q_OBJECT
public:


    static GameDatabase * getInstance();
    /**
     * @brief GameDatabase sets up the connection to the local gameDatabase
     * @param parent
     */    

    ~GameDatabase();

    /**
     * @brief getDatabase returns a pointer to the encapsulated database.
     * Should only be used for debugging purpose only.
     * @return
     */
    QSqlDatabase * getDatabase();

    /**
     * @brief getPlayers populates the passed map<int, PlayerData> with all players from the database
     * @param players reference to the map to populate
     */
    void getPlayers(map<int, PlayerData> & players) const;

    /**
     * @brief getHighscore populates the passed vector<PlayerData> with all players from the database
     * ordered by their win/loss ratio
     * @param highscore reference to the vector to populate
     * May not be NULL.
     */
    void getHighscore(vector<PlayerData> & highscore);

    /**
     * @brief getSavedGames populats the passed vector with saved games from the database
     * @param games reference to the vector to populate
     */
    void getSavedGames(vector<GameSetup> & games);

    /**
     * @brief loadGame populates the passed gameSetup with data referring to the passed gameIndex.
     * @param gameIndex Index of game (key in the database)
     * @param gameSetup pointer to a GameSetup object to be populated with game data
     */
    void loadGame( GameSetup & gameSetup);

    /**
     * @brief saveGame Saves relevant data hold in gameSetup. If the game already has been saved yet,
     * it will be overwritten. Else it gets an gameId, which identifies the game.
     * @param gameSetup gameSetup cotaining data to be stored to the database
     */
    void saveGame(GameSetup &gameSetup);

    /**
     * @brief addPlayer Adds a player to the database
     * @param name Name of the player (CPU tag is removed automatically)
     * @param isCpu Is this player a CPU player
     * @param level Level, if it is a CPU player
     * @return The (new) id of this player
     */
    int addPlayer(const string &name, bool isCpu, int level);

    /**
     * @brief updatePlayer Updates the player in the database
     * @param playerData
     */
    void updatePlayer(const PlayerData & playerData);

    /**
     * @brief getAppSetup populates the passed FIARApplicationSetup with
     * data from the database
     * @param appSetup reference to the FIARApplicationSetup object to populate
     */
    void getAppSetup(FIARApplicationSetup & appSetup);

    /**
     * @brief saveAppSetup saves the passed appSetup to the database
     * @param appSetup
     */
    void saveAppSetup(FIARApplicationSetup & appSetup);

private:

    GameDatabase(QObject * parent = 0);
    static GameDatabase * databaseInstance;

    QSqlDatabase database;
    const QString querySavedGames;
    const QString queryHighscore;
    // Regular expression identifying a CPU player Tag
    const QRegExp cpuRegExp;
};

#endif // GAMEDATABASE_H
