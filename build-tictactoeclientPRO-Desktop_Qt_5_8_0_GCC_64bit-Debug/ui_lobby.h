/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Lobby
{
public:
    QListWidget *userList;
    QPushButton *challangeButton;
    QPushButton *acceptButton;
    QLabel *challangedLabel;

    void setupUi(QDialog *Lobby)
    {
        if (Lobby->objectName().isEmpty())
            Lobby->setObjectName(QStringLiteral("Lobby"));
        Lobby->resize(579, 633);
        userList = new QListWidget(Lobby);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(285, 11, 281, 411));
        challangeButton = new QPushButton(Lobby);
        challangeButton->setObjectName(QStringLiteral("challangeButton"));
        challangeButton->setGeometry(QRect(360, 470, 141, 101));
        acceptButton = new QPushButton(Lobby);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(70, 250, 121, 81));
        challangedLabel = new QLabel(Lobby);
        challangedLabel->setObjectName(QStringLiteral("challangedLabel"));
        challangedLabel->setGeometry(QRect(70, 190, 211, 31));

        retranslateUi(Lobby);

        QMetaObject::connectSlotsByName(Lobby);
    } // setupUi

    void retranslateUi(QDialog *Lobby)
    {
        Lobby->setWindowTitle(QApplication::translate("Lobby", "Dialog", Q_NULLPTR));
        challangeButton->setText(QApplication::translate("Lobby", "Challange", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("Lobby", "Accept", Q_NULLPTR));
        challangedLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Lobby: public Ui_Lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
