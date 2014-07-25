#include "TilePrimitivesGraphicsItem.h"
#include <QBrush>

TilePrimitivesGraphicsItem::TilePrimitivesGraphicsItem(QGraphicsItem *parent) :
    TileGraphicsItem(parent),
    brush(NULL)
{

}

void TilePrimitivesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(*pen);
    if (brush) painter->setBrush(*brush);
    painter->drawPath(*painterPath);
}

void TilePrimitivesGraphicsItem::setPainterPath(QPainterPath *painterPath)
{
    this->painterPath = painterPath;
}

void TilePrimitivesGraphicsItem::setPen(QPen *pen)
{
    this->pen = pen;
}

void TilePrimitivesGraphicsItem::setBrush(QBrush * brush)
{
    this->brush = brush;
}
