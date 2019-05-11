
#include <vector>
#include "Rect.h"
#include "Shape.h"
#include "Tetromino.h"

using namespace std;



Tetromino::Tetromino()
{
    int yElements = 4;
    int xElements = 4;
    float width = 0.14;
    float height = 0.14;
    shape = sShape;
    vector<vector<Rect *>> tMo;
    
   // if(shape == sqShape){
        cout << "square shape" << endl;
        for(int i = 0; i < yElements; i++){
            vector<Rect *>aRow;
            for(int j = 0; j < xElements; j++){
                float x;
                float y;
                x = 1 + width * j + 0.007 * j;
                y = 1.0 - height * i - 0.007 * i;
                if(j == 1){
                    aRow.push_back(new Rect(x, y, width, height, 0, 0, 1));
                }
                
                // typign studdd
            }
            tMo.push_back(aRow);
        }
        tMosData = tMo;
   // }
    //changes
    for(int i = 0; i < yElements; i++){
        vector<Rect *>aRow;
        for(int j = 0; j < xElements; j++){
            float x;
            float y;
            x = 1 + width * j + 0.007 * j;
            y = 1.0 - height * i - 0.007 * i;
            if(i ==1){
                aRow.push_back(new Rect(x, y, width, height, 0, 0, 1));
            }
        }
        tMo.push_back(aRow);
    }
    tMosData = tMo;

}

void Tetromino::draw(){
    for(int i = 0; i < tMosData.size(); i++){
        for(int j = 0; j < tMosData.at(i).size(); j++){
            Rect* curr = tMosData.at(i).at(j);
            curr->draw();
        }
    }
}

Tetromino::~Tetromino()
{
}

