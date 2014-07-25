/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "LoadGameTableView.h"
#include "gameview.h"
#include "highscoretableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionToggle_Fullscreen;
    QAction *actionNew_Game;
    QAction *actionHighscore;
    QAction *actionLoad_game;
    QAction *actionSave_game;
    QAction *actionExit;
    QAction *actionGame_board;
    QAction *actionPrimitives_Design;
    QAction *actionSimple_Design;
    QAction *actionSvg_Design;
    QAction *actionPrint_higscore;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *pageGameView;
    GameView *gameView;
    QWidget *pageHighscore;
    HighscoreTableView *highscoreTableView;
    QWidget *pageLoadGame;
    LoadGameTableView *loadGameTableView;
    QWidget *pageSqlAdmin;
    QMenuBar *menuBar;
    QMenu *menuConnect_Four;
    QMenu *menuOptions;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(733, 381);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionToggle_Fullscreen = new QAction(MainWindow);
        actionToggle_Fullscreen->setObjectName(QStringLiteral("actionToggle_Fullscreen"));
        actionToggle_Fullscreen->setCheckable(true);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionHighscore = new QAction(MainWindow);
        actionHighscore->setObjectName(QStringLiteral("actionHighscore"));
        actionLoad_game = new QAction(MainWindow);
        actionLoad_game->setObjectName(QStringLiteral("actionLoad_game"));
        actionSave_game = new QAction(MainWindow);
        actionSave_game->setObjectName(QStringLiteral("actionSave_game"));
        actionSave_game->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionGame_board = new QAction(MainWindow);
        actionGame_board->setObjectName(QStringLiteral("actionGame_board"));
        actionGame_board->setEnabled(false);
        actionPrimitives_Design = new QAction(MainWindow);
        actionPrimitives_Design->setObjectName(QStringLiteral("actionPrimitives_Design"));
        actionPrimitives_Design->setCheckable(true);
        actionSimple_Design = new QAction(MainWindow);
        actionSimple_Design->setObjectName(QStringLiteral("actionSimple_Design"));
        actionSimple_Design->setCheckable(true);
        actionSimple_Design->setChecked(true);
        actionSvg_Design = new QAction(MainWindow);
        actionSvg_Design->setObjectName(QStringLiteral("actionSvg_Design"));
        actionSvg_Design->setCheckable(true);
        actionPrint_higscore = new QAction(MainWindow);
        actionPrint_higscore->setObjectName(QStringLiteral("actionPrint_higscore"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAcceptDrops(false);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(43, 9, 431, 261));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setFrameShadow(QFrame::Plain);
        pageGameView = new QWidget();
        pageGameView->setObjectName(QStringLiteral("pageGameView"));
        sizePolicy.setHeightForWidth(pageGameView->sizePolicy().hasHeightForWidth());
        pageGameView->setSizePolicy(sizePolicy);
        gameView = new GameView(pageGameView);
        gameView->setObjectName(QStringLiteral("gameView"));
        gameView->setGeometry(QRect(0, 0, 101, 101));
        sizePolicy1.setHeightForWidth(gameView->sizePolicy().hasHeightForWidth());
        gameView->setSizePolicy(sizePolicy1);
        gameView->setLayoutDirection(Qt::LeftToRight);
        gameView->setRenderHints(QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        gameView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        stackedWidget->addWidget(pageGameView);
        pageHighscore = new QWidget();
        pageHighscore->setObjectName(QStringLiteral("pageHighscore"));
        sizePolicy1.setHeightForWidth(pageHighscore->sizePolicy().hasHeightForWidth());
        pageHighscore->setSizePolicy(sizePolicy1);
        highscoreTableView = new HighscoreTableView(pageHighscore);
        highscoreTableView->setObjectName(QStringLiteral("highscoreTableView"));
        highscoreTableView->setGeometry(QRect(10, 10, 271, 161));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(highscoreTableView->sizePolicy().hasHeightForWidth());
        highscoreTableView->setSizePolicy(sizePolicy2);
        stackedWidget->addWidget(pageHighscore);
        pageLoadGame = new QWidget();
        pageLoadGame->setObjectName(QStringLiteral("pageLoadGame"));
        sizePolicy.setHeightForWidth(pageLoadGame->sizePolicy().hasHeightForWidth());
        pageLoadGame->setSizePolicy(sizePolicy);
        loadGameTableView = new LoadGameTableView(pageLoadGame);
        loadGameTableView->setObjectName(QStringLiteral("loadGameTableView"));
        loadGameTableView->setGeometry(QRect(10, 20, 256, 192));
        stackedWidget->addWidget(pageLoadGame);
        pageSqlAdmin = new QWidget();
        pageSqlAdmin->setObjectName(QStringLiteral("pageSqlAdmin"));
        stackedWidget->addWidget(pageSqlAdmin);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 733, 21));
        menuConnect_Four = new QMenu(menuBar);
        menuConnect_Four->setObjectName(QStringLiteral("menuConnect_Four"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConnect_Four->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuConnect_Four->addAction(actionNew_Game);
        menuConnect_Four->addAction(actionLoad_game);
        menuConnect_Four->addAction(actionSave_game);
        menuConnect_Four->addSeparator();
        menuConnect_Four->addAction(actionPrint_higscore);
        menuConnect_Four->addSeparator();
        menuConnect_Four->addAction(actionExit);
        menuOptions->addAction(actionToggle_Fullscreen);
        menuOptions->addSeparator();
        menuOptions->addAction(actionPrimitives_Design);
        menuOptions->addAction(actionSimple_Design);
        menuOptions->addAction(actionSvg_Design);
        menuView->addAction(actionHighscore);
        menuView->addAction(actionGame_board);

        retranslateUi(MainWindow);
        QObject::connect(actionNew_Game, SIGNAL(triggered()), MainWindow, SLOT(openNewGameDialog()));
        QObject::connect(actionHighscore, SIGNAL(triggered()), MainWindow, SLOT(openHighscore()));
        QObject::connect(actionLoad_game, SIGNAL(triggered()), MainWindow, SLOT(openLoadGame()));
        QObject::connect(actionSave_game, SIGNAL(triggered()), MainWindow, SLOT(saveGame()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionPrimitives_Design, SIGNAL(toggled(bool)), gameView, SLOT(selectPrimitivesDesign(bool)));
        QObject::connect(actionSimple_Design, SIGNAL(toggled(bool)), gameView, SLOT(selectSimpleDesign(bool)));
        QObject::connect(actionSvg_Design, SIGNAL(toggled(bool)), gameView, SLOT(selectSvgDesign(bool)));
        QObject::connect(actionToggle_Fullscreen, SIGNAL(toggled(bool)), MainWindow, SLOT(toggleFullscreen(bool)));
        QObject::connect(actionGame_board, SIGNAL(triggered()), MainWindow, SLOT(openGameBoard()));
        QObject::connect(actionPrint_higscore, SIGNAL(triggered()), MainWindow, SLOT(printHighscore()));

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Connect Four", 0));
        actionToggle_Fullscreen->setText(QApplication::translate("MainWindow", "Toggle Fullscreen", 0));
        actionToggle_Fullscreen->setShortcut(QApplication::translate("MainWindow", "Alt+Return", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionHighscore->setText(QApplication::translate("MainWindow", "Highscore", 0));
        actionLoad_game->setText(QApplication::translate("MainWindow", "Load game", 0));
        actionSave_game->setText(QApplication::translate("MainWindow", "Save game", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionGame_board->setText(QApplication::translate("MainWindow", "Game board", 0));
        actionPrimitives_Design->setText(QApplication::translate("MainWindow", "Abstract Design", 0));
        actionSimple_Design->setText(QApplication::translate("MainWindow", "Simple Design", 0));
        actionSvg_Design->setText(QApplication::translate("MainWindow", "Fancy Design", 0));
        actionPrint_higscore->setText(QApplication::translate("MainWindow", "Print higscore", 0));
        menuConnect_Four->setTitle(QApplication::translate("MainWindow", "Connect Four", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
