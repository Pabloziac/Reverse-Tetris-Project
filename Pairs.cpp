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
Pairs::Pairs(float x, float y){
    this->x = x;
    this->y = y;
}

float Pairs::getX(){
    return x;
}

float Pairs::getY(){
    return y;
}

void Pairs::setPair(float x, float y){
    this->x = x;
    this->y = y;
}

void Pairs::setX(float x){
    this->x = x;
}

void Pairs::setY(float y){
    this->y = y;
}

