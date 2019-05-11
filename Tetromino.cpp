
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
    shape = tShape;
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
    // tShape v1
    vector<Pairs *> tShapeV1;
    Pairs* pair1 = new Pairs(0, 1);
    Pairs* pair2 = new Pairs(1, 0);
    Pairs* pair3 = new Pairs(1, 0);
    Pairs* pair4 = new Pairs(1, 2);
            
    tShapeV1.push_back(pair1);
    tShapeV1.push_back(pair2);
    tShapeV1.push_back(pair3);
    tShapeV1.push_back(pair4);
            
    cout << pair1->getX() << endl;
    cout << pair1->getY() << endl;
    tShapeList.push_back(tShapeV1);
    //this is the error.
    modelsVector[shape].push_back(tShapeV1);
    cout << "here" << endl;
    models = modelsVector;

        
//        if(version == v2){
//
//        }
//        if(version == v3){
//
//        }
//        if(version == v4){
//
//        }
//
//
//    if(shape == tShape){
//        for(int i = 0; i < yElements; i++){//y
//            vector<Rect *>aRow;
//
//            for(int j = 0; j < xElements; j++){//x
//                float x;
//                float y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==1) || (i==1 && j==0) || (i==1 && j==1) || (i==1 && j==2)){
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
//
//    if(shape == mlShape){
//        for(int i = 0; i < yElements; i++){//y
//            vector<Rect *>aRow;
//            for(int j = 0; j < xElements; j++){//x
//                float x;
//                float y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==0) || (i==0 && j==1) || (i==1 && j==1) || (i==2 && j==1)){
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
//
//    if(shape == sShape){
//        for(int i = 0; i < yElements; i++){//y(vertically)
//            vector<Rect *>aRow;
//            for(int j = 0; j < xElements; j++){//x(horizontally)
//                float x;
//                float y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==1) || (i==1 && j==0) || (i==1 && j==1) || (i==2 && j==0)){
//                    aRow.push_back(new Rect(x, y, width, height, 0, 0, 1));
//                }
//                else{
//                    aRow.push_back(NULL);
//                }
//            }
//            tMo.push_back(aRow);
//        }
//        tMosData = tMo;
//   }
//
//    if(shape == zShape){
//        for(int i = 0; i < 3; i++){//y(vertically)
//            vector<Rect *>aRow;
//            for(int j = 0; j < 2; j++){//x(horizontally)
//                float x;
//                float y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==0) || (i==1 && j==0) || (i==1 && j==1) || (i==2 && j==1)){
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
//
//   if(shape == lShape){
//        for(int i = 0; i < 3; i++){//y
//            vector<Rect *>aRow;
//            for(int j = 0; j < 2; j++){//x
//                float x;
//                float y;
//                x = 1 + width * j + 0.007 * j;
//                y = 1.0 - height * i - 0.007 * i;
//                if((i==0 && j==0) || (i==0 && j==1) || (i==1 && j==0) || (i==2 && j==0)){
//                    aRow.push_back(new Rect(x, y, width, height, 0, 0, 1));
//                }
//                else{
//                    aRow.push_back(NULL);
//                }
//            }
//            tMo.push_back(aRow);
//        }
//        tMosData = tMo;
//   }
//
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

