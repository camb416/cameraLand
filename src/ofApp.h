#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector<ofPoint*> boxPositions;
        vector<float> boxSizes;
        vector<ofColor> boxColors;
    
    void generateBoxes();
    
    int numBoxes;
    
    
    ofCamera cam;
    
    ofVec2f mouseDownPosition;
    bool isMouseDown;
    
    float keyAcc = 2.0f;
    
    float maxVel = 100.0f;
    float friction = 0.9f;
    
    
    ofPoint acc;
    ofPoint vel;
    
		
};
