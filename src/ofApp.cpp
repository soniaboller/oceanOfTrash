#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    decreaseFreq = true;
    decreaseTime = true;
    decreaseMagnitude = false;
    decreaseColor = false;
    frequency = 0.15;
    timeFrequency = 0.35;
    magnitude = 5.0;
    gridX = 40;
    gridY = 25;
    gridResolution = 100;
    cam.setTarget(ofVec3f(0,0,0));
    cam.setDistance(20);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    float waveTime = ofGetElapsedTimef()/10;
    float noiseTime = time * timeFrequency;
    
    ofVec3f extentXMin( gridX * -0.5, 0, gridX * -0.5 );
    ofVec3f extentXMax( gridX *  0.5, gridX, gridX *  0.5 );
    
    ofVec3f extentYMin( gridY * -0.5, 0, gridY * -0.5 );
    ofVec3f extentYMax( gridY *  0.5, gridY, gridY *  0.5 );
    
    
    if (decreaseFreq){
        frequency -= 0.0005;
        if (frequency <= 0.005){
            decreaseFreq = false;
        }
    }
    else {
        frequency += 0.0005;
        if(frequency >= 0.15){
            decreaseFreq = true;
        }
    }
    if (decreaseTime){
        timeFrequency -= 0.000005;
        if (timeFrequency <= 0.2){
            decreaseTime = false;
        }
    }
    else {
        timeFrequency += 0.000005;
        if(timeFrequency >= 0.35){
            decreaseTime = true;
        }
    }
    if (decreaseMagnitude){
        magnitude -= 0.0005;
        if (magnitude <= 5.0){
            decreaseMagnitude = false;
        }
    }
    else {
        magnitude += 0.0005;
        if(magnitude >= 8.0){
            decreaseMagnitude = true;
        }
    }
    if (decreaseColor){
        color -= 0.005;
        if (color <= 0.0){
            decreaseColor = false;
        }
    }
    else {
        color += 0.005;
        if(color >= 0.5){
            decreaseColor = true;
        }
    }
    
    
    mesh.clear();
    mesh.setMode( OF_PRIMITIVE_LINES );

    for( int y = 0; y < gridResolution; y++ ){
        for( int x = 0; x < gridResolution; x++ ){

            ofVec3f pos;

            pos.x = ofMap( x,  0, gridResolution-1, extentXMin.x, extentXMax.x );
            pos.y = ofMap( y,  0, gridResolution-1, extentYMin.y, extentYMax.y );
            pos.y = pos.y - gridY/2;
            pos.z = 0;


            ofVec3f noisePos = pos * frequency;

            ofVec3f vel;
            vel.x = ofSignedNoise( noisePos.x, noisePos.y, noisePos.z, noiseTime );
            vel.y = ofSignedNoise( noiseTime,  noisePos.z, noisePos.y, noisePos.x );
            vel.z = ofSignedNoise( noisePos.z, noiseTime,  noisePos.y, noisePos.x );

            ofVec3f normVel = vel.getNormalized();
            ofVec3f velAsCol = (normVel + ofVec3f(1)) * 0.5;

            ofFloatColor tmpCol( 0, velAsCol.y - color, 1 , ofMap(cos(waveTime), -1, 1, 0, 1));

            mesh.addVertex( pos );
            mesh.addColor( tmpCol );

            mesh.addVertex( pos + (vel * magnitude));
            mesh.addColor( ofFloatColor(tmpCol, 0.0) );
        }
    }
    
    mesh2.clear();
    mesh2.setMode( OF_PRIMITIVE_TRIANGLES );


    for( int y = 0; y < gridResolution; y++ ){
          for( int x = 0; x < gridResolution; x++ ){
              
            ofVec3f pos;

            pos.x = ofMap( x,  0, gridResolution-1, extentXMin.x, extentXMax.x );
            pos.y = ofMap( y,  0, gridResolution-1, extentYMin.y, extentYMax.y );
            pos.y = pos.y - gridY/2; 
            pos.z = 0;


            ofVec3f noisePos = pos * frequency;

            ofVec3f vel;
            vel.x = ofSignedNoise( noisePos.x, noisePos.y, noisePos.z, noiseTime );
            vel.y = ofSignedNoise( noiseTime,  noisePos.z, noisePos.y, noisePos.x );
            vel.z = ofSignedNoise( noisePos.z, noiseTime,  noisePos.y, noisePos.x );

            ofVec3f normVel = vel.getNormalized();
            ofVec3f velAsCol = (normVel + ofVec3f(1)) * 0.5;

            ofFloatColor tmpCol( 0, velAsCol.y - color, 1 , ofMap(sin(waveTime), -1, 1, 0, 1));

            if(y != 0 && y < (gridResolution) && x != 0 && x < (gridResolution)){
                mesh2.addVertex( pos );
                mesh2.addColor( tmpCol );
                mesh2.addVertex( pos + (vel * magnitude));
                mesh2.addColor( ofFloatColor(tmpCol, 0.0) );
            }
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    ofEnableDepthTest();
    
        cam.begin();
    
            mesh.draw();
            mesh2.draw();
    
        cam.end();
    
    ofDisableDepthTest();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'F'){
        ofSetFullscreen(true);
        ofHideCursor();
    } else if (key == 'f'){
        ofSetFullscreen(false);
        ofShowCursor();
    }
    if(key == ' '){
        ofResetElapsedTimeCounter();
    }
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
