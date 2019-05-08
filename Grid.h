#ifndef Grid_h
#define Grid_h

#include <vector>
#include <iostream>
#include "Rect.h"
class Grid
{
public:
    std::vector<std::vector<Rect *>> gridData;
    Grid();
    void Print();
    void draw(); 
    std::vector<int> ContainsFullRows();
    ~Grid();
};

#endif