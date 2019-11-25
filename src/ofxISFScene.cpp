#include "ofxISFScene.h"
using namespace VVGL;
using namespace VVISF;
void ofxISFScene::setup(string path, float width, float height){
	GLContextRef    ctxRef = CreateGLContextRefUsing((GLFWwindow*)((ofAppGLFWWindow*)ofGetWindowPtr())->getWindowContext());
	bp = CreateGlobalBufferPool(ctxRef->newContextSharingMe());
	renderScene = CreateISFSceneRefUsing(ctxRef->newContextSharingMe());
	renderScene->useFile(ofToDataPath(path));
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

void ofxISFScene::setInput(string name, bool val) {
	ISFAttrRef intVal = mDoc->input(name);
	if (intVal == nullptr || intVal->type() != ISFValType_Bool) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFBoolVal(val);
	intVal->setCurrentVal(value);
}

ofTexture ofxISFScene::getTextureRef() {
	return mTex;
}

void  ofxISFScene::setInput(string name, long val) {
	ISFAttrRef intVal = mDoc->input(name);
	if (intVal == nullptr || intVal->type() != ISFValType_Long) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFLongVal(val);
	intVal->setCurrentVal(value);
}
void  ofxISFScene::setInput(string name, float val) {
	ISFAttrRef floatAttr = mDoc->input(name);
	if (floatAttr == nullptr || floatAttr->type() != ISFValType_Float) {
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFFloatVal(val);
	floatAttr->setCurrentVal(value);
}
void ofxISFScene::setInput(string name, ofVec2f val) {
	ISFAttrRef point2DAttr = mDoc->input(name);
	if (point2DAttr == nullptr || point2DAttr->type() != ISFValType_Point2D){
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFPoint2DVal(val.x, val.y);
	point2DAttr->setCurrentVal(value);
}
void ofxISFScene::setInput(string name, ofFloatColor val) {
	ISFAttrRef colorAttr = mDoc->input(name);
	if (colorAttr == nullptr || colorAttr->type() != ISFValType_Color){
		ofLogError() << "INPUT NOT FOUND OR MISMATCHED TYPE" << endl;
		return;
	}
	ISFVal value = ISFColorVal(val.r, val.g, val.b, val.a);
	colorAttr->setCurrentVal(value);
}
void ofxISFScene::setInput(string name, ofTexture val) {
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
void ofxISFScene::draw(float x, float y, float width, float height){

	renderScene->renderToBuffer(mGLBuff, mGLBuff->size);
	mTex.draw(x, y, width, height);
}