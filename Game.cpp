#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
#include "TextBox.h"
using namespace std;

Game::Game()
{
    // Some cross-platform compatimility stuff

    const char *shroomFileName;
    const char *fireballFileName;
    tickCounts = 0;

    // In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
    // In other environments the image files are in the same folder as the project

#if defined WIN32
    shroomFileName = "../mushroom.png";
    fireballFileName = "../fireball.bmp";
#else
    shroomFileName = "mushroom.png";
    fireballFileName = "fireball.bmp";
#endif

    tmos = NULL;
    grid = NULL;
    gameStarted = false;
    menu = new Menu();
    // grid->deleteRow(4);
    char *text = "S C O R E : 0";
    scoreBoard = new TextBox(text, 0.6, 0.8, GLUT_BITMAP_HELVETICA_18, 0.6, 0.0, 0.9, 800);
}

void Game::startGame()
{
    tmos = new Tetromino();
    grid = new Grid();
    gameStarted = true;
    setRate(1);
    start();
}

void Game::action()
{
    grid->continueMovingRects();
    int rows = tmos->nextAction(grid, tickCounts, resetAt);

    if (rows == -1)
    {
        stop();
        menu->gameOver(score);
        gameStarted = false;
    }
    else if (rows >= 0)
    {
        score += rows * 10;
        if (resetAt > 500)
        {
            if (score % 100 == 0)
            {
                resetAt -= 70;
            }
        }
    }
    if (resetAt == tickCounts)
    {
        tickCounts = 0;
    }
    else
    {
        tickCounts++;
    }
}

void Game::draw() const
{
    if (gameStarted)
    {
        grid->draw();
        tmos->draw();
        scoreBoard->drawBitmapText(1, 0.75, score);
    }
    else
    {
        menu->draw();
    }
    //char* text = " SCORE : ";
    //scoreBoard->draw(score);
}
void Game::handleLeftMouseDown(float a, float b)
{
    cout << "left mouse down" << endl;

    if (menu->didClickButton1(a, b))
    {
        cout << "clicked button" << endl;
        startGame();
    }
};

void Game::handleSpecialKeyDown(int key, float a, float b)
{
    if (key == GLUT_KEY_LEFT)
    {
        //move tetromino left as long as within screen and no collision
        //cout << "left" << endl;
        tmos->shiftOffsetX(grid, -1);
    }
    else if (key == GLUT_KEY_DOWN)
    {
        //cout << "down" << endl;
        tmos->shiftOffsetY(grid, -1);
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        //cout << "right" << endl;
        tmos->shiftOffsetX(grid, 1);
    }
    else if (key == GLUT_KEY_UP)
    {
        //cout << "up" << endl;
        tmos->shiftOffsetY(grid, 1);
    }
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    int k = key;

    // cout << "Keyboard pressed: " << key << endl;

    if (key == ' ') //rotating by switching the enum version.
    {
        tmos->nextVersion(grid);
    }
    else if (key == 'a')
    {
        //move tetromino left as long as within screen and no collision
        //cout << "left" << endl;
        tmos->shiftOffsetX(grid, -1);
    }
    else if (key == 's')
    {
        //cout << "down" << endl;
        tmos->shiftOffsetY(grid, -1);
    }
    else if (key == 'd')
    {
        //cout << "right" << endl;
        tmos->shiftOffsetX(grid, 1);
    }
    else if (key == 'w')
    {
        //cout << "up" << endl;
        tmos->shiftOffsetY(grid, 1);
    }
}

Game::~Game()
{
    stop();
}
