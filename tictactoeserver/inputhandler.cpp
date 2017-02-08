#include "inputhandler.h"
#include "ttcserver.h"

InputHandler* InputHandler::inputhandler = NULL;

InputHandler::InputHandler()
{
    inputhandler = this;
    readed = false;
    connect(this, SIGNAL(write(User*, QString)), TTCServer::ttcserver, SLOT(write(User*, QString)));
    connect(this, SIGNAL(read(User*)), TTCServer::ttcserver, SLOT(read(User*)));
    qDebug() << "new thread created!";
}

void InputHandler::run()
{
    User* user;
    while(true)
    {
        for (int i = 0; i < Data::getConnections()->size(); i++)
        {
            readed = false;
            user = Data::getConnections()->at(i);
            if (user->hasSomethingToSay())
            {
                //qDebug() << "emitting read signal with " << user;
                emit read(user);
                while (!readed)
                {

                }
            }
        }
    }
}

void InputHandler::readCompleted()
{
    readed = true;
}
