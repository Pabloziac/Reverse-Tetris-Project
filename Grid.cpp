#include "Grid.h"
#include "Rect.h"

Grid::Grid()
{
    // Grid states
    currentState = chillin;

    // deleting behavior
    deletingState = notDeleting;
    deletingRowIndex = -3;

    yElements = 20;
    xElements = 13;
    rectWidth = 0.14;
    rectHeight = 0.14;
    std::vector<std::vector<Rect *>> matrix;
    gridData = matrix;
    resetGrid();
}

void Grid::resetGrid()
{
    for (int i = 0; i < yElements; i++)
    {
        std::vector<Rect *> aRow;
        for (int j = 0; j < xElements; j++)
        {
            float x = -1.5 + rectWidth * j + 0.006 * j;
            float y = 1.0 - rectHeight * i - 0.006 * i;
            if (i < 1)
            {
                aRow.push_back(new Rect(x, y, rectWidth, rectHeight, 0.4, 0.9, 0.4));
            }
            else
            {
            aRow.push_back(NULL);
            }
        }
        gridData.push_back(aRow);
    }
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
    // rows
    for (int i = 0; i < gridData.size(); i++)
    {
        // rect
        if (!(currentState == deletingARow && deletingRowIndex == i))
        {
            for (int j = 0; j < gridData.at(i).size(); j++)
            {
                Rect *curr = gridData.at(i).at(j);
                // std::cout << "rec to draw" << curr << std::endl;
                if (curr != NULL)
                {
                    curr->draw();
                }
            }
        }
    }
}
Rect *Grid::getAt(int y, int x)
{
    return gridData.at(y).at(x);
}

// deleting behavior
void Grid::deleteRow(int i)
{
    deletingRowIndex = i;
    std::cout << "set to delete row: " << i << std::endl;
    currentState = deletingARow;
    deletingState = movingRects;
}

void Grid::continueMovingRects()
{
    if (currentState == deletingARow && deletingState == movingRects)
    {
        bool willStop = false;
        // go through all elements in row
        for (int movingRowsIndex = deletingRowIndex + 1; movingRowsIndex < gridData.size(); movingRowsIndex++)
        {
            for (int i = 0; i < gridData.at(movingRowsIndex).size(); i++)
            {
                float yPos = gridData.at(movingRowsIndex).at(i)->getY();
                yPos += 0.00035;
                gridData.at(movingRowsIndex).at(i)->setY(yPos);
                if (deletingRowIndex + 1 == movingRowsIndex)
                {
                    int borderIndexRow = deletingRowIndex - 1;
                    // dev tests
                    gridData.at(borderIndexRow).at(i)->setG(0);
                    gridData.at(borderIndexRow).at(i)->setB(0);

                    if (gridData.at(borderIndexRow).at(i)->touchesBottomEdge(gridData.at(movingRowsIndex).at(i)))
                    {
                        willStop = true;
                    }
                }
            }
        }
        if (willStop)
        {
            std::vector<std::vector<Rect *>>::iterator nth = gridData.begin() + deletingRowIndex;
            gridData.erase(nth);
            deletingRowIndex = 0;
            currentState = chillin;
            deletingState = notDeleting;
        }
        glutPostRedisplay();
    }
}

void Grid::setAt(int i, int j, float x, float y, float w, float h, float r, float g, float b)
{
    std::cout << "i " << i << std::endl;
    std::cout << "j " << j << std::endl;

    std::cout << "rows " << gridData.size() << std::endl;
    std::cout << "columns " << gridData.at(j).size() << std::endl;

    Rect *copy = new Rect(x, y, w, h, r, g, b);
    gridData.at(j).at(i) = copy;
    std::cout << "rec in grid: " << gridData.at(j).at(i) << std::endl;
}

Grid::~Grid()
{
}
