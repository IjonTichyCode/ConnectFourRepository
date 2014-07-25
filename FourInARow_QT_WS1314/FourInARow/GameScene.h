#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QVector>
#include <QSoundEffect>

#include "tilegraphicsitem.h"
#include "fourinarowboard.h"
#include "tokenfallsound.h"
#include "TileSvgGraphicsItem.h"

/**
 * @brief The GameScene class is an abstract class used to show a FourInARowBoard.
 * It have to be extended to define the exact design of the tokens and the board.
 * Methods to add tokens and show game results are already implemented.
 * The board and the tokens are represented by TileGraphicsItem objects of square shape.
 * The board is build up by column*row board tiles.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);

    ~GameScene();

    /**
     * @brief setBoard Setup the Connect Four game board, this scene is representing.
     * @param board
     */
    virtual void setBoard(FourInARowBoard * board);

    /**
     * @brief addToken Adds a token to the scene
     * @param player Player [0,1], who played the token
     * @param x column where the token should fall in
     * @param y row where the token should
     */
    virtual void addToken(const int & player, const int & x, const int & y);

    /**
     * @brief setupNextToken creates a token of the player, who is next.
     * This token hovers over the board to show the column it will fall in, when
     * it will be added to the board.
     * @param column
     */
    virtual void setupNextToken(int column);

    /**
     * @brief playerWins creates animation and sound effects to indicate a win
     * @param player The player, who won.
     * @param winRow Array of column,row pairs of the winning row tokens
     */
    virtual void playerWins(int player, int * winRow);

    /**
     * @brief tie creates animation and sound effects to indicate a tie
     */
    virtual void tie();

    /**
     * @brief failToken creates animation and sound effects to indicate trying an invalid move.
     * @param player who tried the invalid move
     * @param x column of the invalid move
     * @param y row of the invalid move
     */
    virtual void failToken(const int & player, const int & x, const int & y);

    /**
     * @brief selectColumn Lets the selector token hover on top of the selected column
     * @param column to select
     */
    virtual void selectColumn(int column);

    /**
     * @brief calcScale calculates the scale of the scene. The scene has its own size in pixels.
     * The scale is calculated in relation to the passed size
     * @param size of the viewport used to show this scene
     * @return
     */
    virtual qreal calcScale(QSizeF size);

    /** Toggles sound on or off.
     * @brief toggleSound
     * @param state
     */
    void toggleSound(bool state);


protected:
    /**
     * @brief newBoardTile is an abstract method, which creates a TileGraphicsItem, painting a new board tile.
     * @return
     */
    virtual TileGraphicsItem * newBoardTile() = 0;

    /**
     * @brief newBoardCornerTile is an abstract method, which creates a TileGraphicsItem, painting a new board tile
     * positioned at the top left corner of the board. The Tile is rotated automatically for the other corners.
     * @return
     */
    virtual TileGraphicsItem * newBoardCornerTile() = 0;

    /**
     * @brief newToken is an abstract method, which creates a TileGraphicsItem, painting a new token tile.
     * @param player player owning the tile [0,1]
     * @return
     */
    virtual TileGraphicsItem * newToken(const int & player) = 0;

    QVector<TileGraphicsItem*> whiteTokens;
    QVector<TileGraphicsItem*> blackTokens;
    QVector<TileGraphicsItem*> boardTiles;
    QVector<TileGraphicsItem*> boardCornerTiles;

    // used to indicate the selected column
    TileGraphicsItem * nextToken;

    FourInARowBoard * board;

    // radius of each tile in pixels boundingbox is (-r,-r,r,r)
    const float tileRadius;

private:
    /**
     * @brief newTieAnimationToken creates a Token used to indicate a tie.
     * @param player
     * @return
     */
    virtual TileGraphicsItem * newTieAnimationToken(int player);

    /**
     * @brief newWinAnimationToken creates a token used to indicate a win
     * @param player
     * @return
     */
    virtual TileGraphicsItem * newWinAnimationToken(int player);

    bool playSound;

    QSoundEffect * bounceEffect0;
    QSoundEffect * bounceEffect1;
    QSoundEffect * slideEffect0;
    QSoundEffect * slideEffect1;
    QSoundEffect * winSound;
    QSoundEffect * tieSound;
    QSoundEffect * invalidMoveSound;

    QSvgRenderer whiteTokenWinRenderer;
    QSvgRenderer blackTokenWinRenderer;
    QSvgRenderer whiteTokenTieRenderer;
    QSvgRenderer blackTokenTieRenderer;


};

#endif // GAMESCENE_H
