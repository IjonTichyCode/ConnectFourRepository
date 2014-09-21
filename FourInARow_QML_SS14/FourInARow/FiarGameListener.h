#ifndef FIARGAMELISTENER_H
#define FIARGAMELISTENER_H

/**
 * @brief The FiarGameListener class allows the game logic to invoke methods indirectly on the GUI, without knowing the GUI
 * FiarGameListener is abstract, a Implementation has to be provided by the GUI, which
 * calls the correct Methods on the GUI
 */
class FiarGameListener
{
public:
    FiarGameListener();

    /**
     * @brief tokenAdded The specified Token has been added to the game
     * @param player player (0 or 1) who added the token
     * @param column column where the token has been placed
     * @param row row where the token has been placed
     */
    virtual void tokenAdded(int player, int column, int row) const = 0;

    /**
     * @brief playersTurn Indicate that the specified players turn begins
     * @param player
     * @param time time to make the turn. If 0 then the player has no time limit
     */
    virtual void playersTurn(int player, int time) const = 0;

    /**
     * @brief playerWon Indicates that the specified player has won the game with the specified row.
     * col0, row0 -- col1, row1 are the positions of the winning row token positions.
     * @param player
     * @param col0
     * @param row0
     * @param col1
     * @param row1
     * @param col2
     * @param row2
     * @param col3
     * @param row3
     */
    virtual void playerWon(int player, int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3) const = 0;

    /**
     * @brief gameEndedDrawn Indicates, that the game ended as a tie
     */
    virtual void gameEndedDrawn() const = 0;

    /**
     * @brief triedIllegalColumn Indicate that the last move tried, was an illegal move.
     * This means usually, that a column that doesn´t exist was tried.
     * @param player Player, who made the move
     * @param column column tried
     */
    virtual void triedIllegalColumn(int player, int column) const = 0;

    /**
     * @brief triedFullColumn Indicates that the last move tried, was on a full column.
     * @param player Player who tried the move
     * @param column Column tried
     */
    virtual void triedFullColumn(int player, int column) const = 0;
};

#endif // FIARGAMELISTENER_H
