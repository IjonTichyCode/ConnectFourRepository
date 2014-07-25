#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QRegExp>
#include "NewGameSetup.h"
#include "GameDatabase.h"


namespace Ui {
class NewGameDialog;
}

/**
 * @brief The NewGameDialog class is modal QDialog with GUI elements to configure an new Connect Four game.
 * Two players can be selected, each controlled by a human or computer players.
 * Human or computer players can be created. The level of computer players can be chosen.
 * It can be chosen, which player starts the game.
 */
class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();

    /**
     * @brief setSetupData Set a pointer to a NewGameSetup object, which is configured by the dialog
     * @param data
     */
    virtual void setSetupData(NewGameSetup * data);

    /**
     * @brief setGameDatabase Sets a pointer to the gameDatabase used to get data about existing players.
     * @param gameDatabase
     */
    virtual void setGameDatabase(GameDatabase * gameDatabase);

public slots:

    /**
     * @brief Creates a new player based on the current state of the dialog.
     * No player is created, if no player name was typed by the user.
     */
    virtual void createPlayer();

    /**
     * @brief player0Begins finishes the dialog with the configurations made and
     * starts the game with player 0.
     */
    virtual void player0Begins();

    /**
     * @brief player1Begins finishes the dialog with the configurations made and
     * starts the game with player 1.
     */
    virtual void player1Begins();

    /**
     * @brief cpuLvlSliderEnable enable/disable the slider. Slider is only enabled,
     * if CPU player is selected
     * @param state
     */
    virtual void cpuLvlSliderEnable(int state);

private:
    virtual void begin(int startPlayer);

    Ui::NewGameDialog * ui;
    NewGameSetup * setupData;
    GameDatabase * gameDatabase;

    const QRegExp cpuRegExp;
};

#endif // NEWGAMEDIALOG_H
