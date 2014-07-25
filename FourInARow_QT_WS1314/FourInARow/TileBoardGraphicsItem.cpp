#include "TileBoardGraphicsItem.h"
#include <QBrush>

const QPen TileBoardGraphicsItem::PEN(QBrush(Qt::SolidPattern), 4.0, Qt::SolidLine);

TileBoardGraphicsItem::TileBoardGraphicsItem(QGraphicsItem *parent) :
    TileGraphicsItem(parent)
{
}

void TileBoardGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(PEN);
    painter->drawRect(boundingBox);
}
