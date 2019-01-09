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
    
    ofMesh mesh;
    ofMesh mesh2;
    
    ofEasyCam cam;
    
    float frequency;
    float timeFrequency;
    float magnitude;
    float color;
    int gridSize;
    int gridX;
    int gridY;
    int gridResolution;
    
    Boolean decreaseFreq;
    Boolean decreaseTime;
    Boolean decreaseMagnitude;
    Boolean decreaseColor;
    
    float alpha1, alpha2;
    
    
};
