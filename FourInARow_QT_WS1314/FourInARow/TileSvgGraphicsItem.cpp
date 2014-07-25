#include "TileSvgGraphicsItem.h"

TileSvgGraphicsItem::TileSvgGraphicsItem(QGraphicsItem * parent) :
    TileGraphicsItem(parent),
    renderer(NULL)
{
}

void TileSvgGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    renderer->render(painter, boundingBox);
}

void TileSvgGraphicsItem::setRenderer(QSvgRenderer *renderer)
{
    this->renderer = renderer;
}
