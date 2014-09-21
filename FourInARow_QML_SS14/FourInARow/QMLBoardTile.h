#ifndef QMLBOARDTILE_H
#define QMLBOARDTILE_H

#include <QQuickItem>
#include<QQuickPaintedItem>
#include "QMLBoard.h"

/**
 * @brief The QMLBoardTile class is obsolete
 */
class QMLBoardTile : public QQuickItem
{
    Q_OBJECT
//    Q_PROPERTY(QMLBoard * parentBoard READ parentBoard WRITE setParentBoard NOTIFY parentBoardChanged)
    Q_PROPERTY(int rows READ rows WRITE setRows NOTIFY rowsChanged)

public:
    QMLBoardTile(QQuickItem *parent = 0);

//    Q_INVOKABLE QMLBoard * parentBoard() const;
//    Q_INVOKABLE void setParentBoard(QMLBoard * parentBoard);
    //void paint(QPainter *painter);
    Q_INVOKABLE int rows() const;
    Q_INVOKABLE void setRows(int rows);

signals:
//    void parentBoardChanged();
    void rowsChanged();

public slots:

private:
//    QMLBoard * mParentBoard;
    int mRows;

};

#endif // QMLBOARDTILE_H
