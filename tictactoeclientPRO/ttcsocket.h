#ifndef TTCSOCKET_H
#define TTCSOCKET_H

#include <QTcpSocket>
#include "message.h"
#include "controller.h"

class Controller;

class TTCSocket : QTcpSocket
{

    Q_OBJECT

public:
    TTCSocket();
    Message sendAndRecieve(QString message);
    bool doConnect(QString hostname);
    Message recieve();
    void send(QString message);
    void blockGameSignal();
    void unblockGameSignal();

public slots:
    void handleInput();
};

#endif // TTCSOCKET_H
