#ifndef ROWFIELD_H
#define ROWFIELD_H

/**
 * @brief The RowField class represents a set of all possible
 * 4 token rows. Each entry in the rowfield contains information
 * about the number of tokens already in it and which player´s tokens
 * are occupieing the row.
 * The token number is only valid as long as the row is occupied by only
 * one player.
 */

// each column/row combination contains up to 4 potential starting positions for rows
// o - starting position
// x - remaining 3 tokens of a row

// #       #
// #       #
// #  x    #
// #  x    #
// #  x    #
// #  o    #
// #########

// #       #
// #       #
// #       #
// #   x   #
// #  x    #
// # x     #
// #o      #
// #########

// #       #
// #       #
// #       #
// #       #
// #       #
// # oxxx  #
// #########

// #       #
// #       #
// #  o    #
// #   x   #
// #    x  #
// #     x #
// #########
class RowField
{
public:

    /**
     * @brief RowField - constructor - creates an  empty rowfield of given size.
     * @param columns
     * @param rows
     */
    RowField(int columns, int rows);
    RowField(const RowField & rowField);
    ~RowField();

    /**
     * @brief addToken Updates the rowfield with a new token.
     * @param player player, who adds this token [0,1]
     * @param column
     * @param row
     * @return true: this tokens completes a 4 token row
     */
    bool addToken(int player, int column, int row);

    /**
     * @brief getWinRow Returns an int Array with the positions of each Token in the winning row,
     * if a winning row exists (the game is ended). Otherwise the values are not defined.
     * @return winning row in columnIndex, rowIndex pairs (col0, row0, col1, row1...
     */
    int * getWinRow();

private:
    void init();

//    unsigned char *** field;

    unsigned char ** horizontalRows;
    unsigned char ** verticalRows;
    unsigned char ** diagonalTopRightRows;
    unsigned char ** diagonalBottomRightRows;

//    // bits of a field entry representing the number of tokens in a row
//    const unsigned char TOKENMASK;
//    // bits of a field entry representing the owner state of the row
//    const unsigned char OWNERMASK;
//    // bit of a field entry representing, that this row is occupied by the white player
//    const unsigned char WHITE_FLAG;
//    // bit of a field entry representing, that this row is occupied by the black player
//    const unsigned char BLACK_FLAG;
//    // bit of a field entry representing, that this row is occupied by both players
//    // row cant become a "FourInARow"
//    const unsigned char SHARED_FLAG;



    // "const" - values have to be set after initialization, because array initialization is not standard for
    // all compilers.
//    /*const*/ int * angleRowOffsets;
//    /*const*/ int * angleColOffsets;


    const unsigned char TOKENCOUNT_MASK;

    // since the number of tokens of a each player in a row are stored in different bit ranges,
    // increasing or decreasing the token number has to be done with a multiplier.
    // example: player 1 is stored with 3rd and 4th bit -- so to add one token 4 has to be added to the row
    /*const*/ unsigned char plMultiplier[2];
    /*const*/ int plShift[2];


    int winRow[8];
    int rows;
    int columns;
};

#endif // ROWFIELD_H
