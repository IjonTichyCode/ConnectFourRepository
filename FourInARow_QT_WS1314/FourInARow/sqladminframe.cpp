#include "sqladminframe.h"
#include "ui_sqladminframe.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

SQLAdminFrame::SQLAdminFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SQLAdminFrame),
    database(NULL)
{
    ui->setupUi(this);
}

SQLAdminFrame::~SQLAdminFrame()
{
    delete ui;
}

void SQLAdminFrame::setGameDatabase(GameDatabase *database)
{
    this->database = database;
}

void SQLAdminFrame::execStatement()
{

    QSqlQuery query = database->getDatabase()->exec(ui->queryLineEdit->text());
    qDebug() << query.lastError().databaseText();

    QString output;
    while (query.next()) {
        for (int i=0; query.value(i).isValid();  ++i) {
            output += query.value(i).toString().append(", ");
        }

        output += "\n";
    }
    ui->queryReturnTextEdit->document()->setPlainText(output);

}

void SQLAdminFrame::insertTimeIntoTimeTable()
{
    qint64 t = QDateTime::currentMSecsSinceEpoch();
    QDateTime time = QDateTime::currentDateTime();

    QString queryStr =  "insert into timeTable (datum) values ('"
            //+ QString::number(t)
            + time.toString(Qt::ISODate)
            + "')";

    qDebug() << queryStr;

    QSqlQuery query = database->getDatabase()->exec(
            queryStr
        );
}
