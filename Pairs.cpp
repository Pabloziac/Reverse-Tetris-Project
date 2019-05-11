//
//  Pairs.cpp
//  glutapp
//
//  Created by Anthony Choi on 5/10/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "Pairs.h"

Pairs::Pairs(){
}
Pairs::Pairs(int x, int y){
    this->x = x;
    this->y = y;
}

int Pairs::getX(){
    return x;
}

int Pairs::getY(){
    return y;
}

void Pairs::setPair(int x, int y){
    this->x = x;
    this->y = y;
}

void Pairs::setX(int x){
    this->x = x;
}

void Pairs::setY(int y){
    this->y = y;
}

