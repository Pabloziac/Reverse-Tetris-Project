#ifndef Ad_hpp
#define Ad_hpp

#include "AppComponent.h"
#include "TextBox.h"

class Ad: public AppComponent {
    const char* text;
    const char* url;
    TextBox* textbox;
    
public:
    Ad(const char* text, const char* url);
    
    void draw() const;
    void handleKeyDown(unsigned char, float, float);
    
    ~Ad();
};

#endif /* Ad_hpp */
