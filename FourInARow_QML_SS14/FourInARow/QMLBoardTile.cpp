#include "QMLBoardTile.h"
#include <QPainter>
#include <QColor>

QMLBoardTile::QMLBoardTile(QQuickItem *parent) :
    QQuickItem(parent)
//    QQuickPaintedItem(parent)
//  ,mParentBoard(NULL)
{
}

int QMLBoardTile::rows() const
{
    return mRows;
}

void QMLBoardTile::setRows(int rows)
{
    mRows = rows;
    emit rowsChanged();
}

//QMLBoard * QMLBoardTile::parentBoard() const
//{
//    return mParentBoard;
//}

//void QMLBoardTile::setParentBoard(QMLBoard * parentBoard)
//{
//    mParentBoard = parentBoard;
//}

//void QMLBoardTile::paint(QPainter *painter)
//{
//    QPen pen(QColor(255,128,0), 2);
//    painter->setPen(pen);
//    painter->setRenderHints(QPainter::Antialiasing, true);
//    painter->drawRect(0, 0, parentBoard()->tileWidth(), parentBoard()->tileWidth());
//}
