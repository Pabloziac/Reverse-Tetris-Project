#ifndef Menu_h
#define Menu_h
#include <string>
#include "TextBox.h"

using std::string;

struct Menu
{
    bool button1Active;
    bool button2Active;
    bool resetButtonActive;
    bool gameIsOver;
    int score;
    TextBox *scoreBoard;
    TextBox *msg;

    Menu();
    void handleHover(float x, float y);

    bool didClickButton1(float x, float y);
    bool didClickButton2(float x, float y);
    bool didClickResetButtom(float x, float y);

    void draw();
    void showWinner(string company);
    void reset();
    void gameOver(int scoreNum);
};

#endif /* Menu_h */
