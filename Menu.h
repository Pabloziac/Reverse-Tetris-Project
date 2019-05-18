#ifndef Menu_h
#define Menu_h
#include <string>
using std::string;

struct Menu
{
    bool button1Active;
    bool button2Active;
    bool resetButtonActive;

    Menu();

    void handleHover(float x, float y, bool gameOver);

    bool didClickButton1(float x, float y);
    bool didClickButton2(float x, float y);
    bool didClickResetButtom(float x, float y);

    void draw();
    void showWinner(string company);
    void reset();
};

#endif /* Menu_h */
