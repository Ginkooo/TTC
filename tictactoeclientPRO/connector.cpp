#include "connector.h"
#include "ui_connector.h"

Connector::Connector(Controller* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connector)
{
    this->controller = controller;
    ui->setupUi(this);
    ui->cantConnectLabel->setVisible(false);
    connect(ui->sendCredentialsButton, SIGNAL(clicked(bool)), this, SLOT(connectClicked()));
}

Connector::~Connector()
{
    delete ui;
}

void Connector::connectClicked()
{
    if (ui->ipEdit->text().isEmpty() || ui->loginEdit->text().isEmpty())
    {
        ui->cantConnectLabel->setText("Fill the fields");
        ui->cantConnectLabel->setVisible(true);
        return;
    }

    if (!controller->connect(ui->ipEdit->text(), ui->loginEdit->text()))
    {
        ui->cantConnectLabel->setText("Bad IP or login, try again");
        ui->cantConnectLabel->setVisible(true);
        return;
    }
}
