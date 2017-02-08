#ifndef USER_H
#define USER_H

#include <QTcpSocket>
#include <QDebug>
#include "message.h"
#include <QString>
#include "game.h"

class Game;

class User
{
public:
    User(QTcpSocket *socket);
    int getID();
    void setName(QString name);
    QString getName();
    void sendMessage(QString msg);
    bool isConnected();
    bool isLoggedIn();
    QString getMessage();
    bool login(QString name);
    bool hasSomethingToSay();
    bool isInGame();
    Game* getGame();
    void setGame(Game* game);
    void flushStream();
    User* getChallanger();
    void setChallanger(User* user);
    ~User();

private:
    Game* game;
    User* challanger;
    QString name;
    int id;
    QTcpSocket* socket;
    static int count;
    bool loggedIn;
    Message* message;
};

#endif // USER_H
