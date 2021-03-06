#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Grid.h"
#include "Tetromino.h"
#include "TextBox.h"
#include "Menu.h"

class Game : public AppComponent, private Timer
{
    TexRect *mushroom;
    Rect *projectile;
    Grid *grid;
    Tetromino *tmos;
    TextBox *scoreBoard;
    Menu *menu;
    int tickCounts;
    int resetAt = 1000;
    bool projectileVisible;
    bool mushroomVisible;
    bool up;
    bool left;
    bool hit;
    float theta;
    float deg;
    int score = 0;
    bool gameStarted; 

public:
    AnimatedRect *explosion;
    Game();
    void startGame();
    void draw() const;
    void handleKeyDown(unsigned char, float, float);
    void handleSpecialKeyDown(int, float, float);
    void handleLeftMouseDown(float, float);
    // void handlefloat, float);

    void continueMovingRects();
    void action();
    ~Game();
};

#endif
