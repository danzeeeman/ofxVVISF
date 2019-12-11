#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	generator.setup(ofToDataPath("checkerboard.fs"), 1280, 720);
	group.setName("Checkerboard");
	group.add(width.set("Width", 0.5, 0, 1));
	group.add(offset.set("Offset", ofVec2f(0.5, 0.5), ofVec2f(0, 0), ofVec2f(1, 1)));
	group.add(splitPos.set("Split Pos", ofVec2f(0.5, 0.5), ofVec2f(0, 0), ofVec2f(1, 1)));
	group.add(colorOne.set("Color One", ofColor(0, 0, 0)));
	group.add(colorTwo.set("Color Two", ofColor(255, 255, 255)));
	gui.setup(group);
}

//--------------------------------------------------------------
void ofApp::update(){
	generator.update();
	generator.setInput("width", width.get());
	generator.setInput("offset", offset.get());
	generator.setInput("splitPos", splitPos.get());
	generator.setInput("color1", colorOne.get());
	generator.setInput("color2", colorTwo.get());
}

//--------------------------------------------------------------
void ofApp::draw(){
	generator.draw(0, 0);
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
