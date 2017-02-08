#include "lobby.h"
#include "ui_lobby.h"

Lobby::Lobby(Controller* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    ui->acceptButton->setVisible(false);
    ui->challangedLabel->setVisible(false);
    this->controller = controller;
    connect(ui->acceptButton, SIGNAL(clicked(bool)), this, SLOT(acceptButtonClicked()));
    connect(ui->challangeButton, SIGNAL(clicked(bool)), this, SLOT(challangeButtonClicked()));
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::acceptButtonClicked()
{
    controller->matchAccepted();
}

void Lobby::challangeButtonClicked()
{
   QString challanged = ui->userList->selectedItems()[0]->text();
   controller->challange(challanged);
}

void Lobby::updateUserList(QStringList list)
{
    ui->userList->clear();
    ui->userList->addItems(list);
}

void Lobby::setChallangedText(QString text)
{
    ui->challangedLabel->setText(text);
    ui->challangedLabel->setVisible(true);
    ui->acceptButton->setVisible(true);
}
