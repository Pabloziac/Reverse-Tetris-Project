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
    grid->deleteRow(3);
    //
    //    mushroom = new TexRect(shroomFileName, -0.25, 0.5, 0.5, 0.5);
    //    projectile = new Rect(-0.05, -0.8, 0.1, 0.1);
    //    explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);
    //
    //    up = false;
    //    left = true;
    //    projectileVisible = true;
    //    mushroomVisible = true;
    //    theta = 0;
    //    deg = 0;
    //    hit = false;
    //
    //    setRate(1);
    start();
}

void Game::action()
{
    cout << "tick" << endl;

    grid->continueMovingRects();
    // if (grid->getAt(12, 12)->getX() < 1.0)
    // {
    //     grid->getAt(12, 12)->setX(grid->getAt(12, 12)->getX() + 0.001);
    // }

    // float mx = 0.5;
    // float my = 0;

    // if (theta >= 2* M_PI) theta = 0;
    // if (deg >= 360) deg = 0;

    // mx = 0.5 * cos(theta);
    // my = 0.5 * sin(theta);

    // mushroom->setX(mx - mushroom->getW()/2);
    // mushroom->setY(my + mushroom->getH()/2);

    // theta += 0.001;
    // deg += 0.1;

    // if (!hit && up){
    //     float ypos = projectile->getY();
    //     ypos +=0.005;
    //     projectile->setY(ypos);

    //     if (mushroom->contains(0, ypos-0.005)){
    //         up = false;
    //         hit = true;
    //         projectileVisible = false;
    //         mushroomVisible = false;
    //         explosion->setX(mushroom->getX());
    //         explosion->setY(mushroom->getY());
    //         explosion->playOnce();
    //     }
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
    //    delete mushroom;
    //    delete explosion;
    //    delete projectile;
}
