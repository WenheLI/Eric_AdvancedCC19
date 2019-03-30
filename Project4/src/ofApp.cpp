#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i < 3; i++) {
        auto b = Ball();
        b.init();
        balls.push_back(b);
    }

    
    
    cam.setupPerspective();
    cam.enableOrtho();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (i != j) {
                ofLog() << i << endl;
                balls[i].update(balls[j]);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.enableMouseInput();
    cam.setupPerspective();
    cam.begin();
    light.enable();
    
    for (int i = 0; i < 3; i++) balls[i].draw();
    
    light.disable();
    cam.end();
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
