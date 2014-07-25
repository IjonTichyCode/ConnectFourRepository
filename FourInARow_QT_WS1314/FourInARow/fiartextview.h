#ifndef FIARTEXTVIEW_H
#define FIARTEXTVIEW_H

#include <QTextEdit>
#include "fourinarowgame.h"

class FIARTextView : public QTextEdit
{
    Q_OBJECT
public:
    explicit FIARTextView(QWidget *parent = 0);

    void setGame(FourInARowGame * game);

protected:
    virtual void keyReleaseEvent(QKeyEvent * event);

private:
    int columnIndex;
    FourInARowGame * game;

};

#endif // FIARTEXTVIEW_H
