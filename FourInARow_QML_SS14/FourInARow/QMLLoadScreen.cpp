#include <QDebug>

#include "QMLLoadScreen.h"


QMLLoadScreen::QMLLoadScreen(QQuickItem *parent) :
    QQuickItem(parent)
{
    connect(this, &QMLLoadScreen::loadGame, this, &QMLLoadScreen::receiveLoadGame);
}

void QMLLoadScreen::receiveLoadGame(int index)
{
    qDebug() << "load game: " << index;
}
