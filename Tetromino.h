
#ifndef Tetronimo_h
#define Tetronimo_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Rect.h"
#include "Pairs.h"
enum tMoShape{tShape , sShape, lShape, zShape, mlShape, sqShape};
enum Color{red, green, yellow};
enum tMoVersion{v1, v2, v3, v4};

using namespace std;

class Tetromino{
    vector<vector<Rect *>> tMosData;
    tMoShape shape;
    tMoVersion version;
    vector<vector<vector<Pairs *>>> models;
    
public:
    Tetromino();
    void draw();
    void rotate();
    bool validPos();
    ~Tetromino();
};

#endif /* Tetronimo_hpp */
