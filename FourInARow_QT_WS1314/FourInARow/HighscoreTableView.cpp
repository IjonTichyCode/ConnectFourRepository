#include "HighscoreTableView.h"

#include <QSqlQueryModel>


HighscoreTableView::HighscoreTableView(QWidget *parent) :
    QTableView(parent),
    gameDatabase(NULL)
{
}

HighscoreTableView::~HighscoreTableView()
{
    if (this->model()) delete this->model();
}

void HighscoreTableView::setGameDatabase(GameDatabase * database)
{
    this->gameDatabase = database;
    if (this->model()) delete this->model();

    QSqlQueryModel * model = new QSqlQueryModel();
    database->getHighscore(model);

    model->setHeaderData(0, Qt::Horizontal, tr("Winner"));
    model->setHeaderData(1, Qt::Horizontal, tr("Loser"));
    model->setHeaderData(2, Qt::Horizontal, tr("Moves count"));

    setModel(model);
    show();
}
