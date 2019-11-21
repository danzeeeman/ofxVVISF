#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	scene.setup("Test-MultiPassRendering.fs", 720, 720);
	ofDisableArbTex();
	ofFbo::Settings settings;
	settings.width = 720;
	settings.height = 720;
	settings.internalformat = GL_RGBA;
	mTest.allocate(settings);

	mTest.begin();
	ofClear(0);
	ofSetColor(255, 0, 255);
	ofDrawRectangle(0, 0, 720, 720);
	mTest.end();

	grabber.setup(1280, 720);

}


//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		mTest.begin();
		grabber.draw(0, 0);
		mTest.end();
	}
	scene.setInput("inputImage", mTest.getTexture());

}
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	mTest.draw(720, 0, 720, 720);
	ofSetColor(255, 255, 255);
	scene.draw(0, 0, ofGetWidth(), ofGetHeight());
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
