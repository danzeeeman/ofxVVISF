#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex();
	ofSetWindowShape(640, 480);
	grabber.setup(640, 480);
	autoColor.setup(ofToDataPath("auto color tune.fs"), 640, 480);
	boxinator.setup(ofToDataPath("boxinator.fs"), 640, 480);
	autoColor.setInput("inputImage", grabber.getTexture());
	boxinator.setInput("inputImage", autoColor.getTextureRef());
	autoColorGroup.setName("Auto Color Inputs");
	autoColorGroup.add(colorMode.set("Color Mode", 0, 0, 6));
	autoColorGroup.add(colorCount.set("Color Count", 3, 1, 16));
	autoColorGroup.add(baseColor.set("Base Color", ofFloatColor(0.5, 0, 0.5, 1.0)));
	gui.setup(autoColorGroup);
	boxGroup.setName("Boxinator Inputs");
	boxGroup.add(rate.set("Rate", 0.1, 0, 10));
	boxGroup.add(edge.set("Edge", 0.001, 0.0, 0.01));
	boxGroup.add(blend.set("Blend", 0.5, 0.0, 1.0));
	boxGroup.add(randomize.set("Randomize", 0.5, 0.0, 1.0));
	boxGroup.add(gamma.set("Gamma", -0.3, -0.5, 0.3));
	boxGroup.add(grid.set("Grid Size", ofVec2f(64.5, 64.5), ofVec2f(1.5, 1.5), ofVec2f(900, 600)));

	gui.add(boxGroup);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	autoColor.setInput("colorModeOverride",(long) colorMode.get());
	autoColor.setInput("colorCount", (long)colorCount.get());
	autoColor.setInput("baseColor", baseColor.get());

	boxinator.setInput("rate", rate.get());
	boxinator.setInput("edge", edge.get());
	boxinator.setInput("blend", blend.get());
	boxinator.setInput("randomize", randomize.get());
	boxinator.setInput("gamma", gamma.get());
	boxinator.setInput("grid", grid.get());
	autoColor.update();
	boxinator.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	boxinator.draw(0, 0);
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
