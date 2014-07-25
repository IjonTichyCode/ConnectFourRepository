#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include "fourinarowgame.h"
#include "GameDatabase.h"
#include "NewGameSetup.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class is a GUI Window containing the whole Connect Four application.
 * It is used as GUI, contains top level functionality in one class.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    virtual void resizeEvent(QResizeEvent * event);

    /**
     * @brief newGame starts a new game based on the passe gameSetup object.
     * The application will automatically switch to the game board view.
     * @param gameSetup
     */
    void newGame(NewGameSetup * gameSetup);

    /**
     * @brief setStatusMessage prints a new status message to the status bar of the main window.
     * @param msg
     */
    void setStatusMessage(const QString &msg);

    /**
     * @brief showSaveGameMessageBox creates a modal Dialog to ask, whether the current game should be saved to the database.
     * @return
     */
    QMessageBox::StandardButton showSaveGameMessageBox();

public slots:

    /**
     * @brief toggleFullscreen toggles to fullscreen/normal size mode
     * @param mode true=fullscreen
     */
    void toggleFullscreen(bool mode);

    /**
     * @brief openNewGameDialog Opens a Dialog to create a new game.
     */
    void openNewGameDialog();

    /**
     * @brief openHighscore Switches the application view to the highscore table
     */
    void openHighscore();

    /**
     * @brief openLoadGame Switches the application view to the load game table
     */
    void openLoadGame();

    /**
     * @brief saveGame Saves the current game
     */
    void saveGame();

    /**
     * @brief openGameBoard Switches the application view to the game board view
     */
    void openGameBoard();

    /**
     * @brief printHighscore opens a print dialog to print the highscore table.
     */
    void printHighscore();

protected:
    virtual void closeEvent( QCloseEvent * event );

private:
    Ui::MainWindow *ui;
    GameDatabase * gameDatabase;
    NewGameSetup * gameSetup;


};

#endif // MAINWINDOW_H
