#ifndef AppComponent_hpp
#define AppComponent_hpp

class AppComponent {
public:
    virtual void draw() const = 0;
    
    virtual void handleKeyUp(unsigned char, float, float){}
    virtual void handleKeyDown(unsigned char, float, float){}
    
    virtual void handleSpecialKeyDown(int, float, float){}
    virtual void handleSpecialKeyUp(int, float, float){}
    
    virtual void handleLeftMouseDown(float, float){}
    virtual void handleRightMouseDown(float, float){}
    virtual void handleLeftMouseUp(float, float){}
    virtual void handleRightMouseUp(float, float){}
    
    virtual void handleDrag(float, float){}
    
    
    virtual ~AppComponent(){}
};

#endif
