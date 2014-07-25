#include "LoadGameTableView.h"
#include <QDebug>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "TablePushButton.h"

LoadGameTableView::LoadGameTableView(QWidget *parent) :
    QTableView(parent)
{
}

LoadGameTableView::~LoadGameTableView()
{
    if (this->model()) delete this->model();
}

void LoadGameTableView::setGameDatabase(GameDatabase *database)
{
    this->gameDatabase = database;
    if (this->model()) delete this->model();

    QSqlQueryModel * model = new QSqlQueryModel(this);
    database->getSavedGames(model);
    model->setHeaderData(0, Qt::Horizontal, tr("Game Date"));
    model->setHeaderData(1, Qt::Horizontal, tr("Game Time"));
    model->setHeaderData(2, Qt::Horizontal, tr("Player 1"));
    model->setHeaderData(3, Qt::Horizontal, tr("Player 2"));
    model->insertColumn(5);
    model->setHeaderData(4, Qt::Horizontal, "");

    setModel(model);

    for (int i=0; i<model->rowCount(); ++i) {
        qDebug() << "i";
        TablePushButton * button = new TablePushButton(model->record(i).value(4).toInt(), "Load game", this);
        connect( button, SIGNAL(emitIndex(int)), this, SLOT(loadGame(int)) );
        setIndexWidget(model->index(i, 5), button);
    }

    model->removeColumn(4);
    setModel(model);

    show();
}

void LoadGameTableView::loadGame(int index)
{
    NewGameSetup * gameSetup = new NewGameSetup();
    gameDatabase->loadGame(index, gameSetup);
    mainWindow->newGame(gameSetup);
}

void LoadGameTableView::setMainWindow(MainWindow * mainWindow)
{
    this->mainWindow = mainWindow;
}
