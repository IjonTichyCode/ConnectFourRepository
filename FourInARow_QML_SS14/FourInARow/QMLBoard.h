#ifndef QMLBOARD_H
#define QMLBOARD_H

#include <QQuickItem>

class QMLBoard : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QVector2D dimension READ dimension WRITE setDimension NOTIFY dimensionChanged)
    Q_PROPERTY(qreal tileWidth READ tileWidth WRITE setTileWidth NOTIFY tileWidthChanged)
    Q_PROPERTY(QQuickItem* grid READ grid WRITE setGrid NOTIFY gridChanged)

//    Q_PROPERTY(QQmlListProperty<QMLBoardTile> boardTiles READ boardTiles )


public:
    QMLBoard(QQuickItem *parent = 0);

    Q_INVOKABLE void setDimension(const QVector2D & dimension);
    Q_INVOKABLE QVector2D dimension() const;

    Q_INVOKABLE void setTileWidth(const qreal & tileWidth);
    Q_INVOKABLE qreal tileWidth() const;

    Q_INVOKABLE void setGrid(QQuickItem* grid);
    Q_INVOKABLE QQuickItem* grid() const;


signals:
    void dimensionChanged();
    void tileWidthChanged();
    void gridChanged();

public slots:

private:
    int mRows;
    int mColumns;
    qreal mTileWidth;
    QVector2D mDimension;
    QQuickItem * mGrid;

    bool dimensionSet;

//    QList<QMLBoardTile*> mBoardTiles;
};

#endif // QMLBOARD_H
