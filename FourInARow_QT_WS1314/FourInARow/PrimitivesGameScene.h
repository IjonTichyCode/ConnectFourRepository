#ifndef PRIMITIVESGAMESCENE_H
#define PRIMITIVESGAMESCENE_H

#include <QPainterPath>

#include "GameScene.h"

/**
 * @brief The PrimitivesGameScene class implements the GameScene class
 * with Tiles that are drawn by QPainterPath objects.
 * No external resources are used to draw the tiles.
 */
class PrimitivesGameScene : public GameScene
{
    Q_OBJECT
public:
    explicit PrimitivesGameScene(QObject *parent = 0);

protected:
    virtual TileGraphicsItem * newBoardTile();
    virtual TileGraphicsItem * newBoardCornerTile();
    virtual TileGraphicsItem * newToken(const int & player);

private:
    // paths, pens and brushes are reused for each tile
    QPainterPath tokenPath;
    QPainterPath boardTilePath;
    QPainterPath boardCornerTilePath;


    QPen whiteTokenPen;
    QPen blackTokenPen;
    QPen boardTilePen;

    QBrush whiteTokenBrush;
    QBrush blackTokenBrush;
};

#endif // PRIMITIVESGAMESCENE_H
