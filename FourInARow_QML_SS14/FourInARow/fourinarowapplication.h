#ifndef FOURINAROWAPPLICATION_H
#define FOURINAROWAPPLICATION_H

#include <QLocale>
#include <QGuiApplication>
#include <QTranslator>

#include "FIARNetworkGame.h"
#include "GameSetup.h"
#include "FiarGameListener.h"


/**
 * @brief The FourInARowApplication is the Initialisationclass of this Program.
 * It initializes all Objects needed to start the program appropriate.
 * While running the Program, the current FourInARowGame and the GameListener can be received by this.
 * Since FourInARowApplication is the core class of the program only one instance will be created and it
 * is implemented as a Singleton class.
 */
class FourInARowApplication
{
public:

    /**
     * @brief getInstance Receive the current instance of this class.
     * Will create an instance if not already exists.
     * @return
     */
    static FourInARowApplication * getInstance();
    ~FourInARowApplication();

    /**
     * @brief exec Execute the main application. This method will run until the application is closed.
     * @param argc Command line argument count
     * @param argv Command line arguments
     * @return
     */
    int exec(int & argc, char ** argv);

    /**
     * @brief getGame Return the current FiarInARowGame
     * @return current game, NULL if not existing
     */
    FIARNetworkGame * getGame();

    /**
     * @brief setGame Set the passed game as the current game->
     * @param newGame
     */
    void setGame(FIARNetworkGame * newGame);

    /**
     * @brief setGameListener Set the gameListener which is looked up by the FIARNetworkGame
     * This should be done by the GUI, so the GUI can receive changes in the game.
     * @param gameListener
     */
    void setGameListener(FiarGameListener * gameListener);

    /**
     * @brief setLanguage Sets the language of the application.
     * Only English and German are supported.
     * @param language language as int index. 0=German, 1=English
     */
    void setLanguage(int language);

    /**
     * @brief getGameListener Get a reference to the GameListener.
     * This is called by the current FIARNetworkGame to get the GameListener to publish
     * game changes.
     * @return
     */
    const FiarGameListener & getGameListener() const;

private:
    /**
     * @brief FourInARowApplication Constructor is private to ensure only one instance can be created
     * by getInstance()
     */
    FourInARowApplication();

    static FourInARowApplication * instance;
    FIARNetworkGame * game;

    /** The Game Listener is only registered at the FourInARowApplication class, not the owner.
     * @brief gameListener
     */
    FiarGameListener * gameListener;
    QLocale germanLocal;
    QLocale englishLocale;
    QTranslator ukTranslator;
    QTranslator deTranslator;
    QGuiApplication * app;

};

#endif // FOURINAROWAPPLICATION_H
