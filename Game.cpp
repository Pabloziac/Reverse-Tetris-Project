#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"
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
    tmos = new Tetromino();

}

void Game::action()
{

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
    tmos->draw();
    grid->draw();
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    if (key == ' ') //rotating by switching the enum version.
    {
        tmos->clear();
        cout << " tmo version " << tmos->version << endl;

        if(tmos->version == v1){
            tmos->version = v2;
        }
        else if(tmos->version == v2){
            tmos->version = v3;
        }
        else if(tmos->version == v3){
            tmos->version = v4;
        }
        else if(tmos->version == v4){
            tmos->version = v1;
        }

        glutPostRedisplay();
        //tmos->switchversion = false;
    }
    else if (key == 'a')
    {
        //move tetromino left as long as within screen and no collision
        tmos->xoffset -= 0.147;
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        //move down
        tmos->yoffset -= 0.147;
        glutPostRedisplay();
    }
    else if (key == 'd')
    {
        //move right
        tmos->xoffset += 0.147;
        glutPostRedisplay();
        
    }
}

Game::~Game()
{
    stop();
}
