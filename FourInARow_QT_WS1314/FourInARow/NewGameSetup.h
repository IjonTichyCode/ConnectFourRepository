#ifndef NEWGAMESETUP_H
#define NEWGAMESETUP_H

#include <QObject>

/**
 * @brief The NewGameSetup class is a data structure representing the setup
 * statistics data of a game. A game can be completely reconstructed by this data.
 */
class NewGameSetup : public QObject
{
    Q_OBJECT
public:
    explicit NewGameSetup(QObject *parent = 0);

    // name of player0 (including the CPU player tag, if exists
    QString player0;
    // id (database) of player0
    int player0Id;
    // name of player1 (including the CPU player tag, if exists
    QString player1;
    // id (database) of player0
    int player1Id;
    // string of numbers representing the columns where tokens have fallen in
    QString moveHistory;

    int startPlayer;
    int finished;
    // number of moves
    int moves;

    bool isCpu[2];
    int level[2];

    int columns;
    int rows;
};


#endif // NEWGAMESETUP_H
