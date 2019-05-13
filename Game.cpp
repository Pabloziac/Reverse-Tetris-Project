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
    tmos->nextAction();
}

void Game::draw() const
{
    tmos->draw();
    grid->draw();
}
void Game::handleSpecialKeyDown(int key, float a, float b)
{
    if (key == GLUT_KEY_LEFT)
    {
        //move tetromino left as long as within screen and no collision
        cout << "left" << endl;
        tmos->shiftOffsetX(-0.147);
        glutPostRedisplay();
    }
    else if (key == GLUT_KEY_DOWN)
    {
        cout << "down" << endl;
        tmos->shiftOffsetY(-0.147);
        glutPostRedisplay();
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        cout << "right" << endl;
        tmos->shiftOffsetX(0.147);
        glutPostRedisplay();
    }
    else if (key == GLUT_KEY_UP)
    {
        cout << "up" << endl;
        tmos->shiftOffsetY(0.147);
        glutPostRedisplay();
    }
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    int k = key;
    cout << "Keyboard pressed: " << key << endl;
    cout << "Left key " << GLUT_KEY_LEFT << endl;
    if (key == ' ') //rotating by switching the enum version.
    {
        tmos->nextVersion();
    }
    else if (key == 'a')
    {
        //move tetromino left as long as within screen and no collision
        cout << "left" << endl;
        tmos->shiftOffsetX(-0.147);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        cout << "down" << endl;
        tmos->shiftOffsetY(-0.147);
        glutPostRedisplay();
    }
    else if (key == 'd')
    {
        cout << "right" << endl;
        tmos->shiftOffsetX(0.147);
        glutPostRedisplay();
    }
    else if (key == 'w')
    {
        cout << "up" << endl;
        tmos->shiftOffsetY(0.147);
        glutPostRedisplay();
    }
}

Game::~Game()
{
    stop();
}
