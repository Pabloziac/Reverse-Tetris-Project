#include <iostream>
#include "App.h"
#include "Grid.h"

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    addComponent(new Game());
    addComponent(new Ad("See the best Android phones. Press 1.", "http://apple.com"));
    
    Grid *grid = new Grid();
    grid->Print(); 
    
    fullscreen = false;
}

void App::draw() const {
    for (std::vector<AppComponent*>::const_iterator i = components.begin(); i != components.end(); ++i) {
        (*i)->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    else{
        for (std::vector<AppComponent*>::iterator i = components.begin(); i != components.end(); ++i) {
            (*i)->handleKeyDown(key, x, y);
        }
    }
}
App::~App(){    
    for (std::vector<AppComponent*>::iterator i = components.begin(); i != components.end(); ++i) {
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
