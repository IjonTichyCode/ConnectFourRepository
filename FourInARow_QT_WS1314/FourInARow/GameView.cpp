#include "GameView.h"
#include <QDebug>
#include <QTransform>
#include "SimpleGameScene.h"
#include "PrimitivesGameScene.h"
#include "SvgGameScene.h"

/*************************Con/Destructor, Setup***************************************************************/

GameView::GameView(QWidget *parent):
    QGraphicsView(parent),
    columnIndex(0),
    gameSetup(NULL),
    game(NULL),
    sceneType(SceneType::SCENE_PIXMAP),
    mainWindow(NULL)
{
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
}

GameView::~GameView()
{
    if (game) delete game;
}

FourInARowGame * GameView::getGame()
{
    return game;
}

void GameView::setMainWindow(MainWindow * mainWindow)
{
    this->mainWindow = mainWindow;
}


void GameView::setGameSetup(NewGameSetup *gameSetup)
{
    this->gameSetup = gameSetup;

    for (int i=0; i<2; ++i) {

    }

    if (game) delete game;
    game = new FourInARowGame(gameSetup->startPlayer, gameSetup->columns, gameSetup->rows );
    columnIndex = 0;

    if (scene()) delete scene();
    GameScene * scene = newScene();
    //PrimitivesGameScene * scene = new PrimitivesGameScene(ui->gameView);
    //SvgGameScene * scene = new SvgGameScene(ui->gameView);
    setScene(scene);
    scene->setBoard(game->getBoard());
    scene->toggleSound(false);
    for (int i=0; i<gameSetup->moveHistory.length(); ++i) {
        QString number(gameSetup->moveHistory.at(i));
        columnIndex = number.toInt();
        game->move(columnIndex);
        scene->addToken(i%2, columnIndex, game->getLatestTokenRow());
        qDebug() << "column: " << columnIndex;
        scene->setupNextToken(columnIndex);
        qDebug() << "move: " << columnIndex;
    }
    scene->toggleSound(true);
    printNextPlayer();
    if (gameSetup->isCpu[game->getPlayerToMoveNext()]) {
        move();
    }
}


/*********************************Interaction*****************************************/

void GameView::keyReleaseEvent(QKeyEvent *event)
{
    if (game->isFinished()) {

        return;
    }

    GameScene * gameScene = (GameScene*)this->scene();

    switch (event->key())
    {

    case Qt::Key_Left:

        if (columnIndex>0) {
            --columnIndex;
           gameScene->selectColumn(columnIndex);
        }
        break;

    case Qt::Key_Right:
        if (columnIndex < game->getBoard()->columnCount-1) {
            ++columnIndex;
            gameScene->selectColumn(columnIndex);
        }
        break;

    case Qt::Key_Return:
        move();


        break;
    }

    QGraphicsView::keyReleaseEvent(event);
}

void GameView::move()
{
    GameScene * gameScene = (GameScene*)this->scene();
    int player = game->getPlayerToMoveNext();

    if (gameSetup->isCpu[player]) {
        columnIndex = cpuPlayers[player].getCpuMove(*game);
    }
    MoveResult res = game->move(columnIndex);
    QString message;
    switch (res) {
    case MoveResult::SUCCESS:
        gameScene->addToken(player, columnIndex, game->getLatestTokenRow());
        gameSetup->moveHistory.append(QString::number(columnIndex));
        gameScene->setupNextToken(columnIndex);
        ++gameSetup->moves;
        printNextPlayer();
        break;

    case MoveResult::WIN:
        gameScene->toggleSound(false);
        gameScene->addToken(player, columnIndex, game->getLatestTokenRow());
        gameScene->toggleSound(true);
        gameSetup->moveHistory.append(QString::number(columnIndex));
        gameSetup->startPlayer=player;
        gameSetup->finished=1;
        ++gameSetup->moves;
        mainWindow->setStatusMessage( (game->getPlayerToMoveNext()==0 ? gameSetup->player0 : gameSetup->player1)
            + "wins with "
            + QString::number(gameSetup->moves+1)
            + " moves!"
        );
        gameScene->playerWins( player, game->getWinRow() );
        mainWindow->saveGame();
        break;

    case MoveResult::TIE:
        gameScene->toggleSound(false);
        gameScene->addToken(player, columnIndex, game->getLatestTokenRow());
        gameSetup->moveHistory.append(QString::number(columnIndex));
        gameSetup->finished=2;
        ++gameSetup->moves;
        gameScene->tie();
        mainWindow->saveGame();
        qDebug() << "tie";
        mainWindow->setStatusMessage("Game finished with a tie!");
        break;

    case MoveResult::INVALID_COLUMN:
        gameScene->failToken(player, columnIndex, game->getLatestTokenRow());
        break;

    case MoveResult::FULL_COLUMN:
        gameScene->failToken(player, columnIndex, game->getLatestTokenRow());
        mainWindow->setStatusMessage( "Column is full, try another one "
            + (game->getPlayerToMoveNext()==0 ? gameSetup->player0 : gameSetup->player1)
            + "!"
        );
        break;
    }

    // if game isnt finished and next player is cpu, begin next turn immediately
    if (!game->isFinished() && gameSetup->isCpu[game->getPlayerToMoveNext()]) {
        move();
    }
}

void GameView::resizeEvent(QResizeEvent * event)
{
    if (scene()) {
        qreal sc = ((GameScene*)(scene()))->calcScale(event->size());
        QTransform scaleM;
        scaleM.scale(sc*0.7, sc*.7);
        setTransform(scaleM);
    }
}

void GameView::printNextPlayer()
{
    QString message;
    message.append("Move number ");
    message.append(QString::number(gameSetup->moves+1));
    message.append(": It is ");
    message.append(game->getPlayerToMoveNext()==0 ? gameSetup->player0 : gameSetup->player1);
    message.append(+"´s turn!");
    mainWindow->setStatusMessage(message);
}

GameScene * GameView::newScene()
{
    switch (sceneType) {
    case SceneType::SCENE_PRIMITVES:
        return new PrimitivesGameScene(this);
    case SceneType::SCENE_PIXMAP:
        return new SimpleGameScene(this);
    case SceneType::SCENE_SVG:
        return new SvgGameScene(this);
    }
}

/*****************************************Design select****************************************************/

void GameView::selectPrimitivesDesign(bool state)
{
    sceneType = SceneType::SCENE_PRIMITVES;
    if (scene()) setGameSetup(gameSetup);
}

void GameView::selectSimpleDesign(bool state)
{
    sceneType = SceneType::SCENE_PIXMAP;
    if (scene()) setGameSetup(gameSetup);
}

void GameView::selectSvgDesign(bool state)
{
    sceneType = SceneType::SCENE_SVG;
    if (scene()) setGameSetup(gameSetup);
}

