#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>
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

    // In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
    // In other environments the image files are in the same folder as the project

#if defined WIN32
    shroomFileName = "../mushroom.png";
    fireballFileName = "../fireball.bmp";
#else
    shroomFileName = "mushroom.png";
    fireballFileName = "fireball.bmp";
#endif
    
    score = 21; //if deleterow --> score=score+13
    
    char integer_score[21];
    sprintf(integer_score, "%d", score);
    char text[21] = "S C O R E :  ";
    strcat(text, integer_score);

    cout << text << endl;
    
    scoreBoard = new TextBox(text, 0.6, 0.8, GLUT_BITMAP_HELVETICA_18, 0.6, 0.0, 0.7, 800, score);
    
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
    
    scoreBoard->draw();
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    if (key == ' ') //rotating by switching the enum version.
    {
        tmos->nextVersion();    
    }
    else if (key == 'a')
    {
        //move tetromino left as long as within screen and no collision
        tmos->shiftOffsetX(-0.147);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        //move down
        tmos->shiftOffsetY(-0.147);
        glutPostRedisplay();
    }
    else if (key == 'd')
    {
        //move right
        tmos->shiftOffsetX(0.147);
        glutPostRedisplay();
        
    }
}

Game::~Game()
{
    stop();
}
