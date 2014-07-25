#ifndef TILEPIXMAPGRAPHICSITEM_H
#define TILEPIXMAPGRAPHICSITEM_H

#include "tilegraphicsitem.h"

/**
 * @brief The TilePixmapGraphicsItem class implements the TileGraphicsItem class painting
 * pixmaps into its bounding square.
 */
class TilePixmapGraphicsItem : public TileGraphicsItem
{
    Q_OBJECT
public:
    explicit TilePixmapGraphicsItem(QGraphicsItem *parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /**
     * @brief setPixmap Setup a pointer to the pixmap drawn into the bounding square.
     * @param pixmap
     */
    void setPixmap(QPixmap * pixmap);

private:
    QPixmap * pixmap;
};

#endif // TILEPIXMAPGRAPHICSITEM_H
