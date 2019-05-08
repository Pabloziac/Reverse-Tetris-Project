#ifndef App_h
#define App_h
#include <vector>

#include "GlutApp.h"
#include "Game.h"
#include "Ad.h"

class App: public GlutApp {
    
    std::vector<AppComponent*> components;
    
    void addComponent(AppComponent* component){
        components.push_back(component);
    }
    
    bool fullscreen;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
};

#endif
