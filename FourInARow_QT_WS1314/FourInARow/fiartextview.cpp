#include <QKeyEvent>
#include "fiartextview.h"


FIARTextView::FIARTextView(QWidget *parent) :
    QTextEdit(parent),
    columnIndex(0)
{
    document()->setDefaultFont(QFont("Courier"));


}

void FIARTextView::setGame(FourInARowGame *game)
{
    this->game = game;
}

void FIARTextView::keyReleaseEvent(QKeyEvent * event) {

    bool changed = false;

    switch (event->key())
    {

    case Qt::Key_Left:

        if (columnIndex>0) {
            --columnIndex;
            changed = true;
        }
        break;

    case Qt::Key_Right:
        if (columnIndex < game->getBoard()->columnCount-1) {
            ++columnIndex;
            changed = true;
        }
        break;

    case Qt::Key_Return:
        MoveResult res = game->move(columnIndex);
        switch (res) {
        case MoveResult::SUCCESS:
            changed = true;
            //document()->clear();
            //document()->setPlainText(QString("SUCCESS"));
            break;
        case MoveResult::WIN:
           // document()->clear();
            document()->setPlainText(QString("WIN"));
            break;
        case MoveResult::INVALID_COLUMN:
            //document()->clear();
            document()->setPlainText(QString("invalid column"));
            break;
        case MoveResult::FULL_COLUMN:
            //document()->clear();
            document()->setPlainText(QString("full"));
            break;
        }

        break;
    }

    if (changed) {

        //document()->clear();

        FourInARowBoard * board = game->getBoard();

        QString text;
        for (int i=0; i<columnIndex; ++i) {
            text.append(' ');
        }
        text.append("v\n");

        unsigned short tokenFlag = 1;
        tokenFlag <<= board->rowCount -1;


        for (int row = board->rowCount-1; row>=0; --row) {

            for (int col = 0; col<board->columnCount; ++col) {

                if (tokenFlag & board->whiteTokens[col]) {
                    text.append('o');
                }else if (tokenFlag & board->blackTokens[col]) {
                    text.append('x');
                }else{
                    text.append(' ');
                }
            }
            tokenFlag >>= 1;
            text.append('\n');
        }

      document()->setPlainText(text);
    }

}
