#ifndef QMLPLAYSCREEN_H
#define QMLPLAYSCREEN_H

#include <QQuickItem>
#include "FIARNetworkGame.h"
#include "FiarGameListener.h"

/**
 * @brief The QMLPlayScreen class is a QQuickItem which is mapped to the PlayScreen QML Type.
 * On the PlayScreen the actual game takes place. So this receives the actions of human players from the GUI
 * and tells changes in the game to the GUI to represent them visually.
 */
class QMLPlayScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLPlayScreen(QQuickItem *parent = 0);

    ~QMLPlayScreen();

    // following 6 methods are used to tell the GUI that a specified event in the game has occured.
    // thesse will usually be called by the GameListener
    /**
     * @brief gameTokenAdded Specified token has been added to the game
     * @param player
     * @param column
     * @param row
     */
    void gameTokenAdded(int player, int column, int row);

    /**
     * @brief gamePlayersTurn The player to make the next turn has changed.
     * @param player
     */
    void gamePlayersTurn(int player, int time);

    /**
     * @brief gamePlayerWon The specified player has won the game with the specified tokens
     * @param player
     * @param columns
     * @param rows
     */
    void gamePlayerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3);

    /**
     * @brief gameEndedDrawn The game ended with a tie
     */
    void gameEndedDrawn();

    /**
     * @brief gameTriedIllegalColumn A illegal column has been tried
     * @param player
     * @param column
     */
    void gameTriedIllegalColumn(int player, int column);

    /**
     * @brief gameTriedFullColumn An already full column has been tried
     * @param player
     * @param column
     */
    void gameTriedFullColumn(int player, int column);


signals:

    /*****signals emitted by the game logic************/

    /**
     * @brief newInteractiveToken signals to the GUI to create a new token for the current player to interact with
     * @param player the player, who owns this token
     * @param isCpu whether the player is cpu controlled (in this case the token is obviously not interactive)
     */
    void newInteractiveToken(int player, bool isCpu);

    /**
     * @brief dropToken signals to the GUI, that a the interactive token is
     * dropped into specified board position
     * @param column
     * @param row
     */
    void dropToken(int column, int row);

    /**
     * @brief setupToken signals to the GUI, that a new token should be created
     * on the board at the specified board position
     * @param column
     * @param row
     */
    void setupToken(int player, int column, int row);

    /**
     * @brief rejectToken signals to the GUI, that the last move tried, is rejected (illegal)
     */
    void rejectMove();

    /**
     * @brief playerWon Signals to the GUI that the specified player has won. col0, row0,...,col3,row3
     * are pairs of token positions which represent the winning row.
     * @param player
     * @param col0
     * @param row0
     * @param col1
     * @param row1
     * @param col2
     * @param row2
     * @param col3
     * @param row3
     */
    void playerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3);

    /**
     * @brief tie Signals to the GUI, that the game ended as a tie
     */
    void tie();

    /**
     * @brief gameSaved emit when, game has been succesfully saved
     */
    void gameSaved();

    /**
     * @brief setStatusMessage Set a status message on the PlayScreen like PlayerXs turn
     * @param message
     */
    void setStatusMessage(QString message);

    /**
     * @brief highscoreChanged signals to the gui that the highscore has changed
     */
    void highscoreChanged();

    /**
     * @brief clear Reset the whole visual representation (empty game board)
     */
    void clear();

    /**
     * @brief setTimer Set the countdown timer, that is shown to the player
     * @param time
     */
    void setTimer(int time);


public slots:

    /******** slots to pipe signals into non QT C++ code ********/
    /**
     * @brief makeMove provides a slot to the GUI to make a move on the game. The user tries
     * to drop a token into specified column.
     * @param column
     */
    void makeMove(int column, int time);

    /**
     * @brief persistGame This will persist the current game.
     * This will save the current game, if it hasn´t finished yet.
     * Will overwrite older saved games of the same game.
     */
    void saveGame(int time);

    /**
     * @brief Updates the playScreen with the current loaded game
     * @param id
     */
    void showGame();

    /**
     * @brief startLoadGame slot called from the GUI, when gameloading starts
     */
    void startLoadGame();

    /**
     * @brief endLoadGame slot called from the GUI, when gameload is finished
     */
    void endLoadGame();

    /**
     * @brief timerExpired slot called from the GUI, when the timer of the current player is expired
     */
    void timerExpired();

private:
    FiarGameListener * gameListener;
    bool loadGameFlag;
};

#endif // QMLPLAYSCREEN_H
