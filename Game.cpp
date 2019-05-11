#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"
#include "Grid.h"
#include "Tetromino.h"

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
    tmos = new Tetromino();
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
//    start();
}

void Game::action()
{
    if (grid->getAt(12, 12)->getX() < 1.0)
    {
        grid->getAt(12, 12)->setX(grid->getAt(12, 12)->getX() + 0.001);
    }
    
    


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
    tmos->draw();
    grid->draw();
    
    // if (projectileVisible){
    //     projectile->draw();
    // }
    // if (mushroomVisible){
    //     mushroom->draw(0.0);
    // }
    // explosion->draw(0.1);
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
