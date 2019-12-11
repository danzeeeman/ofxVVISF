#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex();
	ofSetWindowShape(1280, 720);
	grabber.setup(1280, 720);
	scene.setup(ofToDataPath("auto color tune.fs"), 1280, 720);
	scene.setInput("inputImage", grabber.getTexture());
	group.setName("Auto Color Inputs");
	group.add(colorMode.set("Color Mode", 0, 0, 6));
	group.add(colorCount.set("Color Count", 3, 1, 16));
	group.add(baseColor.set("Base Color", ofFloatColor(0.5, 0, 0.5, 1.0)));
	gui.setup(group);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	scene.setInput("colorModeOverride",(long) colorMode.get());
	scene.setInput("colorCount", (long)colorCount.get());
	scene.setInput("baseColor", baseColor.get());
	scene.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	scene.draw(0, 0);
	gui.draw();
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
