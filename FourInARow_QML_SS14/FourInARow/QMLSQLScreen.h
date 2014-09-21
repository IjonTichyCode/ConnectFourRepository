#ifndef QMLSQLSCREEN_H
#define QMLSQLSCREEN_H

#include <QQuickItem>
#include "GameDatabase.h"

class QMLSQLScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLSQLScreen(QQuickItem *parent = 0);

signals:
    void queryOutput(QString output);

public slots:
    void executeQuery(QString queryString);

private:
    GameDatabase * db;
};

#endif // QMLSQLSCREEN_H
