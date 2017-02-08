#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ttcsocket.h"
#include "connector.h"
#include <QString>
#include <QDebug>
#include "message.h"
#include "lobby.h"
#include <QMessageBox>
#include "game.h"

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
    void matchAccepted();
    void challange(QString username);
    void proceedToLobby();

private:
    TTCSocket* ttcsocket;
    Connector* connector;
    Lobby* lobby;
    Game* game;

    void showError(QString errorMsg);
    void updateUserList(QString stringList);
    void setChallanged(QString text);
    void startMatch(QString opponentName);
    void showGameResultAndBackToLobby(QString gameResultText);
};

#endif // CONTROLLER_H
