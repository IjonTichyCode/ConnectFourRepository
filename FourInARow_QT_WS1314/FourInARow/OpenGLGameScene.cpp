#include "OpenGLGameScene.h"
#include <QGraphicsView>

#include <QPainter>
#include "TilePixmapGraphicsItem.h"

OpenGLGameScene::OpenGLGameScene(QObject *parent) :
    GameScene(parent),
    whiteTokenPix("whiteToken.png"),
    blackTokenPix("blackToken.png"),
    boardTilePix("boardTile.png"),
    boardCornerTilePix("boardCornerTile.png")
{
    //QWidget * surface = (QWidget*)parent->parent();

    // Specify an OpenGL 3.3 format using the Core profile.
    // That is, no old-school fixed pipeline functionality
    QGLFormat glFormat;
    glFormat.setVersion( 3, 2 );
    glFormat.setProfile( QGLFormat::CompatibilityProfile ); // Requires >=Qt-4.8.0
    glFormat.setSampleBuffers( true );

    //glWidget->resize(500,400);

    glWidget = new OpenGLGameSceneWidget(glFormat, (QWidget*)(parent->parent()));

    //glWidget->show();


}

TileGraphicsItem *OpenGLGameScene::newBoardTile()
{
   TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
   tile->setPixmap(&boardTilePix);
   return tile;
}

TileGraphicsItem *OpenGLGameScene::newBoardCornerTile()
{
    TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
    tile->setPixmap(&boardCornerTilePix);
    return tile;
}

TileGraphicsItem * OpenGLGameScene::newToken(const int & player)
{
    TilePixmapGraphicsItem * tile = new TilePixmapGraphicsItem();
    tile->setPixmap(player==0 ? &whiteTokenPix : &blackTokenPix);
    return tile;
}
