#include "PrimitivesGameScene.h"

#include "TilePrimitivesGraphicsItem.h"

PrimitivesGameScene::PrimitivesGameScene(QObject *parent) :
    GameScene(parent),
    boardTilePen(QBrush(Qt::SolidPattern), 4.0, Qt::SolidLine),
    whiteTokenPen(Qt::black),
    blackTokenPen(Qt::black),
    whiteTokenBrush(Qt::white),
    blackTokenBrush(Qt::black)
{
    whiteTokenPen.setWidth(5.0);
    blackTokenPen.setWidth(3.0);

    tokenPath.addEllipse(QPointF(), tileRadius, tileRadius);

    boardTilePath.addRect(-tileRadius, -tileRadius, 2*tileRadius, 2*tileRadius);

    boardCornerTilePath.moveTo(-tileRadius, -tileRadius/2);
    boardCornerTilePath.lineTo(-tileRadius, tileRadius);
    boardCornerTilePath.lineTo(tileRadius, tileRadius);
    boardCornerTilePath.lineTo(tileRadius, -tileRadius);
    boardCornerTilePath.lineTo(-tileRadius/2, -tileRadius);
    boardCornerTilePath.lineTo(-tileRadius, -tileRadius/2);
}

TileGraphicsItem *PrimitivesGameScene::newBoardTile()
{
    TilePrimitivesGraphicsItem * tile = new TilePrimitivesGraphicsItem();
    tile->setPainterPath(&boardTilePath);
    tile->setPen(&boardTilePen);
    return tile;
}

TileGraphicsItem *PrimitivesGameScene::newBoardCornerTile()
{
    TilePrimitivesGraphicsItem * tile = new TilePrimitivesGraphicsItem();
    tile->setPainterPath(&boardCornerTilePath);
    tile->setPen(&boardTilePen);
    return tile;
}

TileGraphicsItem * PrimitivesGameScene::newToken(const int & player)
{
    TilePrimitivesGraphicsItem * tile = new TilePrimitivesGraphicsItem();
    tile->setPainterPath(&tokenPath);
    tile->setBrush(player==0 ? &whiteTokenBrush : &blackTokenBrush);
    tile->setPen(player==0 ? &whiteTokenPen : &blackTokenPen);
    return tile;
}
