#ifndef GAME_H
#define GAME_H

#include "user.h"
#include <QDebug>
#include <QString>

class User;

class Game
{
public:
    enum Figure {NONE, CROSS, CIRCLE};
    Game(User* player1, User* player2);
    void drawGameBoard();
    bool put(User* user, short x, short y);
    bool checkWin();
    bool checkDraw();
    QString getGameboard();
    User* getTurn();
    int getFigure(User* user);

private:
    User* player1;
    Figure player1Figure;
    User* player2;
    Figure player2Figure;
    User* turnOf;
    Figure** gameBoard;
    void randomizeFigures();
    bool areSame(int a, int b, int c);
    void switchTurns();
    QString itoqstr(int num);
};

#endif // GAME_H
