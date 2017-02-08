/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *Field2;
    QLabel *Field7;
    QLabel *Field8;
    QLabel *Field4;
    QLabel *Field9;
    QLabel *Field1;
    QLabel *Field5;
    QLabel *Field6;
    QLabel *Field3;
    QLabel *whichTurnLabel;
    QLabel *opponentNameLabel;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(690, 581);
        gridLayoutWidget = new QWidget(GameWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 691, 581));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Field2 = new QLabel(gridLayoutWidget);
        Field2->setObjectName(QStringLiteral("Field2"));

        gridLayout->addWidget(Field2, 0, 1, 1, 1);

        Field7 = new QLabel(gridLayoutWidget);
        Field7->setObjectName(QStringLiteral("Field7"));

        gridLayout->addWidget(Field7, 2, 0, 1, 1);

        Field8 = new QLabel(gridLayoutWidget);
        Field8->setObjectName(QStringLiteral("Field8"));

        gridLayout->addWidget(Field8, 2, 1, 1, 1);

        Field4 = new QLabel(gridLayoutWidget);
        Field4->setObjectName(QStringLiteral("Field4"));

        gridLayout->addWidget(Field4, 1, 0, 1, 1);

        Field9 = new QLabel(gridLayoutWidget);
        Field9->setObjectName(QStringLiteral("Field9"));

        gridLayout->addWidget(Field9, 2, 2, 1, 1);

        Field1 = new QLabel(gridLayoutWidget);
        Field1->setObjectName(QStringLiteral("Field1"));

        gridLayout->addWidget(Field1, 0, 0, 1, 1);

        Field5 = new QLabel(gridLayoutWidget);
        Field5->setObjectName(QStringLiteral("Field5"));

        gridLayout->addWidget(Field5, 1, 1, 1, 1);

        Field6 = new QLabel(gridLayoutWidget);
        Field6->setObjectName(QStringLiteral("Field6"));

        gridLayout->addWidget(Field6, 1, 2, 1, 1);

        Field3 = new QLabel(gridLayoutWidget);
        Field3->setObjectName(QStringLiteral("Field3"));

        gridLayout->addWidget(Field3, 0, 2, 1, 1);

        whichTurnLabel = new QLabel(gridLayoutWidget);
        whichTurnLabel->setObjectName(QStringLiteral("whichTurnLabel"));

        gridLayout->addWidget(whichTurnLabel, 1, 3, 1, 1);

        opponentNameLabel = new QLabel(gridLayoutWidget);
        opponentNameLabel->setObjectName(QStringLiteral("opponentNameLabel"));

        gridLayout->addWidget(opponentNameLabel, 0, 3, 1, 1);


        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "Form", Q_NULLPTR));
        Field2->setText(QString());
        Field7->setText(QString());
        Field8->setText(QString());
        Field4->setText(QString());
        Field9->setText(QString());
        Field1->setText(QString());
        Field5->setText(QString());
        Field6->setText(QString());
        Field3->setText(QString());
        whichTurnLabel->setText(QString());
        opponentNameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
