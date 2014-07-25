#ifndef HIGHSCORETABLEVIEW_H
#define HIGHSCORETABLEVIEW_H

#include <QTableView>

#include "GameDatabase.h"

/**
 * @brief The HighscoreTableView class is a TableView to show HighScores of the players.
 * Winner, Loser and the moves needed to finish the game are shown, sorted by the shortest
 * number of moves.
 */
class HighscoreTableView : public QTableView
{
    Q_OBJECT
public:
    explicit HighscoreTableView(QWidget *parent = 0);

    ~HighscoreTableView();

    /**
     * @brief setGameDatabase populates the table with highscore data
     * @param database GameDatabase pointer needed to get highscore data
     */
    void setGameDatabase(GameDatabase * database);

private:
    GameDatabase * gameDatabase;
};

#endif // HIGHSCORETABLEVIEW_H
