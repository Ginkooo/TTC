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
    proceedToLobby();
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
}

void Controller::updateUserList(QString stringList)
{
    QStringList list = stringList.split(',');
    lobby->updateUserList(list);
}

void Controller::startMatch()
{
    qDebug() << "Match started!";
}

void Controller::challange(QString username)
{
    ttcsocket->send("SGR " + username);
}

void Controller::setChallanged(QString text)
{
    lobby->setChallangedText(text);
}
