#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i < 5; i++) {
        auto b = make_shared<Ball>();
        b->init();
        balls.push_back(b);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			if (i != j) balls[i]->update(balls[j]);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(122, 123, 124);

    for (int i = 0; i < 5; i++) balls[i]->draw();

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
