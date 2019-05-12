
#ifndef Pairs_h
#define Pairs_h

#include <stdio.h>

class Pairs{
private:
    int x;
    int y;
    
public:
    Pairs();
    Pairs(int, int);
    Pairs getPair();
    void setPair(int, int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    ~Pairs();
};

#endif /* Pairs_h */
