#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QString>
#include "gamewindow.h"

class Game
{
public:
    Game(QString opponentName);

private:
    QString opponentName;
    GameWindow* gameWindow;
};

#endif // GAME_H
