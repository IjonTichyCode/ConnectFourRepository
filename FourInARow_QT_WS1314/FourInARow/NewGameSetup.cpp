#include "NewGameSetup.h"

NewGameSetup::NewGameSetup(QObject *parent) :
    QObject(parent),
    columns(7),
    rows(6),
    startPlayer(0),
    finished(0),
    moves(0)
{
    isCpu[0] = false;
    isCpu[1] = false;
}
