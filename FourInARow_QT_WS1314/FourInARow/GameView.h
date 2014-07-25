#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "fourinarowgame.h"
#include "NewGameSetup.h"
#include "mainwindow.h"
#include "GameScene.h"
#include "CpuPlayer.h"

/**
 * @brief The SceneType enum defines the GameScene class used to show the game
 */
enum SceneType {
    SCENE_PRIMITVES,
    SCENE_PIXMAP,
    SCENE_SVG
};

/**
 * @brief The GameView is used to show a GameScene.
 * It receives the input to control a FourInARowGame.
 */
class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget * parent = 0);
    ~GameView();

    virtual void keyReleaseEvent(QKeyEvent * event);

    /**
     * @brief setGameSetup Sets up a new game based on the passed gameSetup.
     * @param gameSetup
     */
    void setGameSetup(NewGameSetup * gameSetup);

    /**
     * @brief getGame Returns the game, this view is showing.
     * @return
     */
    FourInARowGame * getGame();

    /**
     * @brief setMainWindow
     * @param mainWindow
     */
    void setMainWindow(MainWindow * mainWindow);

public slots:
    /**
     * @brief selectPrimitivesDesign select/deselect the Primitives Design.
     * The primitives design is very simple (even simpler than simple design)
     * and drawn by QT methods only.
     * @param state
     */
    void selectPrimitivesDesign(bool state);

    /**
     * @brief selectSimpleDesign select/deselect the simple Design.
     * It is drawn by .png images.
     * @param state
     */
    void selectSimpleDesign(bool state);

    /**
     * @brief selectSvgDesign select/deselect the Svg Design.
     * @param state
     */
    void selectSvgDesign(bool state);

protected:

    virtual void resizeEvent(QResizeEvent * event);

private:
    /**
     * @brief printNextPlayer shows the next player on the status bar
     */
    void printNextPlayer();
    void move();
    /**
     * @brief newScene creates a new GameScene object of the preconfigured type.
     * @return
     */
    GameScene * newScene();

    int columnIndex;

    SceneType sceneType;

    FourInARowGame * game;
    NewGameSetup * gameSetup;
    MainWindow * mainWindow;

    // players used, if one or two players are controlled by the computer
    CpuPlayer cpuPlayers[2];


};

#endif // GAMEVIEW_H
