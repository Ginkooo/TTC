#include "controller.h"

Controller* Controller::controller = NULL;

Controller::Controller()
{
    controller = this;
    connector = new Connector(this);
    connector->show();
}


bool Controller::connect(QString host, QString login)
{
    TTCSocket* ttcsocket = new TTCSocket;
    ttcsocket->blockGameSignal();
    if (!ttcsocket->doConnect(host))
    {
        return false;
    }
    this->ttcsocket = ttcsocket;
    Message message = ttcsocket->sendAndRecieve("LOG " + login);
    if (message.param != "OK")
    {
        return false;
    }

    return true;
}

void Controller::proceedToLobby()
{
    delete connector;
    ttcsocket->unblockGameSignal();
    this->lobby = new Lobby(this);
    lobby->show();
}

void Controller::handleGameMessage(Message message)
{
    if (message.command == "ULI")
        updateUserList(message.param);
    if (message.command == "GRQ")
        setChallanged(message.param);
    if (message.command == "GST")
        startMatch(message.param);
    if (message.command == "ERR")
        showError(message.param);
    if (message.command == "GRE")
        showGameResultAndBackToLobby(message.param);
}

void Controller::showError(QString errorMsg)
{
    QMessageBox messageBox;
    messageBox.setText(errorMsg);
    messageBox.exec();
}

void Controller::updateUserList(QString stringList)
{
    QStringList list = stringList.split(',');
    lobby->updateUserList(list);
}

void Controller::matchAccepted()
{
    ttcsocket->send("AGR");
}

void Controller::startMatch(QString opponentName)
{
    lobby->hide();
    game = new Game(opponentName);
}

void Controller::challange(QString username)
{
    ttcsocket->send("SGR " + username);
}

void Controller::setChallanged(QString text)
{
    lobby->setChallangedText(text);
}

void Controller::showGameResultAndBackToLobby(QString gameResultText)
{
    QMessageBox messageBox;
    messageBox.setText(gameResultText);
    messageBox.exec();
}
