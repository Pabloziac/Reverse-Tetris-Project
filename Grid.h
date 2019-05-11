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
    int deletingRow;

    int yElements;
    int xElements;

public:
    std::vector<std::vector<Rect *>> gridData;
    Grid();
    void Print();
    void draw();
    std::vector<int> ContainsFullRows();
    Rect *getAt(int x, int y);
    void deleteRow(int i);
    void continueMovingRects();
    ~Grid();
};

#endif
