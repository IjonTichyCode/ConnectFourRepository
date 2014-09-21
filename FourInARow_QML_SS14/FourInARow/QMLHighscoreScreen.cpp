#include "QMLHighscoreScreen.h"

#include <QDebug>
#include <vector>
#include "GameDataModel.h"
#include "playerdata.h"

using std::vector;

QMLHighscoreScreen::QMLHighscoreScreen(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void QMLHighscoreScreen::populate()
{
    const vector<PlayerData> & highscoreList =  GameDataModel::getInstance()->getHighscore();
    for (int i=0; i<highscoreList.size(); ++i) {
        const PlayerData & player = highscoreList.at(i);
        double ratio = (player.losses==0 && player.wins==0) ? 0 : player.wins/player.losses;
        emit addEntry( QString(player.name.c_str()), player.wins, player.losses, ratio);
    }
}
