#ifndef SVGGAMESCENE_H
#define SVGGAMESCENE_H

#include <QSvgRenderer>

#include "GameScene.h"

/**
 * @brief The SvgGameScene class implements the GameScene class
 * with Tiles that are drawn by QSvgRenderer objects.
 * External .svg files are used.
 */
class SvgGameScene : public GameScene
{
    Q_OBJECT
public:
    explicit SvgGameScene(QObject *parent = 0);

protected:
    virtual TileGraphicsItem * newBoardTile();
    virtual TileGraphicsItem * newBoardCornerTile();
    virtual TileGraphicsItem * newToken(const int & player);

private:

    // rederers are reused for each tile
    QSvgRenderer whiteTokenRenderer;
    QSvgRenderer blackTokenRenderer;
    QSvgRenderer boardTileRenderer;
    QSvgRenderer boardCornerTileRenderer;
};

#endif // SVGGAMESCENE_H
