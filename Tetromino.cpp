
#include <vector>
#include "Rect.h"
#include "Shape.h"
#include "Tetromino.h"
#include "Pairs.h"
#include <tuple>

using namespace std;

Tetromino::Tetromino()
{
    int yElements = 4;
    int xElements = 4;
    float width = 0.14;
    float height = 0.14;
    shape = lShape;
    version = v1;
    
    // shape
    vector<vector<Rect *>> tMo;
    for(int j = 0; j < yElements; j++){
        vector<Rect *> aRow;
        for(int j = 0; j < xElements; j++){
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
    
    Pairs* tShapeV1pair1 = new Pairs(0, 1);
    Pairs* tShapeV1pair2 = new Pairs(1, 0);
    Pairs* tShapeV1pair3 = new Pairs(1, 1);
    Pairs* tShapeV1pair4 = new Pairs(1, 2);
    
    Pairs* tShapeV2pair1 = new Pairs(2, 1);
    Pairs* tShapeV2pair2 = new Pairs(1, 1);
    Pairs* tShapeV2pair3 = new Pairs(0, 1);
    Pairs* tShapeV2pair4 = new Pairs(1, 2);
    
    Pairs* tShapeV3pair1 = new Pairs(1, 0);
    Pairs* tShapeV3pair2 = new Pairs(1, 1);
    Pairs* tShapeV3pair3 = new Pairs(1, 2);
    Pairs* tShapeV3pair4 = new Pairs(2, 1);
    
    Pairs* tShapeV4pair1 = new Pairs(1, 0);
    Pairs* tShapeV4pair2 = new Pairs(1, 1);
    Pairs* tShapeV4pair3 = new Pairs(0, 1);
    Pairs* tShapeV4pair4 = new Pairs(2, 1);
            
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
    
    Pairs* lShapeV1pair1 = new Pairs(0, 2);
    Pairs* lShapeV1pair2 = new Pairs(1, 0);
    Pairs* lShapeV1pair3 = new Pairs(1, 1);
    Pairs* lShapeV1pair4 = new Pairs(1, 2);
    
    Pairs* lShapeV2pair1 = new Pairs(0, 1);
    Pairs* lShapeV2pair2 = new Pairs(1, 1);
    Pairs* lShapeV2pair3 = new Pairs(2, 1);
    Pairs* lShapeV2pair4 = new Pairs(2, 2);

    Pairs* lShapeV3pair1 = new Pairs(1, 0);
    Pairs* lShapeV3pair2 = new Pairs(1, 1);
    Pairs* lShapeV3pair3 = new Pairs(2, 0);
    Pairs* lShapeV3pair4 = new Pairs(1, 2);

    Pairs* lShapeV4pair1 = new Pairs(0, 0);
    Pairs* lShapeV4pair2 = new Pairs(1, 1);
    Pairs* lShapeV4pair3 = new Pairs(0, 1);
    Pairs* lShapeV4pair4 = new Pairs(2, 1);
    
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



    
    
    models = modelsVector;

//    if(shape == sqShape){
//        for(int i = 0; i < yElements; i++){
//            vector<Rect *>aRow;
//            for(int j = 0; j < xElements; j++){
//                float x, y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==0) || (i==0 && j==1) || (i==1 && j==0) || (i==1 && j==1)){
//                    aRow.push_back(new Rect(x, y, width, height, 0, 0, 1));
//                }
//                else{
//                    aRow.push_back(NULL);
//                }
//            }
//            tMo.push_back(aRow);
//        }
//        tMosData = tMo;
//    }
    

    
    for (int i = 0; i < models.at(shape).at(version).size();i++){
        int gx = models.at(shape).at(version).at(i)->getX();
        int gy = models.at(shape).at(version).at(i)->getY();

        float x = 1 + width * gx + 0.007 * gx;
        float y = 1.0 - height * gy - 0.007 * gy;

        tMosData[gy][gx] = new Rect(x, y, width, height, 0, 0, 1);
    }
}

void Tetromino::draw(){
    for(int i = 0; i < tMosData.size(); i++){
        for(int j = 0; j < tMosData.at(i).size(); j++){
            Rect* curr = tMosData.at(i).at(j);
            if(curr != NULL){
                curr->draw();
            }
        }
    }

}

Tetromino::~Tetromino()
{
}

