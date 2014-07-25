#include "QMLBoard.h"
#include "QMLBoardTile.h"
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlProperty>

QMLBoard::QMLBoard(QQuickItem *parent) :
    QQuickItem(parent),
    dimensionSet(false)
{
}

void QMLBoard::setDimension(const QVector2D &dimension)
{
    mDimension = dimension;
    qDebug() << "setDimension()";

    dimensionSet = true;
    emit dimensionChanged();
}

QVector2D QMLBoard::dimension() const
{
    return mDimension;
}

void QMLBoard::setTileWidth(const qreal & tileWidth)
{
    mTileWidth = tileWidth;
    emit tileWidthChanged();
}

qreal QMLBoard::tileWidth() const
{
    return mTileWidth;
}

void QMLBoard::setGrid(QQuickItem *grid)
{
    mGrid = grid;

    /**
      Old code: creating the board representing tiles with C++
      */
//    QQmlEngine * engine = qmlEngine(this);
//    QQmlContext * context = qmlContext(grid);

//    int tileCount = mDimension.x() * mDimension.y();
//    for (int i=0; i<tileCount; ++i) {
//        QQmlComponent tileComponent(engine, QUrl(QStringLiteral("qrc:///BoardTile.qml")));
//        QQuickItem * tile = qobject_cast<QQuickItem*>(tileComponent.create(context));
//        QQmlProperty::write(tile, "rows", mDimension.y());
//        tile->setParentItem(grid);
//    }

//    qDebug() << "setGrid()";
    emit gridChanged();
}

QQuickItem * QMLBoard::grid() const
{
    return mGrid;
}
