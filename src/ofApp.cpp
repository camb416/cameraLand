#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numBoxes = 4096;
    generateBoxes();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //cam.tilt(ofGetElapsedTimef());
    vel += acc;
    vel *= friction;
    
    // could also use cam.move(x,y,z);
    cam.dolly(vel.z);
    cam.truck(vel.x);
    
    if(isMouseDown){
        cam.tilt((ofGetMouseY()-mouseDownPosition.y)/50.0f);
        cam.pan((ofGetMouseX()-mouseDownPosition.x)/50.0f);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    cam.begin();
    ofEnableDepthTest();
    ofPushMatrix();

    for(int i=0;i<boxSizes.size();i++){
        
        ofPoint p = *boxPositions.at(i);
        ofSetColor(boxColors.at(i));
        ofFill();
        ofDrawBox(p,boxSizes.at(i) * (sin((float)i + ofGetElapsedTimef())*0.25f + 1.0f));
    }
    ofPopMatrix();
    ofDisableDepthTest();
  
    
    cam.end();
    
    if(isMouseDown){
        ofFill();
        ofSetColor(255);
        ofDrawEllipse(mouseDownPosition.x,mouseDownPosition.y,10,10);
        ofDrawEllipse(ofGetMouseX(),ofGetMouseY(),5,5);
        ofDrawLine(mouseDownPosition.x,mouseDownPosition.y,ofGetMouseX(),ofGetMouseY());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   // acc = 1.0f;
    ofLog() << key;
    switch(key){
            case 'w':
            case 'W':
        case 357: // UP
            acc.z = -keyAcc;
            break;
        case 'd':
        case 'D':
        case 358: // RIGHT
            acc.x = keyAcc;
            break;
        case 's':
        case 'S':
        case 359: // DOWN
            acc.z = keyAcc;
            break;
        case 'a':
        case 'A':
        case 356: // LEFT
            acc.x = -keyAcc;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ofLog() << key;
    switch(key){
        case 'w':
        case 'W':
        case 357: // UP
            acc.z = 0;
            break;
        case 'd':
        case 'D':
        case 358: // RIGHT
            acc.x = 0;
            break;
        case 's':
        case 'S':
        case 359: // DOWN
            acc.z = 0;
            break;
        case 'a':
        case 'A':
        case 356: // LEFT
            acc.x = 0;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    isMouseDown = true;
    mouseDownPosition.set(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isMouseDown = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
void ofApp::generateBoxes(){
    boxPositions.clear();
    boxSizes.clear();
    boxColors.clear();
    
    int minBoxPos = -1000;
    int maxBoxPos = 1000;
    
    
    for(int i=0;i<numBoxes;i++){
        float _x = ofRandom(minBoxPos, maxBoxPos);
        float _y = ofRandom(minBoxPos, maxBoxPos);
        float _z = ofRandom(minBoxPos, maxBoxPos);
        
        ofPoint * p = new ofPoint(_x,_y,_z);
        boxPositions.push_back(p);
        
        float _s = ofRandom(5,20);
        boxSizes.push_back(_s);
        
        ofColor c = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        boxColors.push_back(c);
    }
    
    
    
}
