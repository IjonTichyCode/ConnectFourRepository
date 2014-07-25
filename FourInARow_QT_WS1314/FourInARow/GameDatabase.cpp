#include "GameDatabase.h"
#include <QDebug>
#include <QSqlError>

GameDatabase::GameDatabase(QObject *parent) :
    QObject(parent),
    queryHighscore(
        "select name, name1, moves from "
        "players, (select oid, name as name1 from players) as players1, games "
        "where players.oid = games.player0 and players1.oid = games.player1 and finished=1 "
        "order by moves"
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
}

GameDatabase::~GameDatabase()
{
    database.close();
}

QSqlDatabase * GameDatabase::getDatabase()
{
    return &database;
}

QSqlQuery * GameDatabase::getPlayers()
{
    QSqlQuery query = database.exec("select name,iscpu,level from players");

    QSqlQuery * retQuery = new QSqlQuery(query);

    return retQuery;
}

void GameDatabase::getHighscore(QSqlQueryModel * model)
{
    model->setQuery(queryHighscore);
    qDebug() << model->lastError().text();
}

void GameDatabase::getSavedGames(QSqlQueryModel * model)
{
    model->setQuery(querySavedGames);

    qDebug() << model->lastError().text();

}

void GameDatabase::loadGame(int gameIndex, NewGameSetup * gameSetup)
{
    QSqlQuery gameQuery = database.exec(
        "select player0, player1, columns, rows, startplayer, movehistory, moves "
        "from games where oid="
        + QString::number(gameIndex)
    );

    gameQuery.next();
    gameSetup->columns = gameQuery.value(2).toInt();
    gameSetup->rows = gameQuery.value(3).toInt();
    int startPlayer = gameQuery.value(4).toInt();
    gameSetup->moveHistory = gameQuery.value(5).toString();
    gameSetup->moves = gameQuery.value(6).toInt();

    QSqlQuery player0Query = database.exec("select name, iscpu, level from players where oid="
        + gameQuery.value(0).toString()
    );

    QSqlQuery player1Query = database.exec("select name, iscpu, level from players where oid="
        + gameQuery.value(1).toString()
    );

    player0Query.next();
    player1Query.next();

    QSqlQuery & p0Query = startPlayer==0 ? player0Query : player1Query;
    QSqlQuery & p1Query = startPlayer==0 ? player1Query : player0Query;

    gameSetup->player0 = p0Query.value(0).toString();
    gameSetup->player1 = p1Query.value(0).toString();

    if (!p0Query.value(1).isNull()) {
        gameSetup->isCpu[0] = true;
        gameSetup->level[0] = p0Query.value(2).toInt();
        gameSetup->player0.append(" (CPU: level ")
                .append(QString::number(gameSetup->level[0]))
                .append(")");
    }

    if (!p1Query.value(1).isNull()) {
        gameSetup->isCpu[1] = true;
        gameSetup->level[1] = p1Query.value(2).toInt();
        gameSetup->player1.append(" (CPU: level ")
                .append(QString::number(gameSetup->level[1]))
                .append(")");
    }
}

void GameDatabase::saveGame(NewGameSetup *gameSetup)
{
    QString player0(gameSetup->player0);
    QString player1(gameSetup->player1);
    player0.remove(cpuRegExp);
    player1.remove(cpuRegExp);

    QSqlQuery player0IdQuery = database.exec(
            "select oid from players where name='"
            + player0 + "'"
       );

    QSqlQuery player1IdQuery = database.exec(
            "select oid from players where name='"
            + player1 + "'"
       );

    player0IdQuery.next();
    player1IdQuery.next();
    QString player0Id = gameSetup->startPlayer==0 ?  player0IdQuery.value(0).toString() : player1IdQuery.value(0).toString();
    QString player1Id = gameSetup->startPlayer==0 ?  player1IdQuery.value(0).toString() : player0IdQuery.value(0).toString();

    QString queryString =
            "insert into games "
            "(player0, player1, movehistory, moves, startplayer, finished, datum, columns, rows) "
            "values ("
            + player0Id + ","
            + player1Id + ",'"
            + gameSetup->moveHistory + "',"
            + QString::number(gameSetup->moves) + ","
            + QString::number(gameSetup->startPlayer) + ","
            + QString::number(gameSetup->finished) + ","
            + "datetime(),"
            + QString::number(gameSetup->columns) + ","
            + QString::number(gameSetup->rows) + ")"
        ;

    database.exec(queryString);
}

void GameDatabase::addPlayer(const QString & name, bool isCpu, int level)
{
    if (!name.isEmpty()) {
        if (isCpu) {
            database.exec("insert into players (name, iscpu, level) values ('"
                + name + "', 1, " + QString::number(level) + ')'
            );
        }else{
            database.exec( "insert into players (name) values ('" + name + "')" );
        }
    }
}
