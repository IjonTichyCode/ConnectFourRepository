#include "NewGameDialog.h"
#include "ui_NewGameDialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog),
    setupData(NULL),
    gameDatabase(NULL),
    cpuRegExp(" (CPU: level ?)", Qt::CaseSensitive, QRegExp::Wildcard)
{
    ui->setupUi(this);
    setWindowTitle(tr("New Game"));
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::setSetupData(NewGameSetup *data)
{
    setupData = data;

    if (gameDatabase) {
        QSqlQuery * playerQuery = gameDatabase->getPlayers();

        while (playerQuery->next()) {
            QString player = playerQuery->value(0).toString();
            if (!playerQuery->value(1).isNull()) {
                player.append(" (CPU: level ")
                    .append(playerQuery->value(2).toString())
                    .append(')');
            }

            ui->player0ComboBox->addItem(player);
            ui->player1ComboBox->addItem(player);
        }

        delete playerQuery;
    }

}

void NewGameDialog::setGameDatabase(GameDatabase * gameDatabase)
{
    this->gameDatabase = gameDatabase;
}

void NewGameDialog::createPlayer()
{
    if (!ui->playerNameLineEdit->text().isEmpty()) {

        QString plName = ui->playerNameLineEdit->text();

        gameDatabase->addPlayer(plName,
            ui->cpuPlayerCheckBox->isChecked(),
            ui->cpuLvlHorizontalSlider->value())
        ;

        if (ui->cpuPlayerCheckBox->isChecked()) {
            plName.append(" (CPU: level ")
                .append( QString::number(ui->cpuLvlHorizontalSlider->value()) )
                .append(')');
        }

        ui->player1ComboBox->addItem(plName);
        ui->player0ComboBox->addItem(plName);
        ui->player0ComboBox->setCurrentIndex( ui->player0ComboBox->count()-1 );
    }

}

void NewGameDialog::player0Begins()
{
    begin(0);
}

void NewGameDialog::player1Begins()
{
    begin(1);
}

void NewGameDialog::cpuLvlSliderEnable(int state)
{
    ui->cpuLvlHorizontalSlider->setEnabled(state==0 ? false : true);
}

void NewGameDialog::begin(int startPlayer)
{
    const QString & pl0Name = ui->player0ComboBox->currentText();
    const QString & pl1Name = ui->player1ComboBox->currentText();

    setupData->player0 = startPlayer==0 ? pl0Name : pl1Name;
    setupData->player1 = startPlayer==0 ? pl1Name : pl0Name;

    setupData->isCpu[0] = cpuRegExp.indexIn(setupData->player0)>-1;
    setupData->isCpu[1] = cpuRegExp.indexIn(setupData->player1)>-1;

    if (setupData->isCpu[0])
        setupData->level[0] = QString(setupData->player0.at(setupData->player0.length()-2)).toInt();

    if (setupData->isCpu[1])
        setupData->level[1] = QString(setupData->player1.at(setupData->player0.length()-2)).toInt();

    setupData->columns = ui->columnsSpinBox->value();
    setupData->rows = ui->rowsSpinBox->value();

    accept();
}
