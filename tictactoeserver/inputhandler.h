#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QThread>
#include <QDebug>
#include <QtCore>
#include <QString>
#include "message.h"
#include "data.h"

class InputHandler : public QThread
{
    Q_OBJECT
public:
    InputHandler();
    void run();
    static InputHandler* inputhandler;

private:
    bool readed;
    Message message;
    void login(User* user, QString login);
    void sendLogins(User* user);
    void startGameWith(User* user, QString opponentLogin);


public slots:
    void readCompleted();

signals:
    void write(User* user, QString message);
    void read(User* user);
};

#endif // INPUTHANDLER_H
