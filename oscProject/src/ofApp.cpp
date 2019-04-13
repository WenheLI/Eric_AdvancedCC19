#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Drawing");
	ofSetFrameRate(60); // run at 60 fps
	ofSetVerticalSync(true);

	//automatic bind ports
	for (int port : PORTS) {
		ofxOscReceiver receiver = ofxOscReceiver();
		receiver.setup(port);
		receivers.push_back(make_shared<ofxOscReceiver>(receiver));
	}

	ofSetBackgroundAuto(false);




	for (int port : PORTS) {
		ofPoint point = ofPoint(width, height, 10);
		points.push_back(make_shared<ofPoint>(point));
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	//Clean up this disaster (ARRAYS & FORLOOPS) ¡Ì
	//Add screenshot button from receivers 
	//Add color customization from osc app
	//

	for (int i = 0; i < receivers.size(); i++) {
		while (receivers[i]->hasWaitingMessages()){
			// get the next message
			ofxOscMessage m;
			receivers[i]->getNextMessage(m);
			if (m.getAddress() == "/accxyz") {
				auto x = m.getArgAsFloat(0);
				auto y = m.getArgAsFloat(1);
				auto z = m.getArgAsFloat(2);
				
				auto point = points[i];
				point->x += x * 2;
				point->y += y * 2;
				point->z = 10.0 + (z * 5);

				point->x = ofClamp(point->x, 0, width);
				point->y = ofClamp(point->y, 0, height);
				point->z = ofClamp(point->z, 5, 20);
			}
			else if (m.getAddress() == "/encoderM"){
				if (prev == NULL || prev != m.getArgAsInt(0)) {
					ofLog() << "Screenshot" << endl;
					prev = m.getArgAsInt(0);
					glReadBuffer(GL_FRONT);
					img.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
					img.save("screenshot.png");
				}
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	for (auto& point : points) {
		auto x = point->x;
		auto y = point->y;
		auto z = point->z;

		ofPushStyle();
			ofSetColor(x * 80 + 90, 20 + y * 5, z * 10 + 30);
			ofDrawCircle(x, y, z);
		ofPopStyle();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
