#include "TilePixmapGraphicsItem.h"

TilePixmapGraphicsItem::TilePixmapGraphicsItem(QGraphicsItem * parent) :
    TileGraphicsItem(parent)
{
}

void TilePixmapGraphicsItem::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (pixmap) {
       painter->drawPixmap( boundingBox , *pixmap );
    }
}

void TilePixmapGraphicsItem::setPixmap(QPixmap * pixmap) {
    this->pixmap = pixmap;
}
