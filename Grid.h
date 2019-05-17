#ifndef Grid_h
#define Grid_h

#include <vector>
#include <iostream>
#include "Rect.h"
enum State
{
    deletingARow,
    chillin
};
enum DeletingStates
{
    notDeleting,
    movingRects
};

class Grid
{
private:
    State currentState;

    DeletingStates deletingState;
    int deletingRowIndex;

    int yElements;
    int xElements;
    float rectWidth;
    float rectHeight;

public:
    std::vector<std::vector<Rect *>> gridData;
    Grid();
    void Print();
    void draw();
    std::vector<int> ContainsFullRows();
    void setAt(int i, int j, float x, float y, float w, float h, float r, float g, float b);
    Rect *getAt(int x, int y);
    void deleteRow(int i);
    void resetGrid();
    void continueMovingRects();
    ~Grid();
};

#endif
