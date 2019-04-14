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

		ofColor color = ofColor(100, 0, 0);
		colors.push_back(make_shared<ofColor>(color));
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
				auto color = colors[i];

				color->r = x * 80 + 90;
				color->g = 20 + y * 5;
				color->b = z * 10 + 30;

				point->x += x * 2;
				point->y += y * 2;
				point->z = 10.0 + (z * 5);

				point->x = ofClamp(point->x, 0, width*2);
				point->y = ofClamp(point->y, 0, height*2);
				point->z = ofClamp(point->z, 5, 20);
			}
			else if (m.getAddress() == "/encoderM"){
				if (prev == NULL || prev != m.getArgAsInt(0)) {
					ofLog() << "Screenshot" << endl;
					prev = m.getArgAsInt(0);

					//grab image
					glReadBuffer(GL_FRONT);
					img.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
					img.save("screenshot.png");
				}
			} //green
			else if (m.getAddress() == "/1/faderA"){
				auto value = m.getArgAsFloat(0);
				value = ofMap(value, 0, 1, 0, 255);
				colors[i]->g = value;
			} // red
			else if (m.getAddress() == "/1/faderB") {
				auto value = m.getArgAsFloat(0);
				value = ofMap(value, 0, 1, 0, 255);
				colors[i]->r = value;
			} //blue
			else if (m.getAddress() == "/1/faderC") {
				auto value = m.getArgAsFloat(0);
				value = ofMap(value, 0, 1, 0, 255);
				colors[i]->b = value;
			} //alpha
			else if (m.getAddress() == "/1/faderD") {
				auto value = m.getArgAsFloat(0);
				value = ofMap(value, 0, 1, 0, 255);
				colors[i]->a = value;
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	int index = 0;
	for (auto& point : points) {
		auto x = point->x;
		auto y = point->y;
		auto z = point->z;

		ofPushStyle();
			ofSetColor(*colors[index]);
			ofDrawCircle(x, y, z);
		ofPopStyle();
		index += 1;
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
