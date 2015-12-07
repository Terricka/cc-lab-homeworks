
#pragma once

#include "ofMain.h"

class Balls {
public:
    Balls();
    
    void setup();
    void move();
    void display();
    void collide();
    
    ofPoint pos;
    ofPoint speed;
    
    int diameter;
    
    int r, g, b;
    
    //    float vx;
    //    float vy;
    
    
};