#ifndef SIMPLEGAMESCENE_H
#define SIMPLEGAMESCENE_H

#include <QPixmap>

#include "GameScene.h"

/**
 * @brief The SimpleGameScene class implements the GameScene class
 * with Tiles that are drawn by QPixmap objects.
 * .png files are used.
 */
class SimpleGameScene : public GameScene
{
    Q_OBJECT
public:
    explicit SimpleGameScene(QObject *parent = 0);

    ~SimpleGameScene();

protected:
    virtual TileGraphicsItem * newBoardTile();
    virtual TileGraphicsItem * newBoardCornerTile();
    virtual TileGraphicsItem * newToken(const int & player);


private:

    // pixmaps are reused for each tile
    QPixmap whiteTokenPix;
    QPixmap blackTokenPix;
    QPixmap boardTilePix;
    QPixmap boardCornerTilePix;


};

#endif // SIMPLEGAMESCENE_H
