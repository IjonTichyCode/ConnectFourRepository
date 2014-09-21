#ifndef ROWFIELD_H
#define ROWFIELD_H



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

/**
 * @brief The RowField class represents a set of all possible
 * 4 token rows. Each entry in the rowfield contains information
 * about the number of tokens already in it and which player´s tokens
 * are occupieing the row.
 * The token number is only valid as long as the row is occupied by only
 * one player.
 */
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
     * @brief addToken Updates the rowfield with a new token and updates the rowfield value.
     * @param player player, who adds this token [0,1]
     * @param column
     * @param row
     * @return true: this tokens completes a 4 token row
     */
    bool addToken(int player, int column, int row);

    /**
     * @brief removeToken Removes the specified token and updates the rowfield value.
     * @param player owner of the token
     * @param column column of the token
     * @param row row of the token
     */
    void removeToken(int player, int column, int row);

    /**
     * @brief getWinRow Returns an int Array with the positions of each Token in the winning row,
     * if a winning row exists (the game is ended). Otherwise the values are not defined.
     * @return winning row in columnIndex, rowIndex pairs (col0, row0, col1, row1...
     */
    int * getWinRow();

    /**
     * @brief getColumns Get the number of columns of the board this rowfield represents
     * @return columns
     */
    int getColumns();

    /**
     * @brief getRows Get the number of rows of the board this rowfield represents
     * @return rows
     */
    int getRows();

    /**
     * @brief getValue Returns a value evaluating this rowfield, where smaller values (negative) are
     * good for player 0 and greater values are good for player 1.
     * @return
     */
    int getValue();

private:
    /**
     * @brief init helping method for the constructor
     */
    void init();

    unsigned char ** horizontalRows;
    unsigned char ** verticalRows;
    unsigned char ** diagonalTopRightRows;
    unsigned char ** diagonalBottomRightRows;

    const unsigned char TOKENCOUNT_MASK;

    // since the number of tokens of a each player in a row are stored in different bit ranges,
    // increasing or decreasing the token number has to be done with a multiplier.
    // example: player 1 is stored with 3rd and 4th bit -- so to add a single token to a row +4 has to be added to the row
    /*const*/ unsigned char plMultiplier[2];
    /*const*/ int plShift[2];

    int winRow[8];
    int rows;
    int columns;
    int value;

    inline int getValue(unsigned char & row);
};

#endif // ROWFIELD_H
