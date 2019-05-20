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

    std::vector<std::vector<Rect *>> gridData;
    std::vector<int> toDelete;

public:
    Grid();
    void Print();
    void draw();
    void start();
    std::vector<int> ContainsFullRows();
    void setAt(int i, int j, float x, float y, float w, float h, float r, float g, float b);
    Rect *getAt(int x, int y);
    void deleteRows(std::vector<int> toDeleteVector);
    void resetGrid();
    int check();
    void continueMovingRects();
    ~Grid();
};

#endif
