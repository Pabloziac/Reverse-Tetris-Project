#include "Grid.h"
Grid::Grid()
{
    int yElements = 13;
    int xElements = 13;
    float width = 0.14;
    float height = 0.14;
    std::vector<std::vector<Rect *>> matrix;
    for (int i = 0; i < yElements; i++)
    {
        std::vector<Rect *> aRow;
        for (int j = 0; j < xElements; j++)
        {
            float x;
            float y;

            x = -1.5 + width * i + 0.007 * i;
            y = 1.0 - width * j - 0.007 * j;

            aRow.push_back(new Rect(x, y, width, height, 0.4, 0.9, 0.4));
        }
        matrix.push_back(aRow);
    }
    gridData = matrix;
}

void Grid::Print()
{
    std::cout << "Grid \n";
    for (int i = 0; i < gridData.size(); i++)
    {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {

            std::cout << gridData.at(i).at(j)
                      << " ";
        }
        std::cout << std::endl;
    }
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
void Grid::draw()
{
    for (int i = 0; i < gridData.size(); i++)
    {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            Rect *curr = gridData.at(i).at(j);
            curr->draw();
        }
    }
}

Grid::~Grid()
{
}
