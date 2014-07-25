#include "rowfield.h"
#include <cstdlib>
#include <QDebug>

RowField::RowField(int columns, int rows):
    OWNERMASK(0xF0),
    TOKENMASK(0x0F),
    WHITE_FLAG (0x10),
    BLACK_FLAG (0x20),
    SHARED_FLAG(0x40),
    rows(rows),
    columns(columns)
{
    init();
}

RowField::RowField(const RowField &rowField):
    OWNERMASK(0xF0),
    TOKENMASK(0x0F),
    WHITE_FLAG (0x10),
    BLACK_FLAG (0x20),
    SHARED_FLAG(0x40),
    rows(rowField.rows),
    columns(rowField.columns)
{
    qDebug() << "rowfield CC";
    init();
    for (int rowI=0; rowI<rows; ++rowI) {
        for (int colI=0; colI<columns; ++colI) {
            for (int angleI=0; angleI<4; ++angleI) {
                field[rowI][colI][angleI] = rowField.field[rowI][colI][angleI];
            }
        }
    }
}

RowField::~RowField()
{
    delete[] angleRowOffsets;
    delete[] angleColOffsets;

    for (int i=0; i<rows; ++i) {
        for (int j=0; j<columns; ++j) {
            delete[] field[i][j];
        }
        delete[] field[i];
    }
    delete[] field;
}


bool RowField::addToken(int player, int column, int row)
{

    unsigned char playerFlag = player==0 ? WHITE_FLAG : BLACK_FLAG;
    unsigned char otherPlayerFlag = player==0 ? BLACK_FLAG : WHITE_FLAG;

    for (int angle=0; angle<4; ++angle) {

        for (int tokenPosition=0; tokenPosition<4; ++tokenPosition) {
            int colIndex = column + angleColOffsets[angle] * tokenPosition;
            int rowIndex = row + angleRowOffsets[angle] * tokenPosition;

            if (colIndex>=0 && colIndex<columns && rowIndex>=0 && rowIndex<rows) {
                unsigned char * subField = field[rowIndex][colIndex];

                if (subField[angle] & (otherPlayerFlag | SHARED_FLAG)) {
                    subField[angle] = SHARED_FLAG;

                }else{
                    unsigned char tokenCount = subField[angle] & TOKENMASK;
                    ++tokenCount;
                    subField[angle] = tokenCount | playerFlag;


                    if (tokenCount>=4) {
                        for (int winToken = 0; winToken<4; ++winToken) {
                            winRow[winToken*2] = -winToken * angleColOffsets[angle] + colIndex;
                            winRow[winToken*2+1] = -winToken * angleRowOffsets[angle] + rowIndex;
                        }

                        return true;
                    }
                }
            }
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
    field = new unsigned char**[rows];
    for (int rowI=0; rowI<rows; ++rowI) {
        field[rowI] = new unsigned char*[columns];

        for (int colI=0; colI<columns; ++colI) {
            field[rowI][colI] = new unsigned char[4];

            for (int angleI=0; angleI<4; ++angleI) {
                field[rowI][colI][angleI] = 0;
            }
        }
    }

    angleColOffsets = new int[4];
    angleColOffsets[0] = 0;
    angleColOffsets[1] = -1;
    angleColOffsets[2] = -1;
    angleColOffsets[3] = -1;

    angleRowOffsets = new int[4];
    angleRowOffsets[0] = -1;
    angleRowOffsets[1] = -1;
    angleRowOffsets[2] = 0;
    angleRowOffsets[3] = 1;
}
