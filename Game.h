#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Grid.h"
#include "Tetromino.h"
#include "TextBox.h"

class Game : public AppComponent, private Timer
{
    TexRect *mushroom;
    Rect *projectile;
    Grid *grid;
    Tetromino *tmos;
    TextBox* scoreBoard;
    int tickCounts; 
    int const resetAt = 1000;
    bool projectileVisible;
    bool mushroomVisible;
    bool up;
    bool left;
    bool hit;
    float theta;
    float deg;

public:
    AnimatedRect *explosion;
    Game();
    void draw() const;
    void handleKeyDown(unsigned char, float, float);
    void handleSpecialKeyDown(int, float, float);
    void continueMovingRects();
    void action();
    ~Game();
};

#endif
