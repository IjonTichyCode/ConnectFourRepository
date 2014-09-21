#include "FiarGameListenerForQMLGui.h"

FiarGameListenerForQMLGui::FiarGameListenerForQMLGui(QMLPlayScreen * gui):
    gui(gui)
{
}

void FiarGameListenerForQMLGui::tokenAdded(int player, int column, int row) const
{
    gui->gameTokenAdded(player, column, row);
}

void FiarGameListenerForQMLGui::playersTurn(int player, int time) const
{
    gui->gamePlayersTurn(player, time);
}

void FiarGameListenerForQMLGui::playerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3) const
{
    gui->gamePlayerWon(player, col0,row0, col1, row1, col2, row2, col3, row3);
}

void FiarGameListenerForQMLGui::gameEndedDrawn() const
{
    gui->gameEndedDrawn();
}

void FiarGameListenerForQMLGui::triedIllegalColumn(int player, int column) const
{
    gui->gameTriedIllegalColumn(player, column);
}

void FiarGameListenerForQMLGui::triedFullColumn(int player, int column) const
{
    gui->gameTriedFullColumn(player, column);
}
