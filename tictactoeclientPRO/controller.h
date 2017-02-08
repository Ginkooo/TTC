#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ttcsocket.h"
#include "connector.h"
#include <QString>
#include <QDebug>
#include "message.h"
#include "lobby.h"

class Lobby;
class Connector;
class TTCSocket;

class Controller
{
public:
    Controller();
    bool connect(QString host, QString login);
    static Controller* controller;
    void handleGameMessage(Message message);
    void startMatch();
    void challange(QString username);

private:
    TTCSocket* ttcsocket;
    Connector* connector;
    Lobby* lobby;

    void proceedToLobby();
    void updateUserList(QString stringList);
    void setChallanged(QString text);
};

#endif // CONTROLLER_H
