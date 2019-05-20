#include "TextBox.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;
TextBox::TextBox(
    char *text,
    float x,
    float y,
    void *font,
    float r,
    float g,
    float b,
    int width) :

                 Shape(),
                 text(text),
                 x(x),
                 y(y),
                 font(font),
                 r(r),
                 g(g),
                 b(b),
                 width(width)
{
}

void TextBox::draw() const
{
    cout << "shape.h draw() is abstract" << std::endl;
}
void TextBox::newText(char *nText)
{
    text = nText;
}

void TextBox::draw()
{
    //    int num = score;
    //    stringstream ss;
    //    ss << "SCORE : " << num;
    //
    //    const char *res = ss.str().c_str();

    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++)
    {
        glRasterPos2f(x + offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / width) * 2;
    }
}

void TextBox::drawBitmapText(float x, float y, int score)
{
    int num = score;
    //num = 41;
    stringstream ss;
    ss << "SCORE : " << num;

    const char *res = ss.str().c_str();

    glRasterPos2f(x, y);
    for (int i = 0; i < 12; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, res[i]);
    }
}
