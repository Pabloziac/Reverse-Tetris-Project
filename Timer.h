#ifndef Timer_h
#define Timer_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <thread>
#include <chrono>

class Timer {
    int interval;
    
    int delta;
    int initial;
    std::thread timerThread;
    
    static void repeat(Timer*);
public:
    bool running;
    Timer();
    
    void start();
    
    void setRate(int);
    
    void stop();
    
    ~Timer();
    
    virtual void action() = 0;
};


#endif
