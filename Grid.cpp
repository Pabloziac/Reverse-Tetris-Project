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
    std::vector<int> td;
    toDelete = td;
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
            // if (i < 1)
            // {
            //     aRow.push_back(new Rect(x, y, rectWidth, rectHeight, 0.4, 0.9, 0.4));
            // }
            // else
            // {
            aRow.push_back(NULL);
            // }
        }
        gridData.push_back(aRow);
    }
}
int Grid::check()
{
    // check if any rows full
    // if so then delete all rows
    // check if game is over
    std::vector<int> toDeleteList;
    for (int i = 0; i < gridData.size(); i++)
    {
        int filledSpots = 0;
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            if (gridData.at(i).at(j) != NULL)
            {
                filledSpots++;
            }
        }
        if (filledSpots == 13)
        {
            toDeleteList.push_back(i);
            // filledSpots = 0;
        }
        else if (filledSpots == 0)
        {

            break;
        }
    }

    for (int j = 0; j < toDeleteList.size(); j++)
    {
        std::cout << "will delete " << toDeleteList.at(j) << std::endl;
    }

    if (toDeleteList.size() > 0)
    {
        // std::vector<int> toDeleteList;
        deleteRows(toDeleteList);
    }
    Print();
    for (int j = 0; j < gridData.at(13).size(); j++)
    {
        if (gridData.at(13).at(j) != NULL)
        {
            std::cout << "game over" << std::endl;
            return -1;
            break;
        }
    }
    return toDeleteList.size();
}
void Grid::Print()
{
    std::cout << "Grid \n";
    for (int i = 0; i < gridData.size(); i++)
    {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            if (gridData.at(i).at(j) != NULL)
            {

                std::cout << 1
                          << " ";
            }
            else
            {
                std::cout << 0
                          << " ";
            }
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
        // if (currentState != deletingARow && deletingRowIndex != i)
        // {
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            Rect *curr = gridData.at(i).at(j);
            // std::cout << "rec to draw" << curr << std::endl;
            if (curr != NULL)
            {
                // std::cout << "" << i << " " << j << std::endl;
                curr->draw();
            }
        }
        // }
    }
}
Rect *Grid::getAt(int y, int x)
{
    return gridData.at(y).at(x);
}

// deleting behavior
void Grid::deleteRows(std::vector<int> toDeleteVector)
{
    std::cout << "deleteorws(): " << toDeleteVector.size() << std::endl;

    for (int j = 0; j < toDeleteVector.size(); j++)
    {
        std::cout << "will delete " << toDeleteVector.at(j) << std::endl;
    }

    // toDelete = toDeleteVector;
    // std::cout << "set to delete row: " << i << std::endl;
    currentState = deletingARow;
    deletingState = movingRects;

    std::vector<std::vector<Rect *>>::iterator nth = gridData.begin();
    for (int i = toDeleteVector.size() - 1; i >= 0; i--)
    {
        int pos = toDeleteVector.at(i);

        nth += pos;
        gridData.erase(nth);
        nth -= pos;

        std::vector<Rect *> aRow;
        for (int j = 0; j < xElements; j++)
        {
            aRow.push_back(NULL);
        }
        gridData.push_back(aRow);
    }
    // deletingRowIndex = 0;

    glutPostRedisplay();

    // std::1cout << "remoed rows" << std::endl;

    // Print();

    // std::vector<std::vector<Rect *>>::iterator hth = gridData.begin();

    for (int i = 0; i < gridData.size(); i++)
    {
        // rect
        // if (currentState != deletingARow && deletingRowIndex != i)
        // {
        // std::cout << "checking row" << i << std::endl;
        for (int j = 0; j < gridData.at(i).size(); j++)
        {
            float x = -1.5 + rectWidth * j + 0.006 * j;
            float y = 1.0 - rectHeight * i - 0.006 * i;

            if (gridData.at(i).at(j) != NULL)
            {
                gridData.at(i).at(j)->setX(x);
                gridData.at(i).at(j)->setY(y);
            }
        }
    }

    // toDelete.clear();
    currentState = chillin;
    deletingState = notDeleting;
    glutPostRedisplay();
}

void Grid::continueMovingRects()
{
    if (currentState == deletingARow && deletingState == movingRects)
    {
        // bool willStop = false;
        // // go through all elements in row
        // for (int movingRowsIndex = deletingRowIndex + 1; movingRowsIndex < gridData.size(); movingRowsIndex++)
        // {
        //     for (int i = 0; i < gridData.at(movingRowsIndex).size(); i++)
        //     {
        //         float yPos = gridData.at(movingRowsIndex).at(i)->getY();
        //         yPos += 0.00035;
        //         gridData.at(movingRowsIndex).at(i)->setY(yPos);
        //         if (deletingRowIndex + 1 == movingRowsIndex)
        //         {
        //             int borderIndexRow = deletingRowIndex - 1;
        //             // dev tests
        //             gridData.at(borderIndexRow).at(i)->setG(0);
        //             gridData.at(borderIndexRow).at(i)->setB(0);

        //             if (gridData.at(borderIndexRow).at(i)->touchesBottomEdge(gridData.at(movingRowsIndex).at(i)))
        //             {
        //                 willStop = true;
        //             }
        //         }
        //     }
        // }

        // if (willStop)
        // {
        //     std::vector<std::vector<Rect *>>::iterator nth = gridData.begin();
        //     for (int i = 0; i < gridData.size(); i++)
        //     {
        //         int pos = gridData.at(i);
        //         nth += pos;
        //         gridData.erase(nth);
        //         nth -= pos;
        //     }
        //     // deletingRowIndex = 0;
        //     toDelete.clear();
        //     currentState = chillin;
        //     deletingState = notDeleting;
        // }

        // glutPostRedisplay();
    }
}

void Grid::setAt(int i, int j, float x, float y, float w, float h, float r, float g, float b)
{
    // std::cout << "setting grid rec: (" << i << ", " << j << ")" << std::endl;
    Rect *copy = new Rect(x, y, w, h, r, g, b);
    gridData.at(i).at(j) = copy;
    // std::cout << "rec in grid: " << gridData.at(j).at(i) << std::endl;
}

Grid::~Grid()
{
}
