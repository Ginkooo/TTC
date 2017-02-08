#include "ttcsocket.h"

TTCSocket::TTCSocket()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleInput()));
}

void TTCSocket::handleInput()
{
    QString message = this->readAll();
    qDebug() << message;
    if (message.length() < 3)
    {
        qDebug() << "Message is too short!";
        return;
    }
    Message msg;
    msg.decodeMessage(message);
    Controller::controller->handleGameMessage(msg);
}

Message TTCSocket::sendAndRecieve(QString message)
{
    message += "\r\n";
    this->write(message.toLocal8Bit());
    this->waitForBytesWritten();
    this->waitForReadyRead();
    QString msg = this->readAll();
    Message messageObj;
    messageObj.decodeMessage(msg);
    return messageObj;
}

Message TTCSocket::recieve()
{
    this->waitForBytesWritten();
    this->waitForReadyRead();
    QString msg = this->readAll();
    Message messageObj;
    messageObj.decodeMessage(msg);
    return messageObj;
}

void TTCSocket::send(QString message)
{
    message += "\r\n";
    this->write(message.toLocal8Bit());
}

bool TTCSocket::doConnect(QString hostname)
{
    this->connectToHost(hostname, 8000);
    this->waitForConnected(3000);

    if (recieve().param == "OK")
    {
        return true;
    }

    return false;
}
void TTCSocket::blockGameSignal()
{
    this->blockSignals(true);
}

void TTCSocket::unblockGameSignal()
{
    this->blockSignals(false);
}
