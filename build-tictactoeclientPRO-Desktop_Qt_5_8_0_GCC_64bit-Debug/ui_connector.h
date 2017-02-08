/********************************************************************************
** Form generated from reading UI file 'connector.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTOR_H
#define UI_CONNECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Connector
{
public:
    QLineEdit *ipEdit;
    QLineEdit *loginEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *sendCredentialsButton;
    QLabel *cantConnectLabel;

    void setupUi(QDialog *Connector)
    {
        if (Connector->objectName().isEmpty())
            Connector->setObjectName(QStringLiteral("Connector"));
        Connector->resize(367, 619);
        ipEdit = new QLineEdit(Connector);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setGeometry(QRect(120, 200, 131, 20));
        loginEdit = new QLineEdit(Connector);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));
        loginEdit->setGeometry(QRect(120, 350, 131, 20));
        label = new QLabel(Connector);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 320, 47, 13));
        label_2 = new QLabel(Connector);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 170, 71, 16));
        sendCredentialsButton = new QPushButton(Connector);
        sendCredentialsButton->setObjectName(QStringLiteral("sendCredentialsButton"));
        sendCredentialsButton->setGeometry(QRect(140, 440, 101, 51));
        cantConnectLabel = new QLabel(Connector);
        cantConnectLabel->setObjectName(QStringLiteral("cantConnectLabel"));
        cantConnectLabel->setGeometry(QRect(80, 70, 211, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        cantConnectLabel->setFont(font);

        retranslateUi(Connector);

        QMetaObject::connectSlotsByName(Connector);
    } // setupUi

    void retranslateUi(QDialog *Connector)
    {
        Connector->setWindowTitle(QApplication::translate("Connector", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Connector", "Login:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Connector", "Server's IP:", Q_NULLPTR));
        sendCredentialsButton->setText(QApplication::translate("Connector", "Connect", Q_NULLPTR));
        cantConnectLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connector: public Ui_Connector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTOR_H
