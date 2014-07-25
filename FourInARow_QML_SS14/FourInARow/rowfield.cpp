#include "rowfield.h"
#include <cstdlib>
#include <QDebug>

RowField::RowField(int columns, int rows):
//    TOKENMASK(0x0F),
//    OWNERMASK(0xF0),
//    WHITE_FLAG (0x10),
//    BLACK_FLAG (0x20),
//    SHARED_FLAG(0x40),
    TOKENCOUNT_MASK(0x03),
    rows(rows),
    columns(columns)
{
    init();
}

RowField::RowField(const RowField &rowField):
//    OWNERMASK(0xF0),
//    TOKENMASK(0x0F),
//    WHITE_FLAG (0x10),
//    BLACK_FLAG (0x20),
//    SHARED_FLAG(0x40),
    TOKENCOUNT_MASK(0x03),
    rows(rowField.rows),
    columns(rowField.columns)
{
    qDebug() << "rowfield CC";
    init();
//    for (int rowI=0; rowI<rows; ++rowI) {
//        for (int colI=0; colI<columns; ++colI) {
//            for (int angleI=0; angleI<4; ++angleI) {
//                field[rowI][colI][angleI] = rowField.field[rowI][colI][angleI];
//            }
//        }
//    }

    //******************

    for (int row=0; row<rows; ++row) {
        for (int col=0; col<columns-3; ++col) {
            horizontalRows[row][col] = rowField.horizontalRows[row][col];
        }
    }
    for (int row=0; row<rows-3; ++row) {

        for (int col=0; col<columns; ++col) {
            verticalRows[row][col] = rowField.verticalRows[row][col];
        }

        for (int col=0; col<columns-3; ++col) {
            diagonalTopRightRows[row][col] = rowField.diagonalTopRightRows[row][col];
            diagonalBottomRightRows[row][col] = rowField.diagonalBottomRightRows[row][col];
        }
    }


}

RowField::~RowField()
{
//    delete[] angleRowOffsets;
//    delete[] angleColOffsets;

//    for (int i=0; i<rows; ++i) {
//        for (int j=0; j<columns; ++j) {
//            delete[] field[i][j];
//        }
//        delete[] field[i];
//    }
//    delete[] field;

    //**************************

    for (int i=0; i<rows; ++i) {
        delete[] horizontalRows;
    }

    for (int i=0; i<rows-3; ++i) {
        delete[] verticalRows;
        delete[] diagonalTopRightRows;
        delete[] diagonalBottomRightRows;
    }

}


bool RowField::addToken(int player, int column, int row)
{

//    unsigned char playerFlag = player==0 ? WHITE_FLAG : BLACK_FLAG;
//    unsigned char otherPlayerFlag = player==0 ? BLACK_FLAG : WHITE_FLAG;

//    for (int angle=0; angle<4; ++angle) {

//        for (int tokenPosition=0; tokenPosition<4; ++tokenPosition) {
//            int colIndex = column + angleColOffsets[angle] * tokenPosition;
//            int rowIndex = row + angleRowOffsets[angle] * tokenPosition;

//            if (colIndex>=0 && colIndex<columns && rowIndex>=0 && rowIndex<rows) {
//                unsigned char * subField = field[rowIndex][colIndex];

//                if (subField[angle] & (otherPlayerFlag | SHARED_FLAG)) {
//                    subField[angle] = SHARED_FLAG;

//                }else{
//                    unsigned char tokenCount = subField[angle] & TOKENMASK;
//                    ++tokenCount;
//                    subField[angle] = tokenCount | playerFlag;


//                    if (tokenCount>=4) {
//                        for (int winToken = 0; winToken<4; ++winToken) {
//                            winRow[winToken*2] = -winToken * angleColOffsets[angle] + colIndex;
//                            winRow[winToken*2+1] = -winToken * angleRowOffsets[angle] + rowIndex;
//                        }

//                        return true;
//                    }
//                }
//            }
//        }

//    }
//    return false;


    //******************

    int x = (column<columns-3 ? column : columns-4);
    int y = (row<rows-3 ? row : rows-4);

    int xOff = column-x;
    int yOff = row-y;

    for ( ; x>column-4 && x>=0; --x) {
        qDebug() << ((unsigned char)(horizontalRows[row][x] >> plShift[player]) & TOKENCOUNT_MASK);
        if ( ((horizontalRows[row][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            return true;
        }else{
            horizontalRows[row][x] += plMultiplier[player];
        }

    }

    for ( ; y>row-4 && y>=0; --y) {
        qDebug() << ((unsigned char)(verticalRows[y][column] >> plShift[player]) & TOKENCOUNT_MASK);
        if ( ((verticalRows[y][column] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            return true;
        }else{
            verticalRows[y][column] += plMultiplier[player];
        }
    }

    int off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row-off;
    for ( ; x>column-4 && y>=0 && x>=0; --x, --y) {
        qDebug() << ((unsigned char)(diagonalTopRightRows[y][x] >> plShift[player]) & TOKENCOUNT_MASK);
        if ( ((diagonalTopRightRows[y][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            return true;
        }else{
            diagonalTopRightRows[y][x] += plMultiplier[player];
        }
    }

    //************** bottom right
    y = (row>2 ? row : 3);
    yOff = y-row;
    off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row+off;

    for ( ; x>column-4 && x>=0 && y<rows; --x, ++y) {
        qDebug() << ((unsigned char)(diagonalBottomRightRows[y-3][x] >> plShift[player]) & TOKENCOUNT_MASK);
        if ( ((diagonalBottomRightRows[y-3][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            return true;
        }else{
            diagonalBottomRightRows[y-3][x] += plMultiplier[player];
        }
    }

    return false;

}

int * RowField::getWinRow()
{
    return winRow;
}

void RowField::init()
{
//    field = new unsigned char**[rows];
//    for (int rowI=0; rowI<rows; ++rowI) {
//        field[rowI] = new unsigned char*[columns];

//        for (int colI=0; colI<columns; ++colI) {
//            field[rowI][colI] = new unsigned char[4];

//            for (int angleI=0; angleI<4; ++angleI) {
//                field[rowI][colI][angleI] = 0;
//            }
//        }
//    }

//    angleColOffsets = new int[4];
//    angleColOffsets[0] = 0;
//    angleColOffsets[1] = -1;
//    angleColOffsets[2] = -1;
//    angleColOffsets[3] = -1;

//    angleRowOffsets = new int[4];
//    angleRowOffsets[0] = -1;
//    angleRowOffsets[1] = -1;
//    angleRowOffsets[2] = 0;
//    angleRowOffsets[3] = 1;

    //******************

    horizontalRows = new unsigned char*[rows];
    for (int row=0; row<rows; ++row) {
        horizontalRows[row] = new unsigned char[columns-3];
        for (int col=0; col<columns-3; ++col) {
            horizontalRows[row][col] = 0;
        }
    }

    verticalRows = new unsigned char*[rows-3];
    diagonalTopRightRows = new unsigned char*[rows-3];
    diagonalBottomRightRows = new unsigned char*[rows-3];

    for (int row=0; row<rows-3; ++row) {
        verticalRows[row] = new unsigned char[columns];
        for (int col=0; col<columns; ++col) {
            verticalRows[row][col] = 0;
        }

        diagonalTopRightRows[row] = new unsigned char[columns-3];
        diagonalBottomRightRows[row] = new unsigned char[columns-3];
        for (int col=0; col<columns-3; ++col) {
            diagonalTopRightRows[row][col] = 0;
            diagonalBottomRightRows[row][col] = 0;
        }
    }

    plMultiplier[0] = 1;
    plMultiplier[1] = 4;

    plShift[0] = 0;
    plShift[1] = 2;

}
