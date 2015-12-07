#include "balls.h"

Balls::Balls(){
    
}

void Balls::setup(){
    pos.x = ofRandomHeight();
    pos.y = ofRandomWidth();
    
    speed.x = 8;
    speed.y = 8;
    
    diameter = 20;
    
    r = ofRandom(0, 255);
    g = ofRandom(0, 255);
    b = ofRandom(0, 255);
    
    int x = ofRandomWidth();
    int y = ofRandomHeight();
}

void Balls::move(){
    pos.x += speed.x;
    pos.y += speed.y;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth() + diameter){
        speed.x = -speed.x;
    }
    
    if(pos.y < 0 || pos.y > ofGetWindowHeight() + diameter){
        speed.y = -speed.y;
    }
}

void Balls::display(){
    
    ofSetColor(r, g, b);
    ofCircle(pos.x, pos.y, diameter);
    
}

void Balls::collide(){
    
}