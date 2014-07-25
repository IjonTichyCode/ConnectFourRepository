#include "fourinarowboard.h"

#include <QDebug>

FourInARowBoard:: FourInARowBoard(int player, int columns, int rows):
    whiteTokens(new unsigned short[columns]),
    blackTokens(new unsigned short[columns]),
    rowField(columns, rows),
    nextPlayer(player),
    columnCount(columns),
    rowCount(rows)
{
    for (int i=0; i<columns; ++i) {
        whiteTokens[i] = 0;
        blackTokens[i] = 0;
    }

    fullColumnMask = 1;
    fullColumnMask <<= rows;
    fullColumnMask -= 1;
}

FourInARowBoard::FourInARowBoard(const FourInARowBoard & board):
    whiteTokens(new unsigned short[board.columnCount]),
    blackTokens(new unsigned short[board.columnCount]),
    rowField(board.rowField),
    nextPlayer(board.nextPlayer),
    columnCount(board.columnCount),
    rowCount(board.rowCount),
    fullColumnMask(board.fullColumnMask)
{
    qDebug() << "board CC";
    for (int i=0; i<columnCount; ++i) {
        whiteTokens[i] = board.whiteTokens[i];
        blackTokens[i] = board.blackTokens[i];
    }
}

FourInARowBoard::~FourInARowBoard()
{
    delete[] whiteTokens;
    delete[] blackTokens;
}
