#include "fourinarowgame.h"
#include <cmath>


FourInARowGame::FourInARowGame(int startPlayer):
    board(startPlayer, 7, 6),
    gameFinished(false),
    fullColumns(0),
    allColumnsFullMask(1),
    latestTokenRow(0)
{
    allColumnsFullMask <<= 7;
    allColumnsFullMask -= 1;
}

FourInARowGame::FourInARowGame(int startPlayer, int columns, int rows):
    board(startPlayer, columns, rows),
    gameFinished(false),
    fullColumns(0),
    allColumnsFullMask(1)
{
    allColumnsFullMask <<= columns;
    allColumnsFullMask -= 1;
}

int FourInARowGame::getPlayerToMoveNext () const {
    return board.nextPlayer;
}

MoveResult FourInARowGame::move(int column) {

    if (column>=board.columnCount || column<0) {
        return MoveResult::INVALID_COLUMN;
    }

    const unsigned short one = 1;
    unsigned short oldColumnTotal = board.blackTokens[column] | board.whiteTokens[column];

    if ( (board.fullColumnMask & (~oldColumnTotal)) == 0) {
        return MoveResult::FULL_COLUMN;
    }

    // create bitmask with only one bit set at the new column highest position.
    // 1st shift one left, 2nd negate all bits lower than the left most
    unsigned short newToken = ((oldColumnTotal<<1) | one) ^ oldColumnTotal ;
    unsigned short * currentPlayerTokens  = (board.nextPlayer==0) ? board.whiteTokens : board.blackTokens;

    // add the new bit to the current players chosen column bitmask
    currentPlayerTokens[column] |= newToken;

//    const double log2 = log(2);
//    latestTokenRow = (int)(log(newToken)/log2);

    for (latestTokenRow=0; newToken>0; ++latestTokenRow) {
        newToken >>= 1;
    }
    --latestTokenRow;


    if (board.rowField.addToken(board.nextPlayer, column, latestTokenRow ) ) {
        gameFinished = true;
        return MoveResult::WIN;

    }else{
        if (latestTokenRow >= board.rowCount-1) {
            unsigned short one = 1;
            one <<= column;
            fullColumns |= one;
            if ( !(fullColumns^allColumnsFullMask) ) {
                return MoveResult::TIE;
            }
        }
    }

    ++board.nextPlayer;
    board.nextPlayer %= 2;

    return MoveResult::SUCCESS;
}

int FourInARowGame::getColumnCount() const {
    return board.columnCount;
}

int FourInARowGame::getRowCount() const {
    return board.rowCount;
}

int FourInARowGame::getLatestTokenRow() const
{
    return latestTokenRow;
}


FourInARowBoard * FourInARowGame::getBoard()
{
    return &board;
}

int * FourInARowGame::getWinRow()
{
    return board.rowField.getWinRow();
}

bool FourInARowGame::isFinished()
{
    return gameFinished;
}
