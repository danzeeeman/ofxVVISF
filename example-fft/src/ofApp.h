#pragma once

#include "ofMain.h"
#include "ofxFft.h"
#include "Synchronized.h"
#include "ofxISFScene.h"
class ofApp : public ofBaseApp {

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
	void plot(vector<float>& buffer, float scale, float offset);
	void audioIn(ofSoundBuffer & input);

	Synchronized< vector<float> > rawAudioLeft;
	Synchronized< vector<float> > rawAudioRight;
	Synchronized< vector<float> > rawFft;

	int bufferSize;
	ofxISFScene scene;
	ofTexture mAudio;
	ofTexture mFft;
	ofSoundStream soundStream;
	ofxFft* fft;
};
