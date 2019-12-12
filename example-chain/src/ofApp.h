#pragma once

#include "ofMain.h"
#include "ofxISFScene.h"
#include "ofxGui.h"
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
		
		ofxISFScene autoColor;
		ofxISFScene boxinator;
		ofxISFScene boxinatorTwo;
		ofVideoGrabber grabber;
		ofParameterGroup autoColorGroup;
		ofParameterGroup boxGroup;
		ofParameter<int> colorMode;
		ofParameter<int> colorCount;
		ofParameter<float> rate;
		ofParameter<float> edge;
		ofParameter<float> blend;
		ofParameter<float> randomize;
		ofParameter<float> gamma;
		ofParameter<ofVec2f> grid;
		ofParameter<ofFloatColor> baseColor;
		ofxPanel gui;

};
