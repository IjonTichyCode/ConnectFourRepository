#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NewGameDialog.h"
#include "sqladminframe.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRegExp>
#include <QPrintDialog>
#include <QPrinter>

#include <QDebug>

#include <QtSql/QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameSetup(NULL),
    gameDatabase(NULL)
{
    ui->setupUi(this);

    ui->gameView->setMainWindow(this);

    this->setWindowTitle(tr("Connect Four"));
    //ui->statusBar->hide();

    gameDatabase = new GameDatabase(this);

    SQLAdminFrame * sqlAdminFrame = new SQLAdminFrame(ui->pageSqlAdmin);
    sqlAdminFrame->setGameDatabase(gameDatabase);
    sqlAdminFrame->show();

    ui->highscoreTableView->setGameDatabase(gameDatabase);
    ui->loadGameTableView->setGameDatabase(gameDatabase);

    QVBoxLayout * centralWidgetLayout = new QVBoxLayout();
//    centralWidgetLayout->setAlignment(Qt::AlignCenter);
    centralWidgetLayout->addWidget(ui->stackedWidget);
    ui->centralWidget->setLayout(centralWidgetLayout);

    QVBoxLayout * pageHighscoreLayout = new QVBoxLayout();
//    pageHighscoreLayout->addWidget(ui->highscoreTableView, 0,0);
    pageHighscoreLayout->addWidget(ui->highscoreTableView);
    ui->pageHighscore->setLayout(pageHighscoreLayout);

    QVBoxLayout * pageLoadGameLayout = new QVBoxLayout();
    pageLoadGameLayout->addWidget(ui->loadGameTableView);
    ui->pageLoadGame->setLayout(pageLoadGameLayout);

    QVBoxLayout * pageGameViewLayout = new QVBoxLayout();
    pageGameViewLayout->addWidget(ui->gameView);
    ui->pageGameView->setLayout(pageGameViewLayout);

    ui->loadGameTableView->setMainWindow(this);
    ui->centralWidget->show();

    QActionGroup * designGroup = new QActionGroup(ui->menuOptions);
    designGroup->addAction(ui->actionSvg_Design);
    designGroup->addAction(ui->actionPrimitives_Design);
    designGroup->addAction(ui->actionSimple_Design);

    qDebug() << ui->centralWidget->size();

    qDebug() << QSqlDatabase::drivers();

}

MainWindow::~MainWindow()
{
    if (gameSetup) delete gameSetup;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    //ui->gameView->resize(event->size());
    //ui->stackedWidget->resize(event->size());
}



QMessageBox::StandardButton MainWindow::showSaveGameMessageBox()
{
    return QMessageBox::question(this, tr("Save game"),
            tr("Do you want to save the current game?"),
            QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
}

void MainWindow::toggleFullscreen(bool mode)
{
    if (mode) {
        showFullScreen();

    }else{
        showNormal();
    }
}

void MainWindow::openNewGameDialog()
{
    NewGameDialog * dialog = new NewGameDialog(this);
    NewGameSetup * gameSetup = new NewGameSetup();

    dialog->setGameDatabase(gameDatabase);
    dialog->setSetupData(gameSetup);

    int newGameResult = dialog->exec();

    if (newGameResult == QDialog::Accepted) {
        newGame(gameSetup);
    }else{
        delete gameSetup;
    }
}


void MainWindow::newGame(NewGameSetup * gameSetup)
{
    // if another game is in progress ask to save it
    if (gameSetup!=this->gameSetup && this->gameSetup!=NULL) {
        QMessageBox::StandardButton reply = showSaveGameMessageBox();

        if (reply==QMessageBox::Cancel) {
            delete gameSetup;
            return;
        }else if (reply==QMessageBox::Yes) {
            saveGame();
        }

        delete this->gameSetup;

    }
    this->gameSetup = gameSetup;
    ui->gameView->setGameSetup(gameSetup);
    ui->gameView->setFocus();
    ui->gameView->show();
    ui->actionGame_board->setEnabled(true);
    ui->actionSave_game->setEnabled(true);

    ui->stackedWidget->setCurrentWidget(ui->pageGameView);
}

void MainWindow::setStatusMessage(const QString & msg)
{
    ui->statusBar->showMessage(msg);
}


void MainWindow::openHighscore()
{
    ui->stackedWidget->setCurrentWidget(ui->pageHighscore);
}

void MainWindow::openLoadGame()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLoadGame);
}

void MainWindow::openGameBoard()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGameView);
}

void MainWindow::printHighscore()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()==QDialog::Accepted) {
        QPainter painter(&printer);
        QPixmap pixmap = QPixmap::grabWidget(ui->highscoreTableView);
        painter.drawPixmap(0,0,pixmap);
    }
}

void MainWindow::saveGame()
{
    if (gameSetup) {
        gameDatabase->saveGame(gameSetup);

        // updates games for Highscore and Loading games
        ui->loadGameTableView->setGameDatabase(gameDatabase);
        ui->highscoreTableView->setGameDatabase(gameDatabase);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //QSettings settings("MyCompany", "MyApp");
    //settings.setValue("geometry", saveGeometry());
    //settings.setValue("windowState", saveState());
    if (gameSetup && gameSetup->finished==0) {
        QMessageBox::StandardButton reply = showSaveGameMessageBox();
        if (reply==QMessageBox::Cancel) {
            event->ignore();
            return;
        }else if (reply==QMessageBox::Yes) {
            gameDatabase->saveGame(gameSetup);
        }

    }
    QMainWindow::closeEvent(event);
}


