
#ifndef Tetronimo_h
#define Tetronimo_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Rect.h"
enum tMoShape{sShape, lShape, tShape, zShape, mlShape, sqShape};
enum Color{red, green, yellow};

using namespace std;

class Tetromino{
    vector<vector<Rect *>> tMosData;
    tMoShape shape;    
    
    
public:
    Tetromino();
    void draw();
    void rotate();
    bool validPos();
    ~Tetromino();
};

#endif /* Tetronimo_hpp */
