#include "ofApp.h"
using namespace VVGL;
using namespace VVISF;
//--------------------------------------------------------------
void ofApp::setup(){
	setup("Test-IMG_NORM_PIXEL.fs", 720, 720);
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

void ofApp::setup(string name, float width, float height){
	GLContextRef    ctxRef = CreateGLContextRefUsing((GLFWwindow*)((ofAppGLFWWindow*)ofGetWindowPtr())->getWindowContext());
	bp = CreateGlobalBufferPool(ctxRef->newContextSharingMe());
	renderScene = CreateISFSceneRefUsing(ctxRef->newContextSharingMe());
	renderScene->useFile(ofToDataPath(name));
	mDoc = renderScene->doc();
	mGLBuff = CreateRGBATex(Size(width, height), true, GetGlobalBufferPool());
	mTex.setUseExternalTextureID(mGLBuff->name);
	mTex.texData.textureTarget = mGLBuff->desc.target;
	mTex.texData.width = mGLBuff->size.width;
	mTex.texData.height = mGLBuff->size.height;
	mTex.texData.tex_w = mGLBuff->size.width;
	mTex.texData.tex_h = mGLBuff->size.height;
	mTex.texData.tex_t = 1.0;
	mTex.texData.tex_u = 1.0;
	mTex.texData.glInternalFormat = mGLBuff->desc.internalFormat;
	mTex.texData.bFlipTexture = mGLBuff->flipped;
	mTex.texData.bAllocated = TRUE;

}

void ofApp::setInput(string name, bool val) {
	ISFAttrRef intVal = mDoc->input(name);
	if (intVal == nullptr || intVal->type() != ISFValType_Bool) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFBoolVal(val);
	intVal->setCurrentVal(value);
}

void  ofApp::setInput(string name, long val) {
	ISFAttrRef intVal = mDoc->input(name);
	if (intVal == nullptr || intVal->type() != ISFValType_Long) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFLongVal(val);
	intVal->setCurrentVal(value);
}
void  ofApp::setInput(string name, float val) {
	ISFAttrRef floatAttr = mDoc->input(name);
	if (floatAttr == nullptr || floatAttr->type() != ISFValType_Float) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFFloatVal(val);
	floatAttr->setCurrentVal(value);
}
void ofApp::setInput(string name, ofVec2f val) {
	ISFAttrRef point2DAttr = mDoc->input(name);
	if (point2DAttr == nullptr || point2DAttr->type() != ISFValType_Point2D){
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFPoint2DVal(val.x, val.y);
	point2DAttr->setCurrentVal(value);
}
void ofApp::setInput(string name, ofFloatColor val) {
	ISFAttrRef colorAttr = mDoc->input(name);
	if (colorAttr == nullptr || colorAttr->type() != ISFValType_Color){
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFColorVal(val.r, val.g, val.b, val.a);
	colorAttr->setCurrentVal(value);
}
void ofApp::setInput(string name, ofTexture val) {
	ISFAttrRef imageAttr = mDoc->input(name);
	if (imageAttr == nullptr || imageAttr->type() != ISFValType_Image) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	//todo copy ofTexture to GLBufferRef
	GLBufferRef ref = CreateFromExistingGLTexture(
		val.texData.textureID,
		(GLBuffer::Target) val.texData.textureTarget,
		(GLBuffer::InternalFormat) val.texData.glInternalFormat,
		(GLBuffer::PixelFormat) val.texData.glInternalFormat,
		GLBuffer::PT_UByte,
		Size(val.texData.width, val.texData.height),
		val.texData.bFlipTexture,
		Rect(0, 0, val.texData.width, val.texData.height),
		NULL,
		NULL);

	ISFVal value = ISFImageVal(ref);
	imageAttr->setCurrentVal(value);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		mTest.begin();
		grabber.draw(0, 0);
		mTest.end();
	}
	setInput("inputImage", mTest.getTexture());

}
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	mTest.draw(720, 0, 720, 720);
	ofSetColor(255, 255, 255);
	draw(0, 0, ofGetWidth(), ofGetHeight());
}
//--------------------------------------------------------------
void ofApp::draw(float x, float y, float width, float height){

	renderScene->renderToBuffer(mGLBuff, mGLBuff->size);
	mTex.draw(x, y, width, height);
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
