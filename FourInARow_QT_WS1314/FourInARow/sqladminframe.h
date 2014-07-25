#ifndef SQLADMINFRAME_H
#define SQLADMINFRAME_H

#include <QFrame>
#include "GameDatabase.h"

namespace Ui {
class SQLAdminFrame;
}

/**
 * @brief The SQLAdminFrame class is for debugging purpose only.
 * This is and remains a stub.
 */
class SQLAdminFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SQLAdminFrame(QWidget *parent = 0);
    ~SQLAdminFrame();

    virtual void setGameDatabase(GameDatabase * database);

public slots:

    virtual void execStatement();
    virtual void insertTimeIntoTimeTable();

private:
    Ui::SQLAdminFrame *ui;
    GameDatabase * database;
};

#endif // SQLADMINFRAME_H
