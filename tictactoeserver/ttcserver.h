#ifndef TTCSERVER_H
#define TTCSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include "data.h"
#include "message.h"
#include "inputhandler.h"
#include "QStringBuilder"

class TTCServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TTCServer();
    static TTCServer* ttcserver;
    void run();

signals:
    void readCompleted();

public slots:
    void newConnection();
    void write(User* user, QString message);
    void read(User* user);

 private:
    QTcpServer* server;
    Message* message;
    void handleInputFrom(User* user);
    void login(User* user, QString login);
    void sendLogins(User* user);
    void sendGameRequest(User* user, QString opponentLogin);
    void startGame(User* user);
    void move(User* user, QString param);
    void checkResult(User* user);
    void sendGameboard(User* user);
    void sendTurn(User* user);
    void sendUserListToAll();

};

#endif // TTCSERVER_H
