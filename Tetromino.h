
#ifndef Tetronimo_h
#define Tetronimo_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Rect.h"
#include "Pairs.h"
enum tMoShape{tShape , lShape, mlShape, sShape, zShape, sqShape, iShape};
enum Color{red, green, yellow};
enum tMoVersion{v1, v2, v3, v4};

using namespace std;

class Tetromino{
public:
    bool switchversion;
    vector<vector<Rect *>> tMosData;
    tMoShape shape;
    tMoVersion version;
    vector<vector<vector<Pairs *>>> models;
    
    Pairs* pos;
    float xoffset;
    float yoffset;
    
    Tetromino();
    void draw();
    void clear();
    void rotate();
    bool validPos();
    ~Tetromino();
};

#endif /* Tetronimo_hpp */
