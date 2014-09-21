 #include "GameSetup.h"

GameSetup::GameSetup():
    columns(7),
    rows(6),
    startPlayer(0),
    finished(0),
    moves(0),
    time(0),
    maxTime(3),
    useTimer(false),
    gameId(-1)

{
    isCpu[0] = false;
    isCpu[1] = false;
}

