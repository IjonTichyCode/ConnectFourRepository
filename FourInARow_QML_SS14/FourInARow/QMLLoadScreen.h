#ifndef QMLLOADSCREEN_H
#define QMLLOADSCREEN_H

#include <QQuickItem>

/**
 * @brief The QMLLoadScreen class is a QQuickItem which is mapped to the LoadScreen QML Type.
 * It shows all games available to load. The C++ Class provides the required data to show on the QML Type.
 */
class QMLLoadScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLLoadScreen(QQuickItem *parent = 0);

signals:

    /**
     * @brief addEntry Add a save game to the LoadScreen
     * @param player0 The name of the first player
     * @param player1 The name of the second player
     * @param index The gameId of the game
     */
    void addEntry(QString player0, QString player1, int index);

    /**
     * @brief clear Delete all games from the loadScreen
     */
    void clear();

    /**
     * @brief startLoadGame Indicate to the GUI that a game loading is in progress
     * This is necessary to prevent the GUI from animating a game, while only loading is in progress.
     */
    void startLoadGame();

    /**
     * @brief endLoadGame Tell the GUI that a game has been loaded completely and the interactive game can start now.
     */
    void endLoadGame();

    /**
     * @brief setBoardDimension Set the dimension of the current game board.
     * @param columns Number of columns
     * @param rows Number of rows
     */
    void setBoardDimension(int columns, int rows);

public slots:

    /**
     * @brief loadGame Slot the GUI can call to start loading a game of the passed index
     * @param index
     */
    void loadGame(int index);

    /**
     * @brief loadLatestGame
     */
    void loadLatestGame();

    /**
     * @brief populate populates the GUI with saved games from the GameDataModel
     */
    void populate();

};

#endif // QMLLOADSCREEN_H
