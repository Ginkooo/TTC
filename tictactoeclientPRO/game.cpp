#include "game.h"

Game::Game(QString opponentName)
{
    gameWindow = new GameWindow;
    gameWindow->show();
}
