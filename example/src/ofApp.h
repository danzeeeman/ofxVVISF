#pragma once

#include "ofMain.h"
#include "VVISF.hpp"




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

		//ISFValType_None,	//!<	No data/unknown value type.
		//ISFValType_Event,	//!<	No data, just an event.  sends a 1 the next render after the event is received, a 0 any other time it's rendered
		//ISFValType_Bool,	//!<	A boolean choice, sends 1 or 0 to the shader
		//ISFValType_Long,	//!<	Sends a long
		//ISFValType_Float,	//!<	Sends a float
		//ISFValType_Point2D,	//!<	Sends a 2 element vector
		//ISFValType_Color,	//!<	Sends a 4 element vector representing an RGBA color
		//ISFValType_Cube,	//!<	Sends a long- the texture number (like GL_TEXTURE0) of a cubemap texture to pass to the shader
		//ISFValType_Image,

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
		
		
		ofFbo mTest;
		ofVideoGrabber grabber;

};
