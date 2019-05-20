#include "Menu.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include <string>
#include <cmath>

Menu::Menu()
{
    button1Active = false;
    button2Active = false;
    resetButtonActive = false;
    gameIsOver = false;
    score = 0;
    msg = new TextBox("S i r t e t", -0.1, 0.1, GLUT_BITMAP_HELVETICA_18, 0.6, 0.0, 0.9, 800);
    button = new TextBox("S t a r t", -0.1, -0.12, GLUT_BITMAP_HELVETICA_18, 0.0, 0.4, 0.4, 800);
    scoreBoard = new TextBox("text", 0, 0.5, GLUT_BITMAP_HELVETICA_18, 0.6, 0.0, 0.9, 800);
}

void Menu::handleHover(float x, float y)
{
    if (!gameIsOver)
    {
        // check if button 1 should be active
        if ((x >= -0.5 && x <= -0.1) && (y >= -0.2 && y <= 0.0))
        {
            button1Active = true;
        }
        else
        {
            button1Active = false;
        }
        // check if button 2 should be active
        if ((x <= 0.5 && x >= 0.1) && (y >= -0.2 && y <= 0.0))
        {
            button2Active = true;
        }
        else
        {
            button2Active = false;
        }
    }
    else
    {
        if ((x <= 0.5 && x >= -0.5) && (y >= -0.2 && y <= 0.0))
        {
            resetButtonActive = true;
        }
        else
        {
            resetButtonActive = false;
        }
    }
}
void Menu::gameOver(int scoreNum)
{
    score = scoreNum;
    gameIsOver = true;
    button->newText("T r y  A g a i n !");
}

bool Menu::didClickButton1(float x, float y)
{
    if ((x <= 0.5 && x >= -0.5) && (y >= -0.2 && y <= 0.0))
    {
        return true;
    }
    return false;
}

bool Menu::didClickButton2(float x, float y)
{
    if ((x <= 0.5 && x >= 0.1) && (y >= -0.2 && y <= 0.0))
    {
        return true;
    }
    return false;
}
bool Menu::didClickResetButtom(float x, float y)
{
    if ((x <= 0.5 && x >= -0.5) && (y >= -0.2 && y <= 0.0))
    {
        return true;
    }
    return false;
}
void Menu::draw()
{
    if (button1Active)
    {
        glColor3f(0.462, 0.780, 1);
    }
    else
    {
        glColor3f(1, 1, 1);
    }
    if (gameIsOver)
    {
        scoreBoard->drawBitmapText(-0.1, 0.1, score);
    }
    else
    {
        msg->draw();
    }

    button->draw();

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, -0.2);
    glEnd();
    // Draw button 2
    // Draw Menu BG
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();
}
void Menu::reset()
{
    button1Active = false;
    button2Active = false;
    resetButtonActive = false;
    gameIsOver = false;
}