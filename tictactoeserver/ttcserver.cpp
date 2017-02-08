#include "ttcserver.h"
#include <vector>

TTCServer* TTCServer::ttcserver = NULL;

TTCServer::TTCServer()
{
    ttcserver = this;
    server = new QTcpServer(this);

    InputHandler* inputHandler = new InputHandler;
    inputHandler->start();

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    connect(this, SIGNAL(readCompleted()), inputHandler, SLOT(readCompleted()));

    if (!server->listen(QHostAddress::Any, 8000))
    {
        qDebug() << "Server cannot start";
    }
    else
    {
        qDebug() << "Server started!";
    }
    message = new Message;
}

void TTCServer::newConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
    User* user = new User(socket);
    Data::getConnections()->push_back(user);
    write(user, "CON OK");
}

void TTCServer::write(User* user, QString message)
{
    user->sendMessage(message + "\r\n");
    user->flushStream();
}

void TTCServer::read(User* user)
{
    Message message;
    QString userInput = user->getMessage();
    qDebug() << "Recieved: " << userInput;
    message.decodeMessage(userInput);
    if (message.command == "LOG")
        login(user, message.param);
    if (message.command == "GLL")
        sendLogins(user);
    if (message.command == "SGR")
        sendGameRequest(user, message.param);
    if (message.command == "AGR")
    {
        startGame(user);
    }
    if (message.command == "MOV")
    {
        move(user, message.param);
    }
    if (message.command == "GGB")
    {
        sendGameboard(user);
    }
    if (message.command == "GTU")
    {
        sendTurn(user);
    }
   user->flushStream();
   emit readCompleted();

}

void TTCServer::login(User* user, QString login)
{
    if(!user->login(login))
    {
        QString message = "ERR " + login + " has been already used";
        write(user, message);
        return;
    }
    write(user, "LOG OK");
    sendUserListToAll();
    qDebug() << "User logged in as: " << user->getName();
}

void TTCServer::sendLogins(User* user)
{
    QString loginList;
    for (int i = 0; i < Data::getConnections()->size(); i++)
    {
        User* temp = Data::getConnections()->at(i);
        if  (temp->isConnected() && temp->isLoggedIn())
        {
            loginList += temp->getName()+",";
        }
    }
    QString message = "ULI " + loginList;
    write(user, message);
}

void TTCServer::sendGameRequest(User* user, QString opponentLogin)
{
    User* opponent = NULL;
    for (int i = 0; i < Data::getConnections()->size(); i++)
    {
        User* temp = Data::getConnections()->at(i);
        if (temp->isLoggedIn() && opponentLogin == temp->getName())
        {
            opponent = temp;
        }
    }
    
    if (opponent == NULL)
    {
        write(user, "ERR There is no opponent like" + opponentLogin);
        return;
    }
    
    write(opponent, "GRQ " + user->getName() + " wants to play with you");
    write(user, "WFA " + opponent->getName() + " is thinking...");
    user->setChallanger(opponent);
    opponent->setChallanger(user);
}

void TTCServer::startGame(User* user)
{
    if (user->getChallanger() == NULL)
    {
        write(user, "ERR cant start game, no opponent");
        return;
    }
    write(user, "GST " + user->getChallanger()->getName());
    write(user->getChallanger(), "GST " + user->getName());
    Game* game = new Game(user, user->getChallanger());
    user->setGame(game);
    user->getChallanger()->setGame(game);
    game->drawGameBoard();
}

void TTCServer::move(User* user, QString param)
{
    short x = param[0].toLatin1() - '0';
    short y = param[1].toLatin1() - '0';
    if (!user->getGame()->put(user, x, y))
    {
        write(user, "MSG It's not your turn!");
    }
    user->getGame()->drawGameBoard();
    checkResult(user);
}

void TTCServer::checkResult(User* user)
{
    if (user->getGame()->checkWin())
    {
        write(user, "GRE You won!");
        write(user->getChallanger(), "GRE You loose, you get nothin");
        user->getChallanger()->setChallanger(NULL);
        user->setChallanger(NULL);
    }
    if (user->getGame()->checkDraw())
    {
        write(user, "GRE Its a draw");
        write(user->getChallanger(), "GRE Its a draw");
        user->getChallanger()->setChallanger(NULL);
        user->setChallanger(NULL);
    }
}

void TTCServer::sendGameboard(User *user)
{
    write(user, "TGB " + user->getGame()->getGameboard());
}

void TTCServer::sendTurn(User* user)
{
    Game* game = user->getGame();
    if (game->getTurn() == user)
    {
        write(user, "YTU");
    }
    if (game->getTurn() == user->getChallanger())
    {
        write(user, "OTU");
    }
}

void TTCServer::sendUserListToAll()
{
    for (int i = 0; i < Data::getConnections()->size(); i++)
    {
        sendLogins(Data::getConnections()->at(i));
    }
}
