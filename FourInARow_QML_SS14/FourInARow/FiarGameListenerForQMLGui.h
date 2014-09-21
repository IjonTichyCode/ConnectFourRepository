#ifndef FIARGAMELISTENERFORQMLGUI_H
#define FIARGAMELISTENERFORQMLGUI_H

#include "QMLPlayScreen.h"
#include "FiarGameListener.h"

/**
 * @brief The FiarGameListenerForQMLGui class implements the abstract FiarGameListener
 * calling related Methods on the QMLPlayScreen object. A reference to a QMLPLayScreen object
 * is set on construction.
 */
class FiarGameListenerForQMLGui : public FiarGameListener
{
public:
    /**
     * @brief FiarGameListenerForQMLGui Constructor
     * @param gui The QMLPlayScreen which should be called by this Listener
     */
    FiarGameListenerForQMLGui(QMLPlayScreen * gui);

    virtual void tokenAdded(int player, int column, int row) const;
    virtual void playersTurn(int player, int time) const;
    virtual void playerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3) const;
    virtual void gameEndedDrawn() const;
    virtual void triedIllegalColumn(int player, int column) const;
    virtual void triedFullColumn(int player, int column) const;

private:
    QMLPlayScreen * gui;

};

#endif // FIARGAMELISTENERFORQMLGUI_H
