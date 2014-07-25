#ifndef TILESVGGRAPHICSITEM_H
#define TILESVGGRAPHICSITEM_H

#include <QSvgRenderer>

#include "tilegraphicsitem.h"

/**
 * @brief The TileSvgGraphicsItem class implements the TileGraphicsItem class using QSvgRenderer objects
 * to draw into the bounding square.
 */
class TileSvgGraphicsItem : public TileGraphicsItem
{
    Q_OBJECT
public:
    explicit TileSvgGraphicsItem(QGraphicsItem *parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /**
     * @brief setRenderer Sets up the renderer used to draw onto the bounding square.
     * @param renderer
     */
    void setRenderer(QSvgRenderer * renderer);

private:
    QSvgRenderer * renderer;
};

#endif // TILESVGGRAPHICSITEM_H
