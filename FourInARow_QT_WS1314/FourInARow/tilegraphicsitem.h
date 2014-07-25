#ifndef TILEGRAPHICSITEM_H
#define TILEGRAPHICSITEM_H

#include <QGraphicsObject>
#include <QPainter>

/**
 * @brief The TileGraphicsItem class is an abstract QGraphicsObject, that can be extended
 * to draw tiles of the Connect Four game. The tiles geometry is squared and set up by the setRadius method.
 * It has properties for x and y position, which can be used to setup animations on the item.
 */
class TileGraphicsItem : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(int yPos READ getYPos WRITE setYPos)
    Q_PROPERTY(int xPos READ getXPos WRITE setXPos)

public:
    explicit TileGraphicsItem(QGraphicsItem  *parent = 0);

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) = 0;

    virtual QRectF boundingRect() const;

    /**
     * @brief setRadius Sets the radius of the bounding Square of this item
     * @param radius (halb of the bounding square edge)
     */
    virtual void setRadius(const float & radius);

    void setYPos(int yPos);
    int getYPos() const;

    void setXPos(int xPos);
    int getXPos() const;

protected:
    int yPos;
    int xPos;
    QRect boundingBox;

};

#endif // TILEGRAPHICSITEM_H
