#ifndef QMLLOADSCREEN_H
#define QMLLOADSCREEN_H

#include <QQuickItem>

class QMLLoadScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLLoadScreen(QQuickItem *parent = 0);

signals:

    void addEntry(QString player0, QString player1, int index);
    void clear();
    void loadGame(int index);

public slots:
    void receiveLoadGame(int index);

};

#endif // QMLLOADSCREEN_H
