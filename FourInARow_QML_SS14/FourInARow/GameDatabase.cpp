#include "GameDatabase.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

using std::pair;

GameDatabase * GameDatabase::databaseInstance(NULL);

GameDatabase::GameDatabase(QObject *parent) :
    QObject(parent),
    queryHighscore(
        "select oid, name, iscpu, wins, losses, "
        "ties from players order by wins/losses desc"
    ),
    querySavedGames(
        "select date(datum), time(datum), name, name1, games.oid from "
        "players, (select oid, name as name1 from players) as players1, games "
        "where players.oid=games.player0 and players1.oid=games.player1 "
        "and finished=0 "
        "order by datum desc" //"and movehistory not null"
    ),
    cpuRegExp(" (CPU: level ?)", Qt::CaseSensitive, QRegExp::Wildcard)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("localhost");
    database.setDatabaseName("connectFourDatabase");
    database.setUserName("fourInARowGame");
    database.setPassword("sdgmkgdbadgbaeh");
    database.open();
    databaseInstance = this;
}

GameDatabase *GameDatabase::getInstance()
{
    if (!databaseInstance) {
        databaseInstance = new GameDatabase();
    }

    return databaseInstance;
}

GameDatabase::~GameDatabase()
{
    database.close();
    databaseInstance = NULL;
}

QSqlDatabase * GameDatabase::getDatabase()
{
    return &database;
}

void GameDatabase::getPlayers(map<int, PlayerData> &players) const
{   
    QSqlQuery query= database.exec("select oid, name, iscpu, level, datum, wins, losses, ties from players order by datum desc");
    qDebug() << query.lastError().databaseText();
    players.clear();

    while (query.next()) {
        PlayerData player;
        player.index = query.value(0).toInt();
        player.name = query.value(1).toString().toStdString();
        player.isCpu = query.value(2).toBool();
        player.level = query.value(3).toInt();
        player.wins = query.value(5).toInt();
        player.losses = query.value(6).toInt();
        player.ties = query.value(7).toInt();
        players.insert(pair<int,PlayerData>(player.index, player));
    }

}

void GameDatabase::getHighscore(vector<PlayerData> & highscore)
{
    QSqlQuery query= database.exec(queryHighscore);
    qDebug() << query.lastError().databaseText();
    highscore.clear();

    while (query.next()) {
        PlayerData player;
        player.index = query.value(0).toInt();
        player.name = query.value(1).toString().toStdString();
        player.isCpu = query.value(2).toBool();
        player.wins = query.value(3).toDouble();
        player.losses = query.value(4).toDouble();
        player.ties = query.value(5).toDouble();
        highscore.push_back(player);
    }
}

void GameDatabase::getSavedGames(vector<GameSetup> & games)
{
    QString queryString("select gameOid, name0, name1, datum from "
        "(select oid, name as name0 from players) as players0,"
        "(select oid, name as name1 from players) as players1,"
        "(select oid as gameOid, player0, player1, datum from games) as gamesTmp "
        "where players0.oid=player0 and players1.oid=player1 "
        "order by datum desc"
    );

    QSqlQuery savedGames = database.exec(queryString);

    if (savedGames.lastError().isValid()) {
        qDebug() << queryString;
        qDebug() << "GameDatabase: getSavedGames(...): " << savedGames.lastError();
    }

    games.clear();

    while (savedGames.next()) {
        GameSetup game;
        game.gameId = savedGames.value(0).toInt();
        game.player0 = savedGames.value(1).toString().toStdString();
        game.player1 = savedGames.value(2).toString().toStdString();
        games.push_back(game);
    }

}

void GameDatabase::saveGame(GameSetup & gameSetup)
{
    // if game has no Id -> game hasn´t been saved yet
    if (gameSetup.gameId <0) {
        QString saveGameQueryString =
                "insert into games "
                "(player0, player1, movehistory, moves, datum, columns, rows, useTimer, maxTime, time) "
                "values ("
                + QString::number(gameSetup.player0Id) + ","
                + QString::number(gameSetup.player1Id) + ",'"
                + QString(gameSetup.moveHistory.c_str()) + "',"
                + QString::number(gameSetup.moves) + ","
                "datetime(),"
                + QString::number(gameSetup.columns) + ","
                + QString::number(gameSetup.rows) + ","
                + QString::number(gameSetup.useTimer) + ","
                + QString::number(gameSetup.maxTime) + ","
                + QString::number(gameSetup.time)+ ")"
            ;

        QSqlQuery saveGameQuery = database.exec(saveGameQueryString);

        if (saveGameQuery.lastError().isValid()) {
            qDebug() << saveGameQueryString;
            qDebug() << "GameDatabase: saveGame(...): " << saveGameQuery.lastError();
        }

        QString queryGameIdString = "select oid from games where datum=(select MAX(datum) from games)";
        QSqlQuery gameIdQuery = database.exec(queryGameIdString);

        if (gameIdQuery.lastError().isValid()) {
            qDebug() << queryGameIdString;
            qDebug() << "GameDatabase: saveGame(...): " << gameIdQuery.lastError();
        }

        if (gameIdQuery.next()) {
            gameSetup.gameId = gameIdQuery.value(0).toInt();
            qDebug() << gameSetup.gameId;
        }

    // if game has a id -> overwrite old saved game
    }else{
        QString overwriteGameQueryString =
            "update games set"
            " moveHistory='" + QString(gameSetup.moveHistory.c_str())
            + "',moves=" + QString::number(gameSetup.moves)
            + ",datum=datetime()"
            ",time=" + QString::number(gameSetup.time)
            + " where oid=" + QString::number(gameSetup.gameId)
        ;

        QSqlQuery overwriteGameQuery = database.exec(overwriteGameQueryString);

        if (overwriteGameQuery.lastError().isValid()) {
            qDebug() << overwriteGameQueryString;
            qDebug() << "GameDatabase: saveGame(...): " << overwriteGameQuery.lastError();
        }
    }
}

void GameDatabase::loadGame(GameSetup & gameSetup)
{
    QSqlQuery gameQuery = database.exec(
        "select player0, player1, movehistory, moves, columns, rows, useTimer, maxTime, time "
        "from games where oid="
        + QString::number(gameSetup.gameId)
    );

    if (gameQuery.next()) {
        gameSetup.player0Id = gameQuery.value(0).toInt();
        gameSetup.player1Id = gameQuery.value(1).toInt();
        gameSetup.moveHistory = gameQuery.value(2).toString().toStdString();
        gameSetup.moves = gameQuery.value(3).toInt();
        gameSetup.columns = gameQuery.value(4).toInt();
        gameSetup.rows = gameQuery.value(5).toInt();
        gameSetup.useTimer = gameQuery.value(6).toBool();
        gameSetup.maxTime = gameQuery.value(7).toInt();
        gameSetup.time = gameQuery.value(8).toFloat();
    }

}

int GameDatabase::addPlayer(const string & name, bool isCpu, int level)
{   
    QString qName(name.c_str());
    if (!qName.isEmpty()) {
        QSqlQuery queryResult;
        if (isCpu) {
            queryResult = database.exec("insert into players (name, iscpu, level) values ('"
                + qName + "', 1, " + QString::number(level) + ')'
            );
        }else{
            queryResult = database.exec( "insert into players (name) values ('" + qName + "')" );
        }

        // means, that the player name already exists
        if (queryResult.lastError().isValid()) {
            return -1;
        }
    }else{
        return -1;
    }

    //get id of the new player
    QSqlQuery query= database.exec("select oid, name from players where name='"
                        + qName + "'");
    if (query.next()) {
        return query.value(0).toInt();
    }else{
        return -1;
    }
}

void GameDatabase::updatePlayer(const PlayerData &playerData)
{
    QString queryString("update players set"
        " wins=" + QString::number(playerData.wins)
        + ",losses=" + QString::number(playerData.losses)
        + ",ties=" + QString::number(playerData.ties)
        + " where oid=" + QString::number(playerData.index)
    );
    QSqlQuery query= database.exec(queryString);
}


void GameDatabase::getAppSetup(FIARApplicationSetup &appSetup)
{
    QSqlQuery optQuery = database.exec(
        "select fullscreen, antialiasing, width, height, player0Id, "
        "player1Id, design, color0, color1, useTimer, maxTime, columns, rows, language from options"
    );

    if (optQuery.next()) {
        appSetup.fullscreen = optQuery.value(0).toBool();
        appSetup.antialiasing = optQuery.value(1).toBool();
        appSetup.width = optQuery.value(2).toInt();
        appSetup.height = optQuery.value(3).toInt();
        appSetup.player0Id = optQuery.value(4).toInt();
        appSetup.player1Id = optQuery.value(5).toInt();
        appSetup.design = optQuery.value(6).toInt();
        appSetup.color0 = optQuery.value(7).toFloat();
        appSetup.color1 = optQuery.value(8).toFloat();
        appSetup.useTimer = optQuery.value(9).toBool();
        appSetup.maxTime = optQuery.value(10).toInt();
        appSetup.columns = optQuery.value(11).toInt();
        appSetup.rows = optQuery.value(12).toInt();
        appSetup.language = optQuery.value(13).toInt();
    }
}

void GameDatabase::saveAppSetup(FIARApplicationSetup &appSetup)
{
    QString queryString("update options set"
        " fullscreen=" + QString::number(appSetup.fullscreen)
        + ",antialiasing=" + QString::number(appSetup.antialiasing)
        + ",width=" + QString::number(appSetup.width)
        + ",height=" + QString::number(appSetup.height)
        + ",player0Id=" + QString::number(appSetup.player0Id)
        + ",player1Id=" + QString::number(appSetup.player1Id)
        + ",design=" + QString::number(appSetup.design)
        + ",color0=" + QString::number(appSetup.color0)
        + ",color1=" + QString::number(appSetup.color1)
        + ",useTimer=" + QString::number(appSetup.useTimer)
        + ",maxTime=" + QString::number(appSetup.maxTime)
        + ",columns=" + QString::number(appSetup.columns)
        + ",rows=" + QString::number(appSetup.rows)
        + ",language=" + QString::number(appSetup.language)
    );


    database.exec(queryString);
}
