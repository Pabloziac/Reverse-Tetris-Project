#include "Grid.h"
#include "Rect.h"

Grid::Grid()
{
    // Grid states
    currentState = chillin;

    // deleting behavior
    deletingState = notDeleting;
    deletingRow = 0;

    yElements = 20;
    xElements = 13;
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
            x = -1.5 + width * j + 0.007 * j;
            y = 1.0 - height * i - 0.007 * i;
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
    return nums;
}

void Grid::draw()
{
    for (int i = 0; i < gridData.size(); i++)
    {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            if (!(currentState == deletingARow && deletingRow == i))
            {
                Rect *curr = gridData.at(i).at(j);
                curr->draw();
            }
        }
    }
}
Rect *Grid::getAt(int x, int y)
{
    return gridData.at(x).at(y);
}

// deleting behavior
void Grid::deleteRow(int i)
{
    std::cout << "set to delete row: " << i << std::endl;
    currentState = deletingARow;
    deletingState = movingRects;
    deletingRow = i;
}

void Grid::continueMovingRects()
{
    // ggridData

    if (currentState == deletingARow && deletingState == movingRects)
    {
        // go through all elements in row
        for (int i = 0; gridData.at(deletingRow + 1).size(); i++)
        {
            gridData.at(deletingRow + 1).at(i)->setB(0.5);
        }
        for (int i = 0; gridData.at(deletingRow + 1).size(); i++)
        {
            float yPos = gridData.at(deletingARow + 1).at(i)->getY();
            yPos += 0.005;
            gridData.at(deletingARow + 1).at(i)->setY(yPos);
        }
        glutPostRedisplay();
    }
}

Grid::~Grid()
{
}
