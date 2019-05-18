
#include <vector>
#include <stdlib.h>
#include "Rect.h"
#include "Shape.h"
#include "Tetromino.h"
#include "Pairs.h"
#include "Grid.h"

using namespace std;

Tetromino::Tetromino()
{
    setShapeAndRotation();

    int yElements = 4;
    int xElements = 4;

    width = 0.14;
    height = 0.14;

    xMin = 0;
    xMax = 0;
    yMin = 0;
    yMax = 0;

    gj = 5;
    gi = 13;

    // create frame
    vector<vector<Rect *>> tMo;
    for (int j = 0; j < yElements; j++)
    {
        vector<Rect *> aRow;
        for (int j = 0; j < xElements; j++)
        {
            aRow.push_back(NULL);
        }
        tMo.push_back(aRow);
    }
    tMosData = tMo;

    vector<vector<vector<Pairs *>>> models;
    models = models;

    generateModels();

    setupFrame();
}
void Tetromino::reset()
{
    clear();
    cout << "finished clearing" << endl;
    setShapeAndRotation();
    cout << "setting rotation" << endl;

    xMin = 0;
    xMax = 0;
    yMin = 0;
    yMax = 0;

    gj = 5;
    gi = 13;

    setupFrame();
    cout << "finished setting up frame" << endl;
}
void Tetromino::generateModels()
{

    //    vector of pairs  = models.at(shape).at(version)

    vector<vector<Pairs *>> tShapeList;
    // tShape shape =0
    vector<Pairs *> tShapeV1;
    vector<Pairs *> tShapeV2;
    vector<Pairs *> tShapeV3;
    vector<Pairs *> tShapeV4;

    Pairs *tShapeV1pair1 = new Pairs(0, 1);
    Pairs *tShapeV1pair2 = new Pairs(1, 0);
    Pairs *tShapeV1pair3 = new Pairs(1, 1);
    Pairs *tShapeV1pair4 = new Pairs(1, 2);

    Pairs *tShapeV2pair1 = new Pairs(2, 1);
    Pairs *tShapeV2pair2 = new Pairs(1, 1);
    Pairs *tShapeV2pair3 = new Pairs(0, 1);
    Pairs *tShapeV2pair4 = new Pairs(1, 2);

    Pairs *tShapeV3pair1 = new Pairs(0, 1);
    Pairs *tShapeV3pair2 = new Pairs(1, 0);
    Pairs *tShapeV3pair3 = new Pairs(1, 1);
    Pairs *tShapeV3pair4 = new Pairs(1, 2);

    Pairs *tShapeV4pair1 = new Pairs(1, 0);
    Pairs *tShapeV4pair2 = new Pairs(1, 1);
    Pairs *tShapeV4pair3 = new Pairs(0, 1);
    Pairs *tShapeV4pair4 = new Pairs(2, 1);

    tShapeV1.push_back(tShapeV1pair1);
    tShapeV1.push_back(tShapeV1pair2);
    tShapeV1.push_back(tShapeV1pair3);
    tShapeV1.push_back(tShapeV1pair4);

    tShapeV2.push_back(tShapeV2pair1);
    tShapeV2.push_back(tShapeV2pair2);
    tShapeV2.push_back(tShapeV2pair3);
    tShapeV2.push_back(tShapeV2pair4);

    tShapeV3.push_back(tShapeV3pair1);
    tShapeV3.push_back(tShapeV3pair2);
    tShapeV3.push_back(tShapeV3pair3);
    tShapeV3.push_back(tShapeV3pair4);

    tShapeV4.push_back(tShapeV4pair1);
    tShapeV4.push_back(tShapeV4pair2);
    tShapeV4.push_back(tShapeV4pair3);
    tShapeV4.push_back(tShapeV4pair4);

    tShapeList.push_back(tShapeV1);
    tShapeList.push_back(tShapeV2);
    tShapeList.push_back(tShapeV3);
    tShapeList.push_back(tShapeV4);

    models.push_back(tShapeList);

    vector<vector<Pairs *>> lShapeList;
    // lShape shape=1
    vector<Pairs *> lShapeV1;
    vector<Pairs *> lShapeV2;
    vector<Pairs *> lShapeV3;
    vector<Pairs *> lShapeV4;

    Pairs *lShapeV1pair1 = new Pairs(0, 2);
    Pairs *lShapeV1pair2 = new Pairs(1, 0);
    Pairs *lShapeV1pair3 = new Pairs(1, 1);
    Pairs *lShapeV1pair4 = new Pairs(1, 2);

    Pairs *lShapeV2pair1 = new Pairs(0, 1);
    Pairs *lShapeV2pair2 = new Pairs(1, 1);
    Pairs *lShapeV2pair3 = new Pairs(2, 1);
    Pairs *lShapeV2pair4 = new Pairs(2, 2);

    Pairs *lShapeV3pair1 = new Pairs(1, 0);
    Pairs *lShapeV3pair2 = new Pairs(1, 1);
    Pairs *lShapeV3pair3 = new Pairs(2, 0);
    Pairs *lShapeV3pair4 = new Pairs(1, 2);

    Pairs *lShapeV4pair1 = new Pairs(0, 0);
    Pairs *lShapeV4pair2 = new Pairs(1, 1);
    Pairs *lShapeV4pair3 = new Pairs(0, 1);
    Pairs *lShapeV4pair4 = new Pairs(2, 1);

    lShapeV1.push_back(lShapeV1pair1);
    lShapeV1.push_back(lShapeV1pair2);
    lShapeV1.push_back(lShapeV1pair3);
    lShapeV1.push_back(lShapeV1pair4);

    lShapeV2.push_back(lShapeV2pair1);
    lShapeV2.push_back(lShapeV2pair2);
    lShapeV2.push_back(lShapeV2pair3);
    lShapeV2.push_back(lShapeV2pair4);

    lShapeV3.push_back(lShapeV3pair1);
    lShapeV3.push_back(lShapeV3pair2);
    lShapeV3.push_back(lShapeV3pair3);
    lShapeV3.push_back(lShapeV3pair4);

    lShapeV4.push_back(lShapeV4pair1);
    lShapeV4.push_back(lShapeV4pair2);
    lShapeV4.push_back(lShapeV4pair3);
    lShapeV4.push_back(lShapeV4pair4);

    lShapeList.push_back(lShapeV1);
    lShapeList.push_back(lShapeV2);
    lShapeList.push_back(lShapeV3);
    lShapeList.push_back(lShapeV4);

    models.push_back(lShapeList);

    vector<vector<Pairs *>> mlShapeList;
    // mlShape shape=2
    vector<Pairs *> mlShapeV1;
    vector<Pairs *> mlShapeV2;
    vector<Pairs *> mlShapeV3;
    vector<Pairs *> mlShapeV4;

    Pairs *mlShapeV1pair1 = new Pairs(1, 0);
    Pairs *mlShapeV1pair2 = new Pairs(1, 1);
    Pairs *mlShapeV1pair3 = new Pairs(1, 2);
    Pairs *mlShapeV1pair4 = new Pairs(2, 2);

    Pairs *mlShapeV2pair1 = new Pairs(2, 0);
    Pairs *mlShapeV2pair2 = new Pairs(0, 1);
    Pairs *mlShapeV2pair3 = new Pairs(1, 1);
    Pairs *mlShapeV2pair4 = new Pairs(2, 1);

    Pairs *mlShapeV3pair1 = new Pairs(1, 0);
    Pairs *mlShapeV3pair2 = new Pairs(1, 1);
    Pairs *mlShapeV3pair3 = new Pairs(0, 0);
    Pairs *mlShapeV3pair4 = new Pairs(1, 2);

    Pairs *mlShapeV4pair1 = new Pairs(0, 1);
    Pairs *mlShapeV4pair2 = new Pairs(1, 1);
    Pairs *mlShapeV4pair3 = new Pairs(2, 1);
    Pairs *mlShapeV4pair4 = new Pairs(0, 2);

    mlShapeV1.push_back(mlShapeV1pair1);
    mlShapeV1.push_back(mlShapeV1pair2);
    mlShapeV1.push_back(mlShapeV1pair3);
    mlShapeV1.push_back(mlShapeV1pair4);

    mlShapeV2.push_back(mlShapeV2pair1);
    mlShapeV2.push_back(mlShapeV2pair2);
    mlShapeV2.push_back(mlShapeV2pair3);
    mlShapeV2.push_back(mlShapeV2pair4);

    mlShapeV3.push_back(mlShapeV3pair1);
    mlShapeV3.push_back(mlShapeV3pair2);
    mlShapeV3.push_back(mlShapeV3pair3);
    mlShapeV3.push_back(mlShapeV3pair4);

    mlShapeV4.push_back(mlShapeV4pair1);
    mlShapeV4.push_back(mlShapeV4pair2);
    mlShapeV4.push_back(mlShapeV4pair3);
    mlShapeV4.push_back(mlShapeV4pair4);

    mlShapeList.push_back(mlShapeV1);
    mlShapeList.push_back(mlShapeV2);
    mlShapeList.push_back(mlShapeV3);
    mlShapeList.push_back(mlShapeV4);

    models.push_back(mlShapeList);

    vector<vector<Pairs *>> sShapeList;
    // sShape shape=3
    vector<Pairs *> sShapeV1;
    vector<Pairs *> sShapeV2;
    vector<Pairs *> sShapeV3;
    vector<Pairs *> sShapeV4;

    Pairs *sShapeV1pair1 = new Pairs(1, 0);
    Pairs *sShapeV1pair2 = new Pairs(1, 1);
    Pairs *sShapeV1pair3 = new Pairs(0, 1);
    Pairs *sShapeV1pair4 = new Pairs(0, 2);

    Pairs *sShapeV2pair1 = new Pairs(0, 0);
    Pairs *sShapeV2pair2 = new Pairs(1, 0);
    Pairs *sShapeV2pair3 = new Pairs(1, 1);
    Pairs *sShapeV2pair4 = new Pairs(2, 1);

    Pairs *sShapeV3pair1 = new Pairs(1, 0);
    Pairs *sShapeV3pair2 = new Pairs(1, 1);
    Pairs *sShapeV3pair3 = new Pairs(0, 1);
    Pairs *sShapeV3pair4 = new Pairs(0, 2);

    Pairs *sShapeV4pair1 = new Pairs(0, 0);
    Pairs *sShapeV4pair2 = new Pairs(1, 0);
    Pairs *sShapeV4pair3 = new Pairs(1, 1);
    Pairs *sShapeV4pair4 = new Pairs(2, 1);

    sShapeV1.push_back(sShapeV1pair1);
    sShapeV1.push_back(sShapeV1pair2);
    sShapeV1.push_back(sShapeV1pair3);
    sShapeV1.push_back(sShapeV1pair4);

    sShapeV2.push_back(sShapeV2pair1);
    sShapeV2.push_back(sShapeV2pair2);
    sShapeV2.push_back(sShapeV2pair3);
    sShapeV2.push_back(sShapeV2pair4);

    sShapeV3.push_back(sShapeV3pair1);
    sShapeV3.push_back(sShapeV3pair2);
    sShapeV3.push_back(sShapeV3pair3);
    sShapeV3.push_back(sShapeV3pair4);

    sShapeV4.push_back(sShapeV4pair1);
    sShapeV4.push_back(sShapeV4pair2);
    sShapeV4.push_back(sShapeV4pair3);
    sShapeV4.push_back(sShapeV4pair4);

    sShapeList.push_back(sShapeV1);
    sShapeList.push_back(sShapeV2);
    sShapeList.push_back(sShapeV3);
    sShapeList.push_back(sShapeV4);

    models.push_back(sShapeList);

    vector<vector<Pairs *>> zShapeList;
    // zShape shape=4
    vector<Pairs *> zShapeV1;
    vector<Pairs *> zShapeV2;
    vector<Pairs *> zShapeV3;
    vector<Pairs *> zShapeV4;

    Pairs *zShapeV1pair1 = new Pairs(0, 0);
    Pairs *zShapeV1pair2 = new Pairs(0, 1);
    Pairs *zShapeV1pair3 = new Pairs(1, 1);
    Pairs *zShapeV1pair4 = new Pairs(1, 2);

    Pairs *zShapeV2pair1 = new Pairs(0, 1);
    Pairs *zShapeV2pair2 = new Pairs(1, 0);
    Pairs *zShapeV2pair3 = new Pairs(1, 1);
    Pairs *zShapeV2pair4 = new Pairs(2, 0);

    Pairs *zShapeV3pair1 = new Pairs(0, 0);
    Pairs *zShapeV3pair2 = new Pairs(1, 1);
    Pairs *zShapeV3pair3 = new Pairs(0, 1);
    Pairs *zShapeV3pair4 = new Pairs(1, 2);

    Pairs *zShapeV4pair1 = new Pairs(0, 1);
    Pairs *zShapeV4pair2 = new Pairs(1, 0);
    Pairs *zShapeV4pair3 = new Pairs(1, 1);
    Pairs *zShapeV4pair4 = new Pairs(2, 0);

    zShapeV1.push_back(zShapeV1pair1);
    zShapeV1.push_back(zShapeV1pair2);
    zShapeV1.push_back(zShapeV1pair3);
    zShapeV1.push_back(zShapeV1pair4);

    zShapeV2.push_back(zShapeV2pair1);
    zShapeV2.push_back(zShapeV2pair2);
    zShapeV2.push_back(zShapeV2pair3);
    zShapeV2.push_back(zShapeV2pair4);

    zShapeV3.push_back(zShapeV3pair1);
    zShapeV3.push_back(zShapeV3pair2);
    zShapeV3.push_back(zShapeV3pair3);
    zShapeV3.push_back(zShapeV3pair4);

    zShapeV4.push_back(zShapeV4pair1);
    zShapeV4.push_back(zShapeV4pair2);
    zShapeV4.push_back(zShapeV4pair3);
    zShapeV4.push_back(zShapeV4pair4);

    zShapeList.push_back(zShapeV1);
    zShapeList.push_back(zShapeV2);
    zShapeList.push_back(zShapeV3);
    zShapeList.push_back(zShapeV4);

    models.push_back(zShapeList);

    vector<vector<Pairs *>> sqShapeList;
    // sqShape shape=5
    vector<Pairs *> sqShapeV1;
    vector<Pairs *> sqShapeV2;
    vector<Pairs *> sqShapeV3;
    vector<Pairs *> sqShapeV4;

    Pairs *sqShapeV1pair1 = new Pairs(0, 0);
    Pairs *sqShapeV1pair2 = new Pairs(0, 1);
    Pairs *sqShapeV1pair3 = new Pairs(1, 0);
    Pairs *sqShapeV1pair4 = new Pairs(1, 1);

    Pairs *sqShapeV2pair1 = new Pairs(0, 1);
    Pairs *sqShapeV2pair2 = new Pairs(1, 0);
    Pairs *sqShapeV2pair3 = new Pairs(1, 1);
    Pairs *sqShapeV2pair4 = new Pairs(0, 0);

    Pairs *sqShapeV3pair1 = new Pairs(0, 0);
    Pairs *sqShapeV3pair2 = new Pairs(1, 1);
    Pairs *sqShapeV3pair3 = new Pairs(0, 1);
    Pairs *sqShapeV3pair4 = new Pairs(1, 0);

    Pairs *sqShapeV4pair1 = new Pairs(0, 1);
    Pairs *sqShapeV4pair2 = new Pairs(0, 0);
    Pairs *sqShapeV4pair3 = new Pairs(1, 1);
    Pairs *sqShapeV4pair4 = new Pairs(1, 0);

    sqShapeV1.push_back(sqShapeV1pair1);
    sqShapeV1.push_back(sqShapeV1pair2);
    sqShapeV1.push_back(sqShapeV1pair3);
    sqShapeV1.push_back(sqShapeV1pair4);

    sqShapeV2.push_back(sqShapeV2pair1);
    sqShapeV2.push_back(sqShapeV2pair2);
    sqShapeV2.push_back(sqShapeV2pair3);
    sqShapeV2.push_back(sqShapeV2pair4);

    sqShapeV3.push_back(sqShapeV3pair1);
    sqShapeV3.push_back(sqShapeV3pair2);
    sqShapeV3.push_back(sqShapeV3pair3);
    sqShapeV3.push_back(sqShapeV3pair4);

    sqShapeV4.push_back(sqShapeV4pair1);
    sqShapeV4.push_back(sqShapeV4pair2);
    sqShapeV4.push_back(sqShapeV4pair3);
    sqShapeV4.push_back(sqShapeV4pair4);

    sqShapeList.push_back(sqShapeV1);
    sqShapeList.push_back(sqShapeV2);
    sqShapeList.push_back(sqShapeV3);
    sqShapeList.push_back(sqShapeV4);

    models.push_back(sqShapeList);

    vector<vector<Pairs *>> iShapeList;
    // iShape shape=6
    vector<Pairs *> iShapeV1;
    vector<Pairs *> iShapeV2;
    vector<Pairs *> iShapeV3;
    vector<Pairs *> iShapeV4;

    Pairs *iShapeV1pair1 = new Pairs(0, 0);
    Pairs *iShapeV1pair2 = new Pairs(0, 1);
    Pairs *iShapeV1pair3 = new Pairs(0, 2);
    Pairs *iShapeV1pair4 = new Pairs(0, 3);

    Pairs *iShapeV2pair1 = new Pairs(0, 0);
    Pairs *iShapeV2pair2 = new Pairs(1, 0);
    Pairs *iShapeV2pair3 = new Pairs(2, 0);
    Pairs *iShapeV2pair4 = new Pairs(3, 0);

    Pairs *iShapeV3pair1 = new Pairs(0, 0);
    Pairs *iShapeV3pair2 = new Pairs(0, 1);
    Pairs *iShapeV3pair3 = new Pairs(0, 2);
    Pairs *iShapeV3pair4 = new Pairs(0, 3);

    Pairs *iShapeV4pair1 = new Pairs(0, 0);
    Pairs *iShapeV4pair2 = new Pairs(1, 0);
    Pairs *iShapeV4pair3 = new Pairs(2, 0);
    Pairs *iShapeV4pair4 = new Pairs(3, 0);

    iShapeV1.push_back(iShapeV1pair1);
    iShapeV1.push_back(iShapeV1pair2);
    iShapeV1.push_back(iShapeV1pair3);
    iShapeV1.push_back(iShapeV1pair4);

    iShapeV2.push_back(iShapeV2pair1);
    iShapeV2.push_back(iShapeV2pair2);
    iShapeV2.push_back(iShapeV2pair3);
    iShapeV2.push_back(iShapeV2pair4);

    iShapeV3.push_back(iShapeV3pair1);
    iShapeV3.push_back(iShapeV3pair2);
    iShapeV3.push_back(iShapeV3pair3);
    iShapeV3.push_back(iShapeV3pair4);

    iShapeV4.push_back(iShapeV4pair1);
    iShapeV4.push_back(iShapeV4pair2);
    iShapeV4.push_back(iShapeV4pair3);
    iShapeV4.push_back(iShapeV4pair4);

    iShapeList.push_back(iShapeV1);
    iShapeList.push_back(iShapeV2);
    iShapeList.push_back(iShapeV3);
    iShapeList.push_back(iShapeV4);

    models.push_back(iShapeList);

    // testing shape
    vector<vector<Pairs *>> testShapeList;

    for (int l = 0; l < 4; l++)
    {
        vector<Pairs *> testShapePairs;
        for (int k = 0; k < 4; k++)
        {
            for (int g = 0; g < 4; g++)
            {
                testShapePairs.push_back(new Pairs(k, g));
            }
        }
        testShapeList.push_back(testShapePairs);
    }
    models.push_back(testShapeList);
}

void Tetromino::setShapeAndRotation()
{
    // generate random state;
    srand(time(NULL));
    int s = rand() % 7;
    int v = rand() % 4;

    // shape = (tMoShape)s;
    shape = iShape;
    version = (tMoVersion)v;
}
void Tetromino::setupFrame()
{
    cout << "settingFrame" << endl;
    for (int i = 0; i < models.at(shape).at(version).size(); i++)
    {
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();

        float x = -1.5 + (gx + gj - 1) * (width + 0.006);
        float y = 1.0 - (gy + gi - 1) * (height + 0.006);

        int gridX = gx + gj;
        int gridY = gy + gi;

        tMosData[gy][gx] = new Rect(x, y, width, height, 0, 0, 1, gridX, gridY);
        if (shape == 0)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 0, 0, .8, gridX, gridY);
        }
        if (shape == 1)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 0, .4, 1, gridX, gridY);
        }
        if (shape == 2)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 0.7, 0, 0.2, gridX, gridY);
        }
        if (shape == 3)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 0.75, 0, 0, gridX, gridY);
        }
        if (shape == 4)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 1, 0.5, 0, gridX, gridY);
        }
        if (shape == 5)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, .3, .5, 1, gridX, gridY);
        }
        if (shape == 6)
        {
            tMosData[gy][gx] = new Rect(x, y, width, height, 0.5, 0, 0.5, gridX, gridY);
        }
    }

    xMax = -1000;
    xMin = 1000;
    yMax = -1000;
    yMin = 1000;

    for (int i = 0; i < tMosData.size(); i++)
    {
        for (int k = 0; k < tMosData.at(i).size(); k++)
        {
            if (tMosData.at(i).at(k) != NULL)
            {
                if (k < xMin)
                {
                    xMin = k;
                }
                else if (k > xMax)
                {
                    xMax = k;
                }

                if (i < yMin)
                {
                    yMin = i;
                }
                else if (i > yMax)
                {
                    yMax = i;
                }
            }
        }
    }
    // cout << "xMax : " << xMax << endl;
    // cout << "xMin : " << xMin << endl;

    // cout << "yMax : " << yMax << endl;
    // cout << "yMin : " << yMin << endl;
}

void Tetromino::draw()
{
    for (int i = 0; i < tMosData.size(); i++)
    {
        for (int j = 0; j < tMosData.at(i).size(); j++)
        {
            Rect *curr = tMosData.at(i).at(j);
            if (curr != NULL)
            {
                curr->draw();
            }
        }
    }
}
bool Tetromino::canShiftX(Grid *grid, int val)
{
    int nextLeftBoundary = gj - 1 + xMin + val;
    int nextRightBoundary = gj - 1 + xMax + val;
    return nextLeftBoundary >= 0 && nextRightBoundary < 13;
}

bool Tetromino::canShiftY(Grid *grid, int val)
{
    // go through all positions in tmosData then
    // check if all next are null then return true

    for (int i = 0; i < tMosData.size(); i++)
    {
        for (int j = 0; j < tMosData.at(i).size(); j++)
        {
            Rect *curr = tMosData.at(i).at(j);
            if (curr != NULL)
            {
                int grX = tMosData.at(i).at(j)->getGridX();
                int grY = tMosData.at(i).at(j)->getGridY();

                cout << "(" << i << ", " << j << ")"
                     << "    "
                     << "(" << grY << ", " << grX << ")" << endl;

                int nextY = grY - val;

                if (nextY <= -1)
                {
                    return false;
                }
                else
                {
                    if (grid->getAt(nextY, grX) != NULL)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Tetromino::shiftOffset(int iVal, int jVal)
{
    // cout << "shiftOffset" << endl;
    for (int i = 0; i < models.at(shape).at(version).size(); i++)
    {
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();

        float x = -1.5 + (gx + gj - 1) * (width + 0.006);
        float y = 1.0 - (gy + gi - 1) * (height + 0.006);

        tMosData[gy][gx]->setX(x);
        tMosData[gy][gx]->setY(y);

        int gridX = gx + gj - jVal;
        int gridY = gy + gi - iVal;

        tMosData[gy][gx]->setGridX(gridX);
        tMosData[gy][gx]->setGridY(gridY);
    }
}

void Tetromino::shiftOffsetY(Grid *grid, int val)
{
    if (canShiftY(grid, val))
    {
        cout << "shifting " << val << endl;
        gi -= val;
        shiftOffset(val, 0);
        glutPostRedisplay();
    }
}

void Tetromino::shiftOffsetX(Grid *grid, int val)
{
    if (canShiftX(grid, val))
    {
        gj += val;
        shiftOffset(0, val);
        glutPostRedisplay();
    }
    else
    {

        cout << "x should not move" << endl;
    }
}

void Tetromino::nextVersion()
{
    clear();
    cout << " tmo version " << version << endl;

    if (version == v1)
    {
        version = v2;
    }
    else if (version == v2)
    {
        version = v3;
    }
    else if (version == v3)
    {
        version = v4;
    }
    else if (version == v4)
    {
        version = v1;
    }

    setupFrame();

    int outies = outsideRects();
    cout << "outies" << outies << endl;
    if (outies == 0)
    {
        glutPostRedisplay();
    }
    else
    {
        shiftOffsetX(NULL, outies);
    }
}
int Tetromino::outsideRects()
{
    int rightBound = gj - 1 + xMax;
    int leftBound = gj - 1 + xMin;

    if (rightBound >= 13)
    {
        return ((13 - 1) - rightBound);
    }
    else if (leftBound < 0)
    {
        return -1 * leftBound;
    }
    return 0;
}
void Tetromino::clear()
{
    // cout << "cleared" << endl;
    for (int i = 0; i < models.at(shape).at(version).size(); i++)
    {
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();
        delete tMosData[gy][gx];
        tMosData[gy][gx] = NULL;
    }
}

bool Tetromino::canContinueGoingUp(Grid *grid)
{
    cout << "canContinueGoingUp" << endl;
    // cout << "gi: " << (gi - 1) << endl;
    // cout << "gj: " << (gj - 1) << endl;
    int foundFirstRow = -1;
    // bool canMove = true;
    for (int i = 0; i < tMosData.size(); i++)
    {
        cout << "foundFirst ROw: " << foundFirstRow << endl;
        if (foundFirstRow > -1)
        {
            break;
        }

        for (int j = 0; j < tMosData.at(i).size(); j++)
        {
            if (tMosData.at(i).at(j) != NULL)
            {
                foundFirstRow = i;

                int currentX = gi - 1 + j;
                int currentY = gj + foundFirstRow - 1;
                // cout << "graph x " << currentX << endl;

                // cout << "next Y" << currentY - 1 << endl
                //  << endl;
                // cout << "checking fam" << endl;
                int nextY = currentY - 1;
                if (nextY < 0)
                {
                    return false;
                }
                else
                {
                    if (grid->getAt(nextY, nextY) != NULL)
                    {
                        cout << "can move" << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Tetromino::nextAction(Grid *grid, int ticks, int resetAt)
{
    if (ticks == resetAt)
    {
        if (canShiftY(grid, 1))
        {
            // move up
            cout << "moving up" << endl;
            shiftOffsetY(grid, 1);
        }
        else
        {
            // reset position
            cout << "touched" << endl;
            insertIntoGrid(grid);
            cout << "finished inserting for grid" << endl;

            // insert data into blocks
            // grid->check();
            reset();
        }
    }
}

void Tetromino::insertIntoGrid(Grid *grid)
{
    for (int i = 0; i < tMosData.size(); i++)
    {
        for (int j = 0; j < tMosData.at(i).size(); j++)
        {
            Rect *curr = tMosData.at(i).at(j);
            if (curr != NULL)
            {
                int currentX = gi - 1 + j;
                int currentY = gj - 1 + i;

                // cout << "currentX: " << currentX << endl;
                // cout <<deletingRowIndex "currentY: " << currentY << endl;

                cout << "current address: " << curr << endl;

                if (grid->getAt(currentX, currentY) == NULL)
                {
                    cout << "(" << currentX << "," << currentY << ")"
                         << " is NULL" << endl;
                    grid->setAt(currentX, currentY, curr->getX(), curr->getY(), curr->getW(), curr->getH(), curr->getR(), curr->getG(), curr->getB());
                }
            }
        }
    }
}

Tetromino::~Tetromino()
{
}
