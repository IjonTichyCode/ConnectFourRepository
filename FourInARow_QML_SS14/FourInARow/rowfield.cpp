#include "rowfield.h"
#include <cstdlib>
#include <QDebug>

RowField::RowField(int columns, int rows):
    TOKENCOUNT_MASK(0x03),
    rows(rows),
    columns(columns),
    value(0)
{
    init();
}

RowField::RowField(const RowField & rowField):
    TOKENCOUNT_MASK(0x03),
    rows(rowField.rows),
    columns(rowField.columns),
    value(rowField.value)
{
    qDebug() << "rowfield CC";
    init();

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
    //******************

    int x = (column<columns-3 ? column : columns-4);
    int y = (row<rows-3 ? row : rows-4);

    int xOff = column-x;
    int yOff = row-y;

    for ( ; x>column-4 && x>=0; --x) {

        if ( ((horizontalRows[row][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            winRow[0]=x; winRow[1]=row;
            winRow[2]=x+1; winRow[3]=row;
            winRow[4]=x+2; winRow[5]=row;
            winRow[6]=x+3; winRow[7]=row;
            return true;
        }else{
            value -= getValue(horizontalRows[row][x]);
            horizontalRows[row][x] += plMultiplier[player];
            value+=getValue(horizontalRows[row][x]);
        }

    }

    for ( ; y>row-4 && y>=0; --y) {
        if ( ((verticalRows[y][column] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            winRow[0]=column; winRow[1]=y;
            winRow[2]=column; winRow[3]=y+1;
            winRow[4]=column; winRow[5]=y+2;
            winRow[6]=column; winRow[7]=y+3;
            return true;
        }else{
            value -= getValue(verticalRows[y][column]);
            verticalRows[y][column] += plMultiplier[player];
            value+=getValue(verticalRows[y][column]);
        }
    }

    int off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row-off;
    for ( ; x>column-4 && y>=0 && x>=0; --x, --y) {
        if ( ((diagonalTopRightRows[y][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            winRow[0]=x; winRow[1]=y;
            winRow[2]=x+1; winRow[3]=y+1;
            winRow[4]=x+2; winRow[5]=y+2;
            winRow[6]=x+3; winRow[7]=y+3;
            return true;
        }else{
            value -= getValue(diagonalTopRightRows[y][x]);
            diagonalTopRightRows[y][x] += plMultiplier[player];
            value+=getValue(diagonalTopRightRows[y][x]);
        }
    }

    //************** bottom right
    y = (row>2 ? row : 3);
    yOff = y-row;
    off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row+off;

    for ( ; x>column-4 && x>=0 && y<rows; --x, ++y) {

        if ( ((diagonalBottomRightRows[y-3][x] >> plShift[player]) & TOKENCOUNT_MASK) == 3 ) {
            winRow[0]=x; winRow[1]=y;
            winRow[2]=x+1; winRow[3]=y-1;
            winRow[4]=x+2; winRow[5]=y-2;
            winRow[6]=x+3; winRow[7]=y-3;
            return true;
        }else{
            value -= getValue(diagonalBottomRightRows[y-3][x]);
            diagonalBottomRightRows[y-3][x] += plMultiplier[player];
            value+=getValue(diagonalBottomRightRows[y-3][x]);
        }
    }
    return false;
}

void RowField::removeToken(int player, int column, int row)
{
    //******************

    int x = (column<columns-3 ? column : columns-4);
    int y = (row<rows-3 ? row : rows-4);

    int xOff = column-x;
    int yOff = row-y;

    for ( ; x>column-4 && x>=0; --x) {
        value -= getValue(horizontalRows[row][x]);
        horizontalRows[row][x] -= plMultiplier[player];
        value += getValue(horizontalRows[row][x]);
    }

    for ( ; y>row-4 && y>=0; --y) {
        value -= getValue(verticalRows[y][column]);
        verticalRows[y][column] -= plMultiplier[player];
        value += getValue(verticalRows[y][column]);
    }

    int off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row-off;
    for ( ; x>column-4 && y>=0 && x>=0; --x, --y) {
        value -= getValue(diagonalTopRightRows[y][x]);
        diagonalTopRightRows[y][x] -= plMultiplier[player];
        value += getValue(diagonalTopRightRows[y][x]);
    }

    //************** bottom right
    y = (row>2 ? row : 3);
    yOff = y-row;
    off = xOff > yOff ? xOff : yOff;
    x = column-off;
    y = row+off;

    for ( ; x>column-4 && x>=0 && y<rows; --x, ++y) {
        value -= getValue(diagonalBottomRightRows[y-3][x]);
        diagonalBottomRightRows[y-3][x] -= plMultiplier[player];
        value += getValue(diagonalBottomRightRows[y-3][x]);
    }
}

int * RowField::getWinRow()
{
    return winRow;
}

int RowField::getColumns()
{
    return columns;
}

int RowField::getRows()
{
    return rows;
}

int RowField::getValue()
{
    return value;
}

void RowField::init()
{

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

int RowField::getValue(unsigned char &row)
{
    unsigned char l0 = row & TOKENCOUNT_MASK;
    unsigned char l1 = row >> plShift[1];
    if (l0 && l1) {
        return 0;
    }else if (l0){
        return -l0*l0;
    }else if (l1){
        return l1*l1;
    }else {
        return 0;
    }

}
