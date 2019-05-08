#include "Ad.h"
#include <string>

Ad::Ad(const char* text, const char* url){
    textbox = new TextBox(text, -0.3, 0.9);
    this->url = url;
}


void Ad::draw() const {
    textbox->draw();
}

void Ad::handleKeyDown(unsigned char key, float x, float y) {
    std::string url_s(url);
    
    url_s = "open " + url_s;
    
    if (key == '1'){
        system(url_s.c_str());
    }
}

Ad::~Ad(){
    delete textbox;
}
