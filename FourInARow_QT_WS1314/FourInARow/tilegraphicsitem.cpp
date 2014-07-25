#include "tilegraphicsitem.h"


TileGraphicsItem::TileGraphicsItem(QGraphicsItem *parent):
    QGraphicsObject(parent),
    boundingBox(-50, -50, 100, 100)
{
}

QRectF TileGraphicsItem::boundingRect() const {
    return boundingBox;
}

void TileGraphicsItem::setRadius(const float & radius)
{
    boundingBox = QRect(-radius, -radius, 2*radius, 2*radius);
}

void TileGraphicsItem::setYPos(int yPos)
{
    this->yPos = yPos;
    setPos(this->pos().x(), yPos);
}

int TileGraphicsItem::getYPos() const
{
    return yPos;
}

void TileGraphicsItem::setXPos(int xPos)
{
    this->xPos = xPos;
    setPos(xPos, this->pos().y());
}

int TileGraphicsItem::getXPos() const
{
    return xPos;
}
