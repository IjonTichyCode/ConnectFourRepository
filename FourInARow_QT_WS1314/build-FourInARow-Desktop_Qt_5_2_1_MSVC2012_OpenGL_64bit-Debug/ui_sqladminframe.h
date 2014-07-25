/********************************************************************************
** Form generated from reading UI file 'sqladminframe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLADMINFRAME_H
#define UI_SQLADMINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SQLAdminFrame
{
public:
    QLineEdit *queryLineEdit;
    QPushButton *execQueryPushButton;
    QPlainTextEdit *queryReturnTextEdit;
    QPushButton *insertTimePushButton;

    void setupUi(QFrame *SQLAdminFrame)
    {
        if (SQLAdminFrame->objectName().isEmpty())
            SQLAdminFrame->setObjectName(QStringLiteral("SQLAdminFrame"));
        SQLAdminFrame->resize(629, 263);
        SQLAdminFrame->setFrameShape(QFrame::StyledPanel);
        SQLAdminFrame->setFrameShadow(QFrame::Sunken);
        queryLineEdit = new QLineEdit(SQLAdminFrame);
        queryLineEdit->setObjectName(QStringLiteral("queryLineEdit"));
        queryLineEdit->setGeometry(QRect(20, 20, 571, 20));
        execQueryPushButton = new QPushButton(SQLAdminFrame);
        execQueryPushButton->setObjectName(QStringLiteral("execQueryPushButton"));
        execQueryPushButton->setGeometry(QRect(510, 50, 75, 23));
        queryReturnTextEdit = new QPlainTextEdit(SQLAdminFrame);
        queryReturnTextEdit->setObjectName(QStringLiteral("queryReturnTextEdit"));
        queryReturnTextEdit->setGeometry(QRect(60, 90, 361, 151));
        insertTimePushButton = new QPushButton(SQLAdminFrame);
        insertTimePushButton->setObjectName(QStringLiteral("insertTimePushButton"));
        insertTimePushButton->setGeometry(QRect(510, 80, 75, 23));

        retranslateUi(SQLAdminFrame);
        QObject::connect(execQueryPushButton, SIGNAL(clicked()), SQLAdminFrame, SLOT(execStatement()));
        QObject::connect(insertTimePushButton, SIGNAL(clicked()), SQLAdminFrame, SLOT(insertTimeIntoTimeTable()));

        QMetaObject::connectSlotsByName(SQLAdminFrame);
    } // setupUi

    void retranslateUi(QFrame *SQLAdminFrame)
    {
        SQLAdminFrame->setWindowTitle(QApplication::translate("SQLAdminFrame", "Frame", 0));
        execQueryPushButton->setText(QApplication::translate("SQLAdminFrame", "exec query", 0));
        insertTimePushButton->setText(QApplication::translate("SQLAdminFrame", "insertTime", 0));
    } // retranslateUi

};

namespace Ui {
    class SQLAdminFrame: public Ui_SQLAdminFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLADMINFRAME_H
