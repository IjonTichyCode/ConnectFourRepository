#ifndef OPENGLGAMESCENE_H
#define OPENGLGAMESCENE_H

#include <QGLWidget>
#include <QPixmap>

#include "GameScene.h"
#include "OpenGLGameSceneWidget.h"

class OpenGLGameScene : public GameScene
{
    Q_OBJECT
public:
    explicit OpenGLGameScene(QObject *parent = 0);

    OpenGLGameSceneWidget * glWidget;

protected:
    virtual TileGraphicsItem * newBoardTile();
    virtual TileGraphicsItem * newBoardCornerTile();
    virtual TileGraphicsItem * newToken(const int & player);


private:


/****************************************/
    QPixmap whiteTokenPix;
    QPixmap blackTokenPix;
    QPixmap boardTilePix;
    QPixmap boardCornerTilePix;

};

#endif // OPENGLGAMESCENE_H
