#ifndef QMLNEWGAMESCREEN_H
#define QMLNEWGAMESCREEN_H

#include <QQuickItem>

/**
 * @brief The QMLNewGameScreen class is a QQuickItem which is mapped to the NewGameScreen QML Type.
 * The NewGameScreen configures and starts new games.
 */
class QMLNewGameScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLNewGameScreen(QQuickItem *parent = 0);

signals:

    /**
     * @brief addEntry Adds a player to the list of selectable players of the GUI
     * @param playerIndex
     * @param player Players name
     * @param isCpu true if it is an artificial player
     * @param level level of the artificial player (irrelevant, if not aritificial)
     */
    void addEntry(int playerIndex, QString player, bool isCpu, int level);

    /**
     * @brief clear signals to the GUI to clear the player lists
     */
    void clear();

    /**
     * @brief newPlayerAdded emit after new player has been succesfully added
     */
    void newPlayerAdded();

    /**
     * @brief selectPlayers This is called once on the GUI to set the last selected players
     * in to the player selection on the newGameScreen
     * @param player0Id id of the first player
     * @param player1Id id of the second player
     */
    void selectPlayers(int player0Id, int player1Id);

    /**
     * @brief setBoardSizeOption This is called once on the GUI to set the last selected board size
     * @param columns
     * @param rows
     */
    void setBoardSizeOption(int columns, int rows);

    /**
     * @brief setTimerOption This is called once on the GUI to set the last selected timer options
     * @param useTimer
     * @param maxTime
     */
    void setTimerOption(bool useTimer, int maxTime);

public slots:
    void populate();

    /**
     * @brief addNewPlayer slot called by the gui when a new player should be added
     * @param name new name
     * @param isCpu
     * @param level
     */
    void addNewPlayer(QString name, bool isCpu, int level); 

    /**
     * @brief setupNewGame This is called by the gui before a new GameSetup is configured
     */
    void setupNewGame();

    /**
     * @brief setTimer Sets the timer options on the new game
     * @param useTimer
     * @param time
     */
    void setTimer(bool useTimer, int time);

    /**
     * @brief setPlayers Defines the players on the new game
     * @param player0Id
     * @param player1Id
     */
    void setPlayers(int player0Id, int player1Id);

    /**
     * @brief setBoardSize slot defines the size of the board  of the new game
     * @param columns
     * @param rows
     */
    void setBoardSize(int columns, int rows);

    /**
     * @brief startGame Slot is called after a new game has been configured completely.
     * Indicate to the game logic, that the new game can start
     */
    void startGame();

    /**
     * @brief qmlComponentCompleted This is called, when mapped QML Type has been completed.
     * After that the application options can be set on the NewGameScreen QML Type.
     */
    void qmlComponentCompleted();
};

#endif // QMLNEWGAMESCREEN_H
