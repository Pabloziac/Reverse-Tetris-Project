#ifndef Rect_h
#define Rect_h

#include "Shape.h"

class Rect : public Shape
{
protected:
    float x;
    float y;
    float w;
    float h;

    float r;
    float g;
    float b;

    // position on grid
    int i;
    int j;     

public:
    Rect(float = 0.0f, float = 0.0f, float = 0.4f, float = 0.2f, float = 1.0f, float = 1.0f, float = 1.0f);

    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;

    float getR() const;
    float getG() const;
    float getB() const;

    int getI(); 
    int getJ(); 

    void setX(float);
    void setY(float);
    void setW(float);
    void setH(float);

    void setR(float);
    void setG(float);
    void setB(float);

    void setI(); 
    void setJ();     

    bool contains(float, float) const;

    bool touchesBottomEdge(Rect *fromBottomRect);
    void redrawScene();

    virtual void draw() const;

    virtual ~Rect();
};

#endif
