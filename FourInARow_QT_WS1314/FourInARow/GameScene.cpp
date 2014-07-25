#include "GameScene.h"
#include <QPropertyAnimation>
#include <cmath>

#include <QDebug>

#include "tokenfallanimation.h"


GameScene::GameScene(QObject *parent) :
    QGraphicsScene(parent),
    tileRadius(30),
    bounceEffect0(new QSoundEffect(this)),
    bounceEffect1(new QSoundEffect(this)),
    slideEffect0(new QSoundEffect(this)),
    slideEffect1(new QSoundEffect(this)),
    winSound(new QSoundEffect(this)),
    invalidMoveSound(new QSoundEffect(this)),
    tieSound(new QSoundEffect(this)),
    whiteTokenTieRenderer(QString("whiteTokenTie.svg")),
    blackTokenTieRenderer(QString("blackTokenTie.svg")),
    whiteTokenWinRenderer(QString("whiteTokenWin.svg")),
    blackTokenWinRenderer(QString("blackTokenWin.svg")),
    playSound(false)
{
    bounceEffect0->setSource(QUrl::fromLocalFile("bounce0.wav"));
    bounceEffect1->setSource(QUrl::fromLocalFile("bounce1.wav"));
    slideEffect0->setSource(QUrl::fromLocalFile("slide0.wav"));
    slideEffect1->setSource(QUrl::fromLocalFile("slide1.wav"));
    winSound->setSource(QUrl::fromLocalFile("win.wav"));
    invalidMoveSound->setSource(QUrl::fromLocalFile("invalidMove.wav"));
    tieSound->setSource(QUrl::fromLocalFile("tie.wav"));
}

GameScene::~GameScene()
{
    for (int i=0; i<whiteTokens.length(); ++i) {
        delete whiteTokens.at(i);
    }

    for (int i=0; i<blackTokens.length(); ++i) {
        delete blackTokens.at(i);
    }

    for (int i=0; i<boardTiles.length(); ++i) {
        delete boardTiles.at(i);
    }

    for (int i=0; i<boardCornerTiles.length(); ++i) {
        delete boardCornerTiles.at(i);
    }
}

void GameScene::setBoard(FourInARowBoard * board) {

    this->board = board;
    const int colMax = board->columnCount;
    const int rowMax = board->rowCount;

    const int x0 = -colMax * tileRadius;
    const int y0 = rowMax * (tileRadius);
    const int d = 2*tileRadius;

    TileGraphicsItem * tile;

    for (int row=0; row<rowMax; ++row) {

        for (int col=0; col<colMax; ++col) {

            //tile = new TileGraphicsItem();

            if ( (row==0 || row==rowMax-1) && (col==0 || col==colMax-1) ) {
                tile = newBoardCornerTile();
                tile->setRotation(-90  + (row>0 ? 90 : 0) + (col>0 ? 90 : 0) + (col>0 && row==0 ? 180 : 0) );
            }else{
                tile = newBoardTile();
            }
            tile->setRadius(tileRadius);
            tile->setPos(x0+d*col, y0-d*row);
            tile->setZValue(1);

            this->addItem(tile);
            boardTiles.append(tile);
        }
    }

    setupNextToken(0);
}

void GameScene::setupNextToken(int column)
{
    nextToken = newToken(board->nextPlayer);
    nextToken->setPos(tileRadius * (column*2-board->columnCount) , 0);
    nextToken->setRadius(tileRadius);

    QPropertyAnimation * a = new QPropertyAnimation(nextToken, "yPos");
    a->setStartValue( - (board->rowCount+4) * tileRadius);
    a->setEndValue((-board->rowCount-1) * tileRadius);

    int timeFactor = (int) (600.0);

    a->setDuration(timeFactor);
    a->setEasingCurve(QEasingCurve::InOutBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    nextToken->setZValue(0);

    this->addItem(nextToken);
    boardTiles.append(nextToken);
}

void GameScene::addToken(const int & player, const int & x, const int & y)
{
    const int rowMax = board->rowCount;
    const int y0 = rowMax * (tileRadius);
    const int d = 2*tileRadius;

    QPropertyAnimation * a = new QPropertyAnimation(nextToken, "yPos");

    a->setEndValue(y0-d*y);
    int timeFactor = (int) (sqrt(rowMax - y)*800.0);

    a->setDuration(timeFactor);
    a->setEasingCurve(QEasingCurve::OutBounce);
    a->start(QPropertyAnimation::DeleteWhenStopped);


    //tokenFallSounds.append(new TokenFallSound(slideEffect0, bounceEffect0, timeFactor));
    if (playSound) {
        QSoundEffect * slideEffect = player==0 ? slideEffect0 : slideEffect1;
        QSoundEffect * bounceEffect = player==0 ? bounceEffect0 : bounceEffect1;
        new TokenFallSound(slideEffect, bounceEffect, timeFactor);
    }

    selectColumn(x);
}

void GameScene::playerWins(int player, int * winRow)
{
    //QVector<TileGraphicsItem*> winnerTokens;
    winSound->play();
    toggleSound(false);
    const int rowMax = board->rowCount;
    const int y0 = rowMax * tileRadius;
    const int d = 2*tileRadius;

    for (int i=0; i<4; ++i) {
        int column = winRow[i*2];
        int row = winRow[i*2+1];

        nextToken = newWinAnimationToken(player);
        nextToken->setPos(tileRadius * (column*2-board->columnCount) , 0);
        nextToken->setRadius(tileRadius);
        nextToken->setZValue(2);

        QPropertyAnimation * a = new QPropertyAnimation(nextToken, "yPos");
        a->setStartValue( - (board->rowCount+4) * tileRadius);
        a->setEndValue(y0-d*row);

        int timeFactor = (int) (1500 + i*500);

        a->setDuration(timeFactor);
        a->setEasingCurve(QEasingCurve::OutElastic);
        a->start(QPropertyAnimation::DeleteWhenStopped);

        this->addItem(nextToken);
        boardTiles.append(nextToken);
    }
}

void GameScene::tie()
{
    tieSound->play();
    toggleSound(false);
    const int colMax = board->columnCount;
    const int rowMax = board->rowCount;

    for (int player=0; player<2; ++player) {
      nextToken = newTieAnimationToken(player);
      nextToken->setRadius(tileRadius);
      nextToken->setPos(0, (-rowMax-1) * tileRadius);
      nextToken->setZValue(2);

      QPropertyAnimation * a = new QPropertyAnimation(nextToken, "xPos");
      a->setStartValue( (player*2-1) * tileRadius * (colMax+3) );
      a->setEndValue((player*2-2) * tileRadius);

      int timeFactor = (int) (1800);

      a->setDuration(timeFactor);
      a->setEasingCurve(QEasingCurve::OutBounce);
      a->start(QPropertyAnimation::DeleteWhenStopped);

      this->addItem(nextToken);
      boardTiles.append(nextToken);
    }
}

void GameScene::failToken(const int & player, const int & x, const int & y)
{
    invalidMoveSound->play();
    QPropertyAnimation * a = new QPropertyAnimation(nextToken, "yPos");
    a->setStartValue((-board->rowCount-1) * tileRadius);
    a->setKeyValueAt(0.25, (-board->rowCount-1) * tileRadius);
    a->setKeyValueAt(0.65, - (board->rowCount+2) * tileRadius);
    a->setEndValue((-board->rowCount-1) * tileRadius);

    int timeFactor = (int) (1500);

    a->setDuration(timeFactor);
    a->setEasingCurve(QEasingCurve::OutElastic);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void GameScene::selectColumn(int column)
{
     QPropertyAnimation * a = new QPropertyAnimation(nextToken, "xPos");
     int endVal = tileRadius * (column*2 - board->columnCount);
     int startVal = nextToken->pos().x();
     a->setStartValue(startVal);
     a->setEndValue(endVal);
     a->setDuration( abs(endVal-startVal)*4 );
     a->setEasingCurve(QEasingCurve::InOutQuad);
     a->start(QPropertyAnimation::DeleteWhenStopped);
}

qreal GameScene::calcScale(QSizeF size)
{
    qreal wPreferred = (tileRadius * 2+1) * board->columnCount;
    qreal hPreferred = (tileRadius * 2+5) * board->rowCount;
    qreal sc = qMin(size.width()/wPreferred, size.height()/hPreferred);
    qDebug() << sc;
    return sc;
}

void GameScene::toggleSound(bool state)
{
    playSound = state;
}

TileGraphicsItem * GameScene::newTieAnimationToken(int player)
{
    TileSvgGraphicsItem * tile = new TileSvgGraphicsItem();
    tile->setRenderer(player==0 ? &whiteTokenTieRenderer : &blackTokenTieRenderer);
    return tile;
}

TileGraphicsItem * GameScene::newWinAnimationToken(int player)
{
    TileSvgGraphicsItem * tile = new TileSvgGraphicsItem();
    tile->setRenderer(player==0 ? &whiteTokenWinRenderer : &blackTokenWinRenderer);
    return tile;
}
