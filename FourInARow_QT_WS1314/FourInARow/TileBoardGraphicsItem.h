#ifndef TILEBOARDGRAPHICSITEM_H
#define TILEBOARDGRAPHICSITEM_H

#include <QPen>

#include "tilegraphicsitem.h"

/**
 * @brief The TileBoardGraphicsItem class
 */
class TileBoardGraphicsItem : public TileGraphicsItem
{
    Q_OBJECT
public:
    explicit TileBoardGraphicsItem(QGraphicsItem *parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

protected:
    static const QPen PEN;
};

#endif // TILEBOARDGRAPHICSITEM_H
