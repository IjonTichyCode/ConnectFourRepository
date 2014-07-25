#ifndef FOURINAROWGAME_H
#define FOURINAROWGAME_H

#include "fourinarowboard.h"


enum MoveResult {
    SUCCESS,
    WIN,
    TIE,
    INVALID_COLUMN,
    FULL_COLUMN
};

class FourInARowGame
{
public:

    /**
     * @brief FourInARowGame - constructor
     * Creates a FourInARowGame object, represanting the game with standard size of 7 columns and 6 rows.
     * @param startPlayer index of the startPlayer [0,1]
     */
    FourInARowGame(int startPlayer = 0);

    /**
     * @brief FourInARowGame - constructor
     * Creates a FourInARowGame object of custom size.
     * @param startPlayer index of the startPlayer [0,1]
     * @param columns number of columns of the board
     * @param rows number of rows of the board
     */
    FourInARowGame(int startPlayer, int columns, int rows);

    /**
     * @brief getPlayerToMoveNext returns the player, who has to take the next move as an integer [0,1]
     * @return player
     */
    int getPlayerToMoveNext() const;

    /**
     * @brief move tries to put a token into a column of the board.
     * Column indices start with 0 for the left most column.
     * @param column column index
     * @return moveresult - feedback about the move.
     * Only the return code SUCCESS changes the player to move next.
     */
    MoveResult move(int column);

    /**
     * @brief getColumnCount
     * @return
     */
    int getColumnCount() const;

    /**
     * @brief getRowCount
     * @return
     */
    int getRowCount() const;

    /**
     * @brief getLatestTokenRow returns the row of the token added in the latest valid move.
     * @return tokens row
     */
    int getLatestTokenRow() const ;

    /**
     * @brief getBoard returns a pointer to the FourInARowBoard object of this game.
     * @return
     */
    FourInARowBoard * getBoard();

    /**
     * @brief getWinRow Returns an int Array with the positions of each Token in the winning row,
     * if a winning row exists (the game is ended). Otherwise the values are not defined.
     * @return winning row in columnIndex, rowIndex pairs (col0, row0, col1, row1...
     */
    int * getWinRow();

    /**
     * @brief isFinished Checks whether this game is finished
     * @return
     */
    bool isFinished();


private:

    FourInARowBoard board;
    int latestTokenRow;
    bool gameFinished;

    // Bitmask representing the full columns starting with the lowest bit for the left most column
    unsigned short fullColumns;
    // Bitmask representing all columns are full
    unsigned short allColumnsFullMask;
};

#endif // FOURINAROWGAME_H
