#include <QDebug>

#include "GameDataModel.h"
#include "GameDatabase.h"
#include "playerdata.h"

using std::pair;

GameDataModel * GameDataModel::instance(NULL);

GameDataModel *GameDataModel::getInstance()
{
    if (!instance) {
        instance = new GameDataModel();
    }
    return instance;
}

GameDataModel::GameDataModel()
{

}

GameDataModel::~GameDataModel()
{
    instance = NULL;
}

void GameDataModel::init()
{
    GameDatabase * dbInstance = GameDatabase::getInstance();
    dbInstance->getPlayers(players);
    dbInstance->getHighscore(highscore);
    dbInstance->getSavedGames(games);
    dbInstance->getAppSetup(appSetup);
}

map<int, PlayerData> & GameDataModel::getPlayers()
{
    return players;
}

const vector<PlayerData> & GameDataModel::getHighscore() const
{
    return highscore;
}

const vector<GameSetup> & GameDataModel::getSavedGames() const
{
    return games;
}

int GameDataModel::addPlayer(PlayerData & player)
{
    GameDatabase * dbInstance = GameDatabase::getInstance();
    int playerId = dbInstance->addPlayer(player.name, player.isCpu, player.level);
    if (playerId>=0) {
        player.index = playerId;
        players.insert( pair<int, PlayerData>(playerId, player) );
        dbInstance->getHighscore(highscore);
        return playerId;
    }else{
        return -1;
    }
}

void GameDataModel::updatePlayer(const PlayerData & playerData)
{
    GameDatabase * dbInstance = GameDatabase::getInstance();
    dbInstance->updatePlayer(playerData);
    dbInstance->getHighscore(highscore);
}

void GameDataModel::saveGame(GameSetup &gameSetup)
{
    GameDatabase::getInstance()->saveGame(gameSetup);
    GameDatabase::getInstance()->getSavedGames(games);
}

GameSetup &GameDataModel::loadGame(int gameId)
{
    newGameSetup();
    gameSetup.gameId = gameId;
    GameDatabase::getInstance()->loadGame(gameSetup);
    gameSetup.player0 = players.at(gameSetup.player0Id).name;
    gameSetup.player1 = players.at(gameSetup.player1Id).name;
    gameSetup.isCpu[0] = players.at(gameSetup.player0Id).isCpu;
    gameSetup.isCpu[1] = players.at(gameSetup.player1Id).isCpu;

    return gameSetup;
}

GameSetup & GameDataModel::getGameSetup()
{
    return gameSetup;
}

GameSetup & GameDataModel::newGameSetup()
{
    gameSetup = GameSetup();
    return gameSetup;
}

FIARApplicationSetup &GameDataModel::getAppSetup()
{
    return appSetup;
}

void GameDataModel::saveAppSetup()
{
    GameDatabase::getInstance()->saveAppSetup(appSetup);
}
