#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// listening port
#define PORT 8000
#define PORT2 9000

class ofApp : public ofBaseApp{
	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int width = ofGetWindowWidth() / 2;
		int height = ofGetWindowHeight() / 2;

		const int PORTS[6] = {8000, 8001, 8002, 8003, 8004, 8005};
		vector<shared_ptr<ofxOscReceiver>> receivers;
		vector<shared_ptr<ofPoint>> points;
		vector<shared_ptr<ofColor>> colors;

		int prev = NULL;
		ofImage img;

};
