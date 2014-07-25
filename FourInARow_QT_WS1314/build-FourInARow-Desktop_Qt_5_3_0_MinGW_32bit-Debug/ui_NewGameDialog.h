/********************************************************************************
** Form generated from reading UI file 'NewGameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDIALOG_H
#define UI_NEWGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QFrame *frame;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *playerNameLineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *cpuPlayerCheckBox;
    QPushButton *createPlayerPushButton;
    QSlider *cpuLvlHorizontalSlider;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *player1ComboBox;
    QComboBox *player0ComboBox;
    QLabel *label;
    QPushButton *player1BeginsPushButton;
    QPushButton *player0BeginsPushButton;
    QPushButton *cancelPushButton;
    QFrame *frame_2;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QSpinBox *rowsSpinBox;
    QSpinBox *columnsSpinBox;
    QLabel *label_9;
    QLabel *label_7;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName(QStringLiteral("NewGameDialog"));
        NewGameDialog->resize(409, 410);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewGameDialog->sizePolicy().hasHeightForWidth());
        NewGameDialog->setSizePolicy(sizePolicy);
        NewGameDialog->setSizeGripEnabled(true);
        NewGameDialog->setModal(true);
        frame = new QFrame(NewGameDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 371, 161));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setBaseSize(QSize(0, 150));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 221, 21));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 341, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        playerNameLineEdit = new QLineEdit(gridLayoutWidget);
        playerNameLineEdit->setObjectName(QStringLiteral("playerNameLineEdit"));

        gridLayout->addWidget(playerNameLineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        cpuPlayerCheckBox = new QCheckBox(gridLayoutWidget);
        cpuPlayerCheckBox->setObjectName(QStringLiteral("cpuPlayerCheckBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cpuPlayerCheckBox->sizePolicy().hasHeightForWidth());
        cpuPlayerCheckBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(cpuPlayerCheckBox, 1, 1, 1, 1);

        createPlayerPushButton = new QPushButton(gridLayoutWidget);
        createPlayerPushButton->setObjectName(QStringLiteral("createPlayerPushButton"));

        gridLayout->addWidget(createPlayerPushButton, 3, 0, 1, 1);

        cpuLvlHorizontalSlider = new QSlider(gridLayoutWidget);
        cpuLvlHorizontalSlider->setObjectName(QStringLiteral("cpuLvlHorizontalSlider"));
        cpuLvlHorizontalSlider->setEnabled(false);
        cpuLvlHorizontalSlider->setMinimum(0);
        cpuLvlHorizontalSlider->setMaximum(2);
        cpuLvlHorizontalSlider->setSingleStep(3);
        cpuLvlHorizontalSlider->setValue(1);
        cpuLvlHorizontalSlider->setSliderPosition(1);
        cpuLvlHorizontalSlider->setOrientation(Qt::Horizontal);
        cpuLvlHorizontalSlider->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(cpuLvlHorizontalSlider, 2, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(NewGameDialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 290, 341, 101));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        player1ComboBox = new QComboBox(gridLayoutWidget_2);
        player1ComboBox->setObjectName(QStringLiteral("player1ComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(player1ComboBox->sizePolicy().hasHeightForWidth());
        player1ComboBox->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(player1ComboBox, 1, 1, 1, 1);

        player0ComboBox = new QComboBox(gridLayoutWidget_2);
        player0ComboBox->setObjectName(QStringLiteral("player0ComboBox"));
        sizePolicy3.setHeightForWidth(player0ComboBox->sizePolicy().hasHeightForWidth());
        player0ComboBox->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(player0ComboBox, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        player1BeginsPushButton = new QPushButton(gridLayoutWidget_2);
        player1BeginsPushButton->setObjectName(QStringLiteral("player1BeginsPushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(player1BeginsPushButton->sizePolicy().hasHeightForWidth());
        player1BeginsPushButton->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(player1BeginsPushButton, 1, 2, 1, 1);

        player0BeginsPushButton = new QPushButton(gridLayoutWidget_2);
        player0BeginsPushButton->setObjectName(QStringLiteral("player0BeginsPushButton"));
        sizePolicy4.setHeightForWidth(player0BeginsPushButton->sizePolicy().hasHeightForWidth());
        player0BeginsPushButton->setSizePolicy(sizePolicy4);
        player0BeginsPushButton->setDefault(true);

        gridLayout_2->addWidget(player0BeginsPushButton, 0, 2, 1, 1);

        cancelPushButton = new QPushButton(gridLayoutWidget_2);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        sizePolicy4.setHeightForWidth(cancelPushButton->sizePolicy().hasHeightForWidth());
        cancelPushButton->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(cancelPushButton, 2, 2, 1, 1);

        frame_2 = new QFrame(NewGameDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 180, 371, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget_5 = new QWidget(frame_2);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(20, 40, 141, 61));
        gridLayoutWidget_5->setFont(font1);
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);
        label_8->setFont(font1);

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        rowsSpinBox = new QSpinBox(gridLayoutWidget_5);
        rowsSpinBox->setObjectName(QStringLiteral("rowsSpinBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(rowsSpinBox->sizePolicy().hasHeightForWidth());
        rowsSpinBox->setSizePolicy(sizePolicy6);
        rowsSpinBox->setFont(font1);
        rowsSpinBox->setReadOnly(false);
        rowsSpinBox->setKeyboardTracking(true);
        rowsSpinBox->setMinimum(4);
        rowsSpinBox->setMaximum(9);
        rowsSpinBox->setValue(6);

        gridLayout_5->addWidget(rowsSpinBox, 0, 1, 1, 1);

        columnsSpinBox = new QSpinBox(gridLayoutWidget_5);
        columnsSpinBox->setObjectName(QStringLiteral("columnsSpinBox"));
        columnsSpinBox->setFont(font1);
        columnsSpinBox->setKeyboardTracking(true);
        columnsSpinBox->setMinimum(4);
        columnsSpinBox->setMaximum(9);
        columnsSpinBox->setValue(7);

        gridLayout_5->addWidget(columnsSpinBox, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 221, 21));
        label_7->setFont(font);
        QWidget::setTabOrder(playerNameLineEdit, cpuPlayerCheckBox);
        QWidget::setTabOrder(cpuPlayerCheckBox, cpuLvlHorizontalSlider);
        QWidget::setTabOrder(cpuLvlHorizontalSlider, createPlayerPushButton);
        QWidget::setTabOrder(createPlayerPushButton, rowsSpinBox);
        QWidget::setTabOrder(rowsSpinBox, columnsSpinBox);
        QWidget::setTabOrder(columnsSpinBox, player0ComboBox);
        QWidget::setTabOrder(player0ComboBox, player1ComboBox);
        QWidget::setTabOrder(player1ComboBox, player0BeginsPushButton);
        QWidget::setTabOrder(player0BeginsPushButton, player1BeginsPushButton);
        QWidget::setTabOrder(player1BeginsPushButton, cancelPushButton);

        retranslateUi(NewGameDialog);
        QObject::connect(cancelPushButton, SIGNAL(clicked()), NewGameDialog, SLOT(reject()));
        QObject::connect(player0BeginsPushButton, SIGNAL(clicked()), NewGameDialog, SLOT(player0Begins()));
        QObject::connect(createPlayerPushButton, SIGNAL(clicked()), NewGameDialog, SLOT(createPlayer()));
        QObject::connect(player1BeginsPushButton, SIGNAL(clicked()), NewGameDialog, SLOT(player1Begins()));
        QObject::connect(cpuPlayerCheckBox, SIGNAL(stateChanged(int)), NewGameDialog, SLOT(cpuLvlSliderEnable(int)));

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QApplication::translate("NewGameDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("NewGameDialog", "Create new player:", 0));
        label_3->setText(QApplication::translate("NewGameDialog", "Name:", 0));
        label_5->setText(QApplication::translate("NewGameDialog", "Computer level:", 0));
        label_6->setText(QApplication::translate("NewGameDialog", "Computer player:", 0));
        cpuPlayerCheckBox->setText(QString());
        createPlayerPushButton->setText(QApplication::translate("NewGameDialog", "Create", 0));
        label_4->setText(QApplication::translate("NewGameDialog", "player 1:", 0));
        label->setText(QApplication::translate("NewGameDialog", "player 2:", 0));
        player1BeginsPushButton->setText(QApplication::translate("NewGameDialog", "Begin", 0));
        player0BeginsPushButton->setText(QApplication::translate("NewGameDialog", "Begin", 0));
        cancelPushButton->setText(QApplication::translate("NewGameDialog", "Cancel", 0));
        label_8->setText(QApplication::translate("NewGameDialog", "rows:", 0));
        label_9->setText(QApplication::translate("NewGameDialog", "columns:", 0));
        label_7->setText(QApplication::translate("NewGameDialog", "Board size:", 0));
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDIALOG_H
