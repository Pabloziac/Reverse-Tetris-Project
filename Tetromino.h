
#ifndef Tetronimo_h
#define Tetronimo_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Grid.h"
#include "Rect.h"
#include "Pairs.h"

enum tMoShape
{
    tShape,
    lShape,
    mlShape,
    sShape,
    zShape,
    sqShape,
    iShape,
    // testShape
};
enum Color
{
    red,
    green,
    yellow
};
enum tMoVersion
{
    v1,
    v2,
    v3,
    v4
};

using namespace std;

class Tetromino
{
public:
    vector<vector<Rect *>> tMosData;
    tMoShape shape;
    tMoVersion version;
    vector<vector<vector<Pairs *>>> models;

    float width;
    float height;

    float xoffset;
    float yoffset;

    int gi;
    int gj;

    Tetromino();
    void draw();
    void clear();
    void rotate();
    bool validPos();
    void setupFrame();
    void nextAction(Grid *grid, int, int);
    bool touchedBoundary();
    void nextVersion();
    void shiftOffset();
    void shiftOffsetX(float val);
    void shiftOffsetY(float val);
    void generateModels();
    ~Tetromino();
};

#endif /* Tetronimo_hpp */
