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
}

void Menu::handleHover(float x, float y, bool gameOver)
{
    if (!gameOver)
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

bool Menu::didClickButton1(float x, float y)
{
    if ((x >= -0.5 && x <= -0.1) && (y >= -0.2 && y <= 0.0))
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
    // "# of Players" text
    // Draw button 1
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    // glVertex3f(-1.0, 0.0, 0.5);
    // glVertex3f(1.0, 0.0, 0.5);
    glVertex3f(-0.3, -0.05, 0.5);
    glVertex3f(-0.3, -0.15, 0.5);
    glEnd();

    if (button1Active)
    {
        glColor3f(0.462, 0.780, 1);
    }
    else
    {
        glColor3f(1, 1, 1);
    }
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.1, -0.2);
    glEnd();

    // Draw button 2
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex3f(0.25, -0.05, 0.5);
    glVertex3f(0.35, -0.05, 0.5);

    glVertex3f(0.25, -0.1, 0.5);
    glVertex3f(0.35, -0.1, 0.5);

    glVertex3f(0.25, -0.15, 0.5);
    glVertex3f(0.35, -0.15, 0.5);

    glVertex3f(0.35, -0.05, 0.5);
    glVertex3f(0.35, -0.1, 0.5);

    glVertex3f(0.25, -0.1, 0.5);
    glVertex3f(0.25, -0.15, 0.5);
    glEnd();

    // Draw button 2
    if (button2Active)
    {
        glColor3f(0.462, 0.780, 1);
    }
    else
    {
        glColor3f(1, 1, 1);
    }
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, -0.2);
    glEnd();

    // "# of Players" text

    glColor3f(1.0, 0.0, 0.0);

    glLineWidth(3);

    glBegin(GL_LINES);

    // "#"
    glVertex3f(-0.5, 0.22, 0.5);
    glVertex3f(-0.35, 0.22, 0.5);

    glVertex3f(-0.5, 0.18, 0.5);
    glVertex3f(-0.35, 0.18, 0.5);

    glVertex3f(-0.4, 0.25, 0.5);
    glVertex3f(-0.4, 0.15, 0.5);

    glVertex3f(-0.45, 0.25, 0.5);
    glVertex3f(-0.45, 0.15, 0.5);

    // "o"

    glVertex3f(-0.3, 0.22, 0.5);
    glVertex3f(-0.25, 0.22, 0.5);

    glVertex3f(-0.3, 0.15, 0.5);
    glVertex3f(-0.25, 0.15, 0.5);

    glVertex3f(-0.25, 0.22, 0.5);
    glVertex3f(-0.25, 0.15, 0.5);

    glVertex3f(-0.30, 0.22, 0.5);
    glVertex3f(-0.30, 0.15, 0.5);

    // "f"

    glVertex3f(-0.22, 0.25, 0.5);
    glVertex3f(-0.18, 0.25, 0.5);

    glVertex3f(-0.22, 0.20, 0.5);
    glVertex3f(-0.18, 0.20, 0.5);

    glVertex3f(-0.22, 0.25, 0.5);
    glVertex3f(-0.22, 0.14, 0.5);

    // "Players?"
    // "P"
    glVertex3f(-0.12, 0.25, 0.5);
    glVertex3f(-0.06, 0.25, 0.5);

    glVertex3f(-0.12, 0.2, 0.5);
    glVertex3f(-0.06, 0.2, 0.5);

    glVertex3f(-0.12, 0.25, 0.5);
    glVertex3f(-0.12, 0.14, 0.5);

    glVertex3f(-0.06, 0.25, 0.5);
    glVertex3f(-0.06, 0.2, 0.5);

    // "l"

    glVertex3f(-0.03, 0.25, 0.5);
    glVertex3f(-0.03, 0.14, 0.5);

    // "a"

    glVertex3f(0.0, 0.22, 0.5);
    glVertex3f(0.05, 0.22, 0.5);

    glVertex3f(0.0, 0.19, 0.5);
    glVertex3f(0.05, 0.19, 0.5);

    glVertex3f(0.0, 0.14, 0.5);
    glVertex3f(0.05, 0.14, 0.5);

    glVertex3f(0.0, 0.19, 0.5);
    glVertex3f(0.0, 0.14, 0.5);

    glVertex3f(0.05, 0.22, 0.5);
    glVertex3f(0.05, 0.14, 0.5);

    // "y"

    glVertex3f(0.07, 0.19, 0.5);
    glVertex3f(0.13, 0.19, 0.5);

    glVertex3f(0.07, 0.14, 0.5);
    glVertex3f(0.13, 0.14, 0.5);

    glVertex3f(0.07, 0.22, 0.5);
    glVertex3f(0.07, 0.19, 0.5);

    glVertex3f(0.13, 0.22, 0.5);
    glVertex3f(0.13, 0.14, 0.5);

    // "e"

    glVertex3f(0.16, 0.22, 0.5);
    glVertex3f(0.22, 0.22, 0.5);

    glVertex3f(0.16, 0.19, 0.5);
    glVertex3f(0.22, 0.19, 0.5);

    glVertex3f(0.16, 0.14, 0.5);
    glVertex3f(0.22, 0.14, 0.5);

    glVertex3f(0.16, 0.22, 0.5);
    glVertex3f(0.16, 0.14, 0.5);

    glVertex3f(0.22, 0.22, 0.5);
    glVertex3f(0.22, 0.19, 0.5);

    // "r"

    glVertex3f(0.25, 0.21, 0.5);
    glVertex3f(0.31, 0.21, 0.5);

    glVertex3f(0.25, 0.22, 0.5);
    glVertex3f(0.25, 0.14, 0.5);

    // "s"

    glVertex3f(0.34, 0.22, 0.5);
    glVertex3f(0.40, 0.22, 0.5);

    glVertex3f(0.34, 0.19, 0.5);
    glVertex3f(0.40, 0.19, 0.5);

    glVertex3f(0.34, 0.14, 0.5);
    glVertex3f(0.40, 0.14, 0.5);

    glVertex3f(0.34, 0.22, 0.5);
    glVertex3f(0.34, 0.19, 0.5);

    glVertex3f(0.40, 0.19, 0.5);
    glVertex3f(0.40, 0.14, 0.5);

    // "?"

    glVertex3f(0.44, 0.24, 0.5);
    glVertex3f(0.50, 0.24, 0.5);

    glVertex3f(0.44, 0.19, 0.5);
    glVertex3f(0.50, 0.19, 0.5);

    glVertex3f(0.50, 0.24, 0.5);
    glVertex3f(0.50, 0.19, 0.5);

    glVertex3f(0.44, 0.19, 0.5);
    glVertex3f(0.44, 0.18, 0.5);

    glVertex3f(0.440, 0.16, 0.5);
    glVertex3f(0.440, 0.14, 0.5);

    glVertex3f(0.445, 0.16, 0.5);
    glVertex3f(0.445, 0.14, 0.5);

    glVertex3f(0.45, 0.16, 0.5);
    glVertex3f(0.45, 0.14, 0.5);

    glEnd();

    // Draw Menu BG
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();
}
void Menu::showWinner(string winner)
{
    float x = -0.2;
    float y = 0.5;
    float h = 0.4;
    float w = 0.4;
    if (winner != "NONE")
    {
        if (winner == "X")
        {
            glColor3f(0, 0, 1);
            glBegin(GL_LINES);
            glVertex2f(x + 0.1, y - 0.1);
            glVertex2f(x + w - 0.1, y - h + 0.1);
            glVertex2f(x + 0.1, y - h + 0.1);
            glVertex2f(x + w - 0.1, y - 0.1);
            glEnd();
        }
        else if (winner == "O")
        {
            glColor3f(1, 0, 0);
            glBegin(GL_LINES);
            float inc = 0.1;
            for (float theta = 0; theta < 2 * M_PI; theta += inc)
            {
                glVertex2f((w / 2 - 0.1) * cos(theta) + x + (w / 2), (w / 2 - 0.1) * sin(theta) + y - h / 2);
                glVertex2f((w / 2 - 0.1) * cos(theta + inc) + x + (w / 2), (w / 2 - 0.1) * sin(theta + inc) + y - h / 2);
            }
            glEnd();
        }
    }
    else
    {
        glColor3f(0, 1, 0);

        glBegin(GL_LINES);
        // "n"
        glVertex3f(-0.15, 0.38, 0.5);
        glVertex3f(-0.2, 0.38, 0.5);

        glVertex3f(-0.2, 0.3, 0.5);
        glVertex3f(-0.2, 0.38, 0.5);

        glVertex3f(-0.15, 0.3, 0.5);
        glVertex3f(-0.15, 0.38, 0.5);

        // o
        glVertex3f(-0.1, 0.38, 0.5);
        glVertex3f(-0.05, 0.38, 0.5);

        glVertex3f(-0.1, 0.30, 0.5);
        glVertex3f(-0.05, 0.30, 0.5);

        glVertex3f(-0.1, 0.38, 0.5);
        glVertex3f(-0.1, 0.30, 0.5);

        glVertex3f(-0.05, 0.38, 0.5);
        glVertex3f(-0.05, 0.30, 0.5);

        // "n"
        glVertex3f(0.05, 0.38, 0.5);
        glVertex3f(0, 0.38, 0.5);

        glVertex3f(-0.0, 0.3, 0.5);
        glVertex3f(-0.0, 0.38, 0.5);

        glVertex3f(0.05, 0.3, 0.5);
        glVertex3f(0.05, 0.38, 0.5);

        // "e"
        glVertex3f(0.15, 0.38, 0.5);
        glVertex3f(0.1, 0.38, 0.5);

        glVertex3f(0.15, 0.34, 0.5);
        glVertex3f(0.1, 0.34, 0.5);

        glVertex3f(0.15, 0.30, 0.5);
        glVertex3f(0.1, 0.30, 0.5);

        glVertex3f(0.1, 0.38, 0.5);
        glVertex3f(0.1, 0.3, 0.5);

        glEnd();
    }
    glBegin(GL_LINES);

    // W
    glVertex3f(-0.14, 0.10, 0.5);
    glVertex3f(-0.2, 0.10, 0.5);

    glVertex3f(-0.13, 0.10, 0.5);
    glVertex3f(-0.1, 0.10, 0.5);

    glVertex3f(-0.2, 0.18, 0.5);
    glVertex3f(-0.2, 0.10, 0.5);

    glVertex3f(-0.15, 0.18, 0.5);
    glVertex3f(-0.15, 0.10, 0.5);

    glVertex3f(-0.14, 0.18, 0.5);
    glVertex3f(-0.14, 0.10, 0.5);

    glVertex3f(-0.1, 0.18, 0.5);
    glVertex3f(-0.1, 0.10, 0.5);
    // o
    glVertex3f(-0.05, 0.18, 0.5);
    glVertex3f(0.0, 0.18, 0.5);

    glVertex3f(-0.05, 0.10, 0.5);
    glVertex3f(0.0, 0.10, 0.5);

    glVertex3f(-0.05, 0.18, 0.5);
    glVertex3f(-0.05, 0.10, 0.5);

    glVertex3f(0, 0.18, 0.5);
    glVertex3f(0, 0.10, 0.5);

    // n
    glVertex3f(0.05, 0.18, 0.5);
    glVertex3f(0.1, 0.18, 0.5);

    glVertex3f(0.05, 0.18, 0.5);
    glVertex3f(0.05, 0.10, 0.5);

    glVertex3f(0.1, 0.18, 0.5);
    glVertex3f(0.1, 0.10, 0.5);

    glEnd();
    // reset button
    glBegin(GL_LINES);
    // "r"
    glVertex3f(-0.25, -0.05, 0.5);
    glVertex3f(-0.31, -0.05, 0.5);

    glVertex3f(-0.31, -0.05, 0.5);
    glVertex3f(-0.31, -0.15, 0.5);
    // "e"
    glVertex3f(-0.18, -0.05, 0.5);
    glVertex3f(-0.13, -0.05, 0.5);

    glVertex3f(-0.18, -0.1, 0.5);
    glVertex3f(-0.13, -0.1, 0.5);

    glVertex3f(-0.18, -0.15, 0.5);
    glVertex3f(-0.13, -0.15, 0.5);

    glVertex3f(-0.18, -0.05, 0.5);
    glVertex3f(-0.18, -0.15, 0.5);

    // "s"
    glVertex3f(-0.02, -0.05, 0.5);
    glVertex3f(0.03, -0.05, 0.5);

    glVertex3f(-0.02, -0.1, 0.5);
    glVertex3f(0.03, -0.1, 0.5);

    glVertex3f(-0.02, -0.15, 0.5);
    glVertex3f(0.03, -0.15, 0.5);

    glVertex3f(-0.02, -0.05, 0.5);
    glVertex3f(-0.02, -0.1, 0.5);

    glVertex3f(0.03, -0.1, 0.5);
    glVertex3f(0.03, -0.15, 0.5);

    // "e"
    glVertex3f(0.1, -0.05, 0.5);
    glVertex3f(0.15, -0.05, 0.5);

    glVertex3f(0.1, -0.1, 0.5);
    glVertex3f(0.15, -0.1, 0.5);

    glVertex3f(0.1, -0.15, 0.5);
    glVertex3f(0.15, -0.15, 0.5);

    glVertex3f(0.1, -0.05, 0.5);
    glVertex3f(0.1, -0.15, 0.5);

    // "t"
    glVertex3f(0.2, -0.05, 0.5);
    glVertex3f(0.3, -0.05, 0.5);

    glVertex3f(0.25, -0.05, 0.5);
    glVertex3f(0.25, -0.15, 0.5);

    glEnd();

    if (resetButtonActive)
    {
        glColor3f(0.462, 0.780, 1);
    }
    else
    {
        glColor3f(1, 1, 1);
    }

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, -0.2);
    glEnd();

    // bg
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
}