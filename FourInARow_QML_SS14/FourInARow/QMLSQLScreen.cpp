#include "QMLSQLScreen.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

QMLSQLScreen::QMLSQLScreen(QQuickItem *parent) :
    QQuickItem(parent)
{
    db = GameDatabase::getInstance();
}

void QMLSQLScreen::executeQuery(QString queryString)
{
    qDebug() << "query: " << queryString;

    QSqlDatabase * db = this->db->getDatabase();

    QSqlQuery query = db->exec(queryString);

    qDebug() << query.lastError().databaseText();

    QString output;
    while (query.next()) {
        for (int i=0; query.value(i).isValid();  ++i) {
            output += query.value(i).toString().append(", ");
        }

        output += "\n";
    }

    emit queryOutput(output);
}
