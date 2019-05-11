#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"
#include "Grid.h"
using namespace std;

Game::Game()
{

    // Some cross-platform compatimility stuff

    const char *shroomFileName;
    const char *fireballFileName;

    // In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
    // In other environments the image files are in the same folder as the project

#if defined WIN32
    shroomFileName = "../mushroom.png";
    fireballFileName = "../fireball.bmp";
#else
    shroomFileName = "mushroom.png";
    fireballFileName = "fireball.bmp";
#endif

    grid = new Grid();

    grid->deleteRow(4);
    setRate(1);
    start();
}

void Game::action()
{
    // cout << "tick" << endl;

    grid->continueMovingRects();
    // if (grid->getAt(12, 12)->getX() < 1.0)
    // {
    //     grid->getAt(12, 12)->setX(grid->getAt(12, 12)->getX() + 0.001);
    // }
    // if (hit){
    //     explosion->setY(explosion->getY()-0.0001);
    // }
}

void Game::draw() const
{
    grid->draw();
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    if (key == ' ')
    {
        up = true;
    }
    else if (key == 'p')
    {
        stop();
    }
    else if (key == 'r')
    {
        start();
    }
}

Game::~Game()
{
    stop();
}
