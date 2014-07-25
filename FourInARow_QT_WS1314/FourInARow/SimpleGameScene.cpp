#include "SimpleGameScene.h"
#include <QPainter>

#include "TilePixmapGraphicsItem.h"


SimpleGameScene::SimpleGameScene(QObject *parent) :
    GameScene(parent),
    whiteTokenPix("whiteToken.png"),
    blackTokenPix("blackToken.png"),
    boardTilePix("boardTile.png"),
    boardCornerTilePix("boardCornerTile.png")
{
}

SimpleGameScene::~SimpleGameScene()
{

}

TileGraphicsItem *SimpleGameScene::newBoardTile()
{
   TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
   tile->setPixmap(&boardTilePix);
   return tile;
}

TileGraphicsItem *SimpleGameScene::newBoardCornerTile()
{
    TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
    tile->setPixmap(&boardCornerTilePix);
    return tile;
}

TileGraphicsItem * SimpleGameScene::newToken(const int & player)
{
    TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
    tile->setPixmap(player==0 ? &whiteTokenPix : &blackTokenPix);
    return tile;
}
