#ifndef LOADGAMETABLEVIEW_H
#define LOADGAMETABLEVIEW_H

#include <QTableView>

#include "GameDatabase.h"
#include "NewGameSetup.h"
#include "mainwindow.h"

/**
 * @brief The LoadGameTableView class is a TableView to show games that can
 * be loaded to be continued.
 * Game date, time and players are shown. A button to load a game is integrated in
 * each row.
 */
class LoadGameTableView : public QTableView
{
    Q_OBJECT
public:
    explicit LoadGameTableView(QWidget *parent = 0);
    ~LoadGameTableView();

    void setGameDatabase(GameDatabase * database);
    void setMainWindow(MainWindow * mainWindow);

protected slots:
    /**
     * @brief loadGame Loads the game with the passed gameIndex.
     * @param index
     */
    void loadGame(int index);


private:
    GameDatabase * gameDatabase;
    MainWindow * mainWindow;
};

#endif // LOADGAMETABLEVIEW_H
