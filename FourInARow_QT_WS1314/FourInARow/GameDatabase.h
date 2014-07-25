#ifndef GAMEDATABASE_H
#define GAMEDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegExp>

#include "NewGameSetup.h"

/**
 * @brief The GameDatabase class encapsulates all necessary Queries
 * to an SQLLite Database. It ensures, that other classes don´t need
 * to manipulate or query data directly on the database.
 */
class GameDatabase : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief GameDatabase sets up the connection to the local gameDatabase
     * @param parent
     */
    explicit GameDatabase(QObject * parent = 0);

    ~GameDatabase();

    /**
     * @brief getDatabase returns a pointer to the encapsulated database.
     * Should only be used for debugging purpose only.
     * @return
     */
    QSqlDatabase * getDatabase();

    /** Returns a pointer to a query with the results needed to setup the selectable players.
     * @brief getPlayers pointer to a query containing player data.
     * @return
     */
    QSqlQuery * getPlayers();

    /**
     * @brief getHighscor Writes Highscore data into a passed QSqlQueryModel
     * @param model Pointer to a QSqlQueryModel to be populated with Highscore data.
     * May not be NULL.
     */
    void getHighscore(QSqlQueryModel * model);

    /**
     * @brief getSavedGames Writes saved games data into a passed QSqlQueryModel. Will not contain games
     * that are already finished. Only games that can be continued.
     * @param model Pointer to a QSqlQueryModel to be populated with saved games data.
     * May not be NULL.
     */
    void getSavedGames(QSqlQueryModel * model);

    /**
     * @brief loadGame populates the passed gameSetup with data referring to the passed gameIndex.
     * @param gameIndex Index of game (key in the database)
     * @param gameSetup pointer to a GameSetup object to be populated with game data
     */
    void loadGame(int gameIndex, NewGameSetup * gameSetup);

    /**
     * @brief saveGame Saves relevant data hold in gameSetup. Each saveGame creates a new record in the database.
     * Continued games aren´t overwritten.
     * @param gameSetup gameSetup cotaining data to be stored to the database
     */
    void saveGame(NewGameSetup * gameSetup);

    /**
     * @brief addPlayer Adds a player to the database
     * @param name Name of the player (CPU tag is removed automatically)
     * @param isCpu Is this player a CPU player
     * @param level Level, if it is a CPU player
     */
    void addPlayer(const QString & name, bool isCpu, int level);

private:

    QSqlDatabase database;
    const QString querySavedGames;
    const QString queryHighscore;
    // Regular expression identifying a CPU player Tag
    const QRegExp cpuRegExp;
};

#endif // GAMEDATABASE_H
