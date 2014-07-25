#ifndef QMLPLAYSCREEN_H
#define QMLPLAYSCREEN_H

#include <QQuickItem>
#include "fourinarowgame.h"

class QMLPlayScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLPlayScreen(QQuickItem *parent = 0);

signals:

    /******** signals emitted by GUI ***********/

    /**
     * @brief makeMove signals this object, that the user tries
     * to drop a token into specified column
     * @param column
     */
    void makeMove(int column);



    /*****signals emitted by thegame logic************/

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


public slots:

    /******** slots to pipe signals into non QT C++ code ********/
    void receiveMove(int column);

private:
    FourInARowGame game;

};

#endif // QMLPLAYSCREEN_H
