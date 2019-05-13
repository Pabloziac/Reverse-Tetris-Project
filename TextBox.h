#ifndef TextBox_hpp
#define TextBox_hpp

#include <string>
#include "Shape.h"

class TextBox: public Shape {
    std::string text;
    float x;
    float y;
    
    void* font;
    float r;
    float g;
    float b;
    int width;
    int score;
public:
    TextBox(
            
            char* = "My TextBox",
            float = 0,
            float = 0,
            void* = GLUT_BITMAP_HELVETICA_18,
            float = 1,
            float = 1,
            float = 1,
            int = 800,
            int = 0
    );
    
    void draw() const;
    void draw(int x);
};

#endif /* TextBox_hpp */
