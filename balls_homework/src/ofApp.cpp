#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    r = ofRandom(0, 255);
    g = ofRandom(0, 255);
    b = ofRandom(0, 255);
    
    ofBackground(r, g, b);
    ofSetColor(0, 155, 50);
    
    
    for (int i=0; i < numballs; i++){
        arrayOfBalls[i].setup();
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myBalls.move();
    
    for (int i=0; i < numballs; i= i+1){
        arrayOfBalls[i].move();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myBalls.display();
    for (int i=0; i < numballs; i= i+1){
        arrayOfBalls[i].display();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
