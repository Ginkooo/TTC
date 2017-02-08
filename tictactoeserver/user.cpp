#include "user.h"
#include "data.h"
#include <string>
#include <QByteArray>

int User::count = 0;

User::User(QTcpSocket* socket)
{
    this->challanger = NULL;
    this->game = NULL;
    this->socket = socket;
    this->name = "";
    this->id = count;
    count++;
    this->message = new Message;
    qDebug() << "New user added! ID: " << getID();
    this->loggedIn = false;
}

void User::setName(QString name)
{
    this->name = name;
}

QString User::getName()
{
    return this->name;
}

int User::getID()
{
    return this->id;
}

bool User::login(QString name)
{
    for (int i = 0; i < Data::getConnections()->size(); i++)
    {
        if(Data::getConnections()->at(i)->getName() == name)
        {
            return false;
        }
    }
    this->loggedIn = true;
    this->setName(name);
    return true;
}

void User::sendMessage(QString msg)
{
    socket->write(msg.toLocal8Bit());
}

bool User::isConnected()
{
    if (this->socket->state() == QTcpSocket::ConnectedState)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool User::isLoggedIn()
{
    if (this->loggedIn)
    {
        return true;
    }
    return false;
}

QString User::getMessage()
{
    QString message;
    if (!isConnected())
    {
        return "DIS DISCONNECT";
    }
    if (socket->canReadLine())
    {
        message = socket->readAll();
    }
    else
    {
        message = "NON MSG";
    }
    return message;
}

bool User::hasSomethingToSay()
{
    if (socket->canReadLine())
    {
        return true;
    }
    return false;
}

void User::flushStream()
{
    this->socket->flush();
}

bool User::isInGame()
{
    if (this->game == NULL)
        return false;
    return true;
}

Game* User::getGame()
{
    return this->game;
}

void User::setGame(Game* game)
{
    this->game = game;
}

User* User::getChallanger()
{
    return this->challanger;
}

void User::setChallanger(User* user)
{
    this->challanger = user;
}

User::~User()
{
    this->socket->close();
    delete this->socket;
    for (int i = 0; i < (int)Data::getConnections()->size(); i++)
    {
        if (Data::getConnections()->at(i)->getID() == this->id)
        {
            free(Data::getConnections()->at(i));
            Data::getConnections()->at(i) = NULL;
        }
    }
}

