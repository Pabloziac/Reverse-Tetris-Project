#ifndef Grid_h
#define Grid_h

#include <vector>
#include <iostream>
class Grid
{
public:
    std::vector<std::vector<int>> gridData;
    Grid();
    void Print();
    std::vector<int> ContainsFullRows();
    ~Grid();
};

#endif