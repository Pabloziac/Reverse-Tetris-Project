
#include <vector>
#include "Rect.h"
#include "Shape.h"
#include "Tetromino.h"
#include "Pairs.h"
#include <tuple>

using namespace std;

Tetromino::Tetromino()
{
    switchversion = false;
    int yElements = 4;
    int xElements = 4;
    width = 0.14;
    height = 0.14;
    xoffset = 0;
    yoffset = 0;
    shape = iShape;
    version = v1;

    // shape
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

    vector<vector<vector<Pairs *>>> modelsVector;

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

    Pairs *tShapeV3pair1 = new Pairs(0, 0);
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

    modelsVector.push_back(tShapeList);

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

    modelsVector.push_back(lShapeList);

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

    modelsVector.push_back(mlShapeList);

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

    modelsVector.push_back(sShapeList);

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

    modelsVector.push_back(zShapeList);

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

    modelsVector.push_back(sqShapeList);

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

    modelsVector.push_back(iShapeList);

    models = modelsVector;

    setupFrame();
}

void Tetromino::setupFrame()
{
    for (int i = 0; i < models.at(shape).at(version).size(); i++)
    {
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();

        float x = -1.5 + width * gx + 0.007 * gx + xoffset;
        float y = 0.0 - height * gy - 0.007 * gy + yoffset;

        tMosData[gy][gx] = new Rect(x, y, width, height, 0, 0, 1);
    }
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

void Tetromino::setOffsetY(float val)
{
    yoffset += val;
}

void Tetromino::setOffsetX(float val)
{
    xoffset += val;
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
    glutPostRedisplay();
}
void Tetromino::clear()
{
    //cout << "cleared" <<endl;
    for (int i = 0; i < models.at(shape).at(version).size(); i++)
    {
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();
        delete tMosData[gy][gx];
        tMosData[gy][gx] = NULL;
    }
}
bool Tetromino::touchedBoundary()
{
    return true;
}
void Tetromino::nextAction()
{
    if (touchedBoundary())
    {
        // reset position
    }
    else
    {
        // move up
    }
}

Tetromino::~Tetromino()
{
}
