#ifndef Shape_hpp
#define Shape_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Shape{
public:
    virtual void draw() const = 0;
};

#endif
