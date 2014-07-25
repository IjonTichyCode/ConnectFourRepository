#include "TablePushButton.h"

#include <QDebug>

TablePushButton::TablePushButton(int index, const QString & text, QWidget *parent) :
    QPushButton(text, parent),
    index(index)
{
    connect(this, SIGNAL(clicked()), this, SLOT(wasClicked()));
}

void TablePushButton::wasClicked()
{
    emit emitIndex(index);
}
