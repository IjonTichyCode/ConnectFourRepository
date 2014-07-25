#ifndef FOURINAROWBOARD_H
#define FOURINAROWBOARD_H

#include "rowfield.h"

/**
 * @brief The FourInARowBoard class is a data structure holding the whole
 * state of a FourInARowGame. All members are public.
 * Use FourInARowGame to play the game.
 */
class FourInARowBoard
{
public:

    /**
     * @brief FourInARowBoard creates a new board starting with the passed player.
     * Sets the size of the board to the passed parameters
     * @param player starting player [0,1]
     * @param columns number of columns
     * @param rows number of rows
     */
    FourInARowBoard(int player, int columns, int rows);
    FourInARowBoard( const FourInARowBoard & other );


    ~FourInARowBoard();

    /**
     * @brief whiteTokens Points to an array of unsigned shorts.
     * The bits of each element represent the white tokens set on the board.
     * Lowest bit represents the bottom most token.
     */
    unsigned short * whiteTokens;
    /**
     * @brief whiteTokens Points to an array of unsigned shorts.
     * The bits of each element represent the black tokens set on the board.
     * Lowest bit represents the bottom most token.
     */
    unsigned short * blackTokens;

    /**
     * @brief rowField rowfield, which represents this board.
     * Useful for fast check of the results of a move.
     */
    RowField rowField;

    int rowCount;
    int columnCount;
    int nextPlayer;

    /**
     * @brief fullColumnMask Bitmask representing a full column. See whiteTokens, blackTokens.
     */
    unsigned short fullColumnMask;
};

#endif // FOURINAROWBOARD_H
