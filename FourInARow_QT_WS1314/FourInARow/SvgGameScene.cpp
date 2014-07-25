#include "SvgGameScene.h"
#include <QPainter>

#include "TileSvgGraphicsItem.h"

SvgGameScene::SvgGameScene(QObject *parent) :
    GameScene(parent),
    whiteTokenRenderer(QString("whiteToken.svg")),
    blackTokenRenderer(QString("blackToken.svg")),
    boardCornerTileRenderer(QString("boardTile.svg")),
    boardTileRenderer(QString("boardTile.svg"))
{
}

TileGraphicsItem * SvgGameScene::newBoardTile()
{
   TileSvgGraphicsItem * tile = new TileSvgGraphicsItem();
   tile->setRenderer(&boardTileRenderer);
   return tile;
}

TileGraphicsItem * SvgGameScene::newBoardCornerTile()
{
    TileSvgGraphicsItem * tile = new TileSvgGraphicsItem();
    tile->setRenderer(&boardCornerTileRenderer);
    return tile;
}

TileGraphicsItem * SvgGameScene::newToken(const int & player)
{
    TileSvgGraphicsItem * tile = new TileSvgGraphicsItem();
    tile->setRenderer(player==0 ? &whiteTokenRenderer : &blackTokenRenderer);
    return tile;
}
