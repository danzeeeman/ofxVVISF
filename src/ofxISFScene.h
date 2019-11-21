#pragma once
#include "ofMain.h"
#include "VVISF.hpp"

class ofxISFScene{
    public:
        void setup(string name, float width, float height);
        void setInput(string name, bool val);
        void setInput(string name, long val);
        void setInput(string name, float val);
        void setInput(string name, ofVec2f val);
        void setInput(string name, ofFloatColor val);
        void setInput(string name, ofTexture val);
            
        void draw(float x, float y, float width, float height);

        VVISF::ISFDocRef mDoc;
		VVISF::ISFSceneRef	renderScene;
		VVGL::GLBufferPoolRef	bp;
		VVGL::GLBufferRef mGLBuff;
		ofTexture mTex;

};