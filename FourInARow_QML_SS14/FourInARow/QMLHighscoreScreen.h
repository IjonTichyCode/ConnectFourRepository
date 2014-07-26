#ifndef QMLHIGHSCORESCREEN_H
#define QMLHIGHSCORESCREEN_H

#include <QQuickItem>

class QMLHighscoreScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLHighscoreScreen(QQuickItem *parent = 0);

signals:

    void addEntry(QString player, int wins, int losses, qreal ratio);
    void clear();


public slots:

};

#endif // QMLHIGHSCORESCREEN_H
