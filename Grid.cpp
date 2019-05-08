#include "Grid.h"
Grid::Grid()
{
    int yElements = 13;
    int xElements = 13;
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < yElements; i++)
    {
        std::vector<int> aRow;
        for (int j = 0; j < xElements; j++)
        {
            aRow.push_back(1);
        }
        matrix.push_back(aRow);
    }
    gridData = matrix;
}

void Grid::Print()
{
    std::cout << "Cash Money \n";
}
std::vector<int> Grid::ContainsFullRows()
{
    // TODO: check each row if they are complete
    std::vector<int> nums; 
    for (int i = 0; i < gridData.size(); i++)
    {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            gridData.at(i).at(j);
        }
    }
}
Grid::~Grid()
{
}