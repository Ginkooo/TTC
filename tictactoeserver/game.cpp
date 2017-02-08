#include "game.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sstream>

Game::Game(User* player1, User* player2)
{
    this->player1 = player1;
    this->player2 = player2;
    gameBoard = new Figure*[3];
    for (int i = 0; i < 3; i++)
    {
        gameBoard[i] = new Figure[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = NONE;
        }
    }
    qDebug() << "Game: " + player1->getName() + " vs " + player2->getName();
    randomizeFigures();
    if (player1Figure == CROSS)
        turnOf = player1;
    else
        turnOf = player2;
}

int Game::getFigure(User* user)
{
    if (user == player1)
        return player1Figure;
    else
        return player2Figure;
}

User* Game::getTurn()
{
    return turnOf;
}

void Game::drawGameBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << gameBoard[i][j];
        }
            std::cout << std::endl;
    }
}

void Game::randomizeFigures()
{
    srand(time(NULL));
    if (rand() % 2 == 0)
    {
        player1Figure = CROSS;
        player2Figure = CIRCLE;
    }
    else
    {
        player1Figure = CIRCLE;
        player2Figure = CROSS;
    }
}

bool Game::put(User* user, short x, short y)
{
    if (turnOf != user)
    {
        return false;
    }

    Figure figure;
    if (user == player1)
    {
        figure = player1Figure;
    }
    else
    {
        figure = player2Figure;
    }
    qDebug() << player1Figure << " " << player2Figure;
    gameBoard[x][y] = figure;
    switchTurns();
    return true;
}

bool Game::checkWin()
{
    bool win;
    win = areSame(gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    if (win)
        return true;
    win = areSame(gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    if (win)
        return true;
    win = areSame(gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    if (win)
        return true;

    win = areSame(gameBoard[0][0], gameBoard[1][1], gameBoard[2][2]);
    if (win)
        return true;
    win = areSame(gameBoard[0][1], gameBoard[1][1], gameBoard[2][2]);
    if (win)
        return true;
    win = areSame(gameBoard[0][2], gameBoard[1][1], gameBoard[2][2]);
    if (win)
        return true;

    win = areSame(gameBoard[0][0], gameBoard[1][1], gameBoard[2][2]);
    if (win)
        return true;
    win = areSame(gameBoard[0][2], gameBoard[1][1], gameBoard[2][0]);
    if (win)
        return true;

    return win;
}

bool Game::checkDraw()
{
    if (checkWin())
    {
        return false;
    }
    bool draw = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == NONE)
            {
                draw = false;
            }
        }
    }
    return draw;
}

bool Game::areSame(int a, int b, int c)
{
    if (a == 0)
        return false;
    if (a == b && b == c)
    {
        return true;
    }
    return false;
}

QString Game::getGameboard()
{
    QString gb = "";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gb += itoqstr(gameBoard[j][i]);
        }
    }

    return gb;
}

void Game::switchTurns()
{
    if (turnOf == player1)
    {
        turnOf = player2;
    }
    else
    {
        turnOf = player1;
    }
}

QString Game::itoqstr(int num)
{
    std::ostringstream sstream;
    sstream.clear();
    sstream << num;
    return QString::fromStdString((sstream.str()));
}

