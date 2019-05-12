
#ifndef Pairs_h
#define Pairs_h

#include <stdio.h>

class Pairs{
private:
    float x;
    float y;
    
public:
    Pairs();
    Pairs(float, float);
    Pairs getPair();
    void setPair(float, float);
    void setX(float);
    void setY(float);
    float getX();
    float getY();
    ~Pairs();
};

#endif /* Pairs_h */
