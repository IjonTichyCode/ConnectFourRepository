#ifndef TILEBOARDCORNERGRAPHICSITEM_H
#define TILEBOARDCORNERGRAPHICSITEM_H

#include <QPainterPath>
#include <QBrush>

#include "tilegraphicsitem.h"

/**
 * @brief The TilePrimitivesGraphicsItem class implements the TileGraphicsItem class painting
 * QPainterPath objects into its bounding square.
 */
class TilePrimitivesGraphicsItem : public TileGraphicsItem
{
    Q_OBJECT
public:
    explicit TilePrimitivesGraphicsItem(QGraphicsItem *parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /**
     * @brief setPainterPath Set up the painterPath used to draw onto the bounding square.
     * @param painterPath
     */
    virtual void setPainterPath(QPainterPath * painterPath);

    /**
     * @brief setPen Set up the Pen used to draw onto the bounding square.
     * @param pen
     */
    virtual void setPen(QPen * pen);

    /**
     * @brief setBrush Set up the brush used to draw onto the bounding square.
     * @param brush
     */
    virtual void setBrush(QBrush * brush);

private:
    QPen * pen;
    QPainterPath * painterPath;
    QBrush * brush;

};

#endif //TILEBOARDCORNERGRAPHICSITEM_H
