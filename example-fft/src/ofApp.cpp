#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofDisableArbTex();
	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);

	bufferSize = 512;

	ofSoundStreamSettings settings;

	// if you want to set the device id to be different than the default
	//auto devices = soundStream.getDeviceList();
	
	// settings.device = devices[4];

	// you can also get devices for an specific api
	// auto devices = soundStream.getDevicesByApi(ofSoundDevice::Api::PULSE);
	// settings.device = devices[0];

	// or get the default device for an specific api:
	// this is a work around for windows
	settings.setApi(ofSoundDevice::Api::MS_DS);

	settings.setInListener(this);
	settings.sampleRate = 44100;
	settings.numOutputChannels = 0;
	settings.numInputChannels = 2;
	settings.bufferSize = bufferSize;
	soundStream.setup(settings);

	fft = ofxFft::create(bufferSize, OF_FFT_WINDOW_HAMMING);

	rawAudioLeft.setup(vector<float>(bufferSize));
	rawAudioRight.setup(vector<float>(bufferSize));
	rawFft.setup(vector<float>(fft->getBinSize()));

	ofLog() << fft->getBinSize() << endl;

	mAudio.allocate(bufferSize, 2, GL_RGBA);
	mFft.allocate(fft->getBinSize(), 1, GL_RGBA);



	//
	// This example is really 3 examples.  It shows how to use audio 
	// as a source.  
	//

	scene.setup(ofToDataPath("Test-Audio.fs"), 1920, 1080);
	//
	//  Comment out line 51 uncomment the line 54 and line 95 to see how the FFT works
	// scene.setup(ofToDataPath("Test-AudioFFT.fs"), 1920, 1080);
	//
	//  Comment out line 51 and line 54 and unomment line 57 and line 95 to use the Spectrogram ISF
	// scene.setup(ofToDataPath("Spectrogram.fs"), 1920, 1080);
	//
}

//--------------------------------------------------------------
void ofApp::update() {
	if (rawAudioLeft.swapFront() && rawAudioRight.swapFront()) {
		//
		// This generates a stereo waveImage texture for the ISFScene
		//
		vector<float> sum;
		vector<float>& dataLeft = rawAudioLeft.getFront();
		vector<float>& dataRight = rawAudioRight.getFront();
		sum.insert(sum.end(), dataLeft.begin(), dataLeft.end());
		sum.insert(sum.end(), dataRight.begin(), dataRight.end());
		vector<float> colorImage;
		colorImage.assign(sum.size() * 4, 0);
		int k = 0;
		for (int i = 0; i < sum.size(); i++) {
			// center around 0.5
			colorImage[k++] = (4.0 * sum[i] + 4.0) / 8.0 ;
			colorImage[k++] = (4.0 * sum[i] + 4.0) / 8.0 ;
			colorImage[k++] = (4.0 * sum[i] + 4.0) / 8.0 ;
			colorImage[k++] = (4.0 * sum[i] + 4.0) / 8.0 ;
	
		}
		mAudio.loadData(&colorImage[0], sum.size() / 2.0, 2, GL_RGBA);
	
	}
	if (rawFft.swapFront()) {
		//
		// This generates the fftImage texture for the ISFScene
		//
		vector<float>& data = rawFft.getFront();
		vector<float> colorImage;
		colorImage.assign(data.size() * 4, 0);
		int k = 0;
		for (int i = 0; i < data.size(); i++) {
			//scale
			colorImage[k++] = (data[i])*255;
			colorImage[k++] = (data[i])*255;
			colorImage[k++] = (data[i])*255;
			colorImage[k++] = (data[i])*255;
		}

		mFft.loadData(&colorImage[0], data.size(), 1, GL_RGBA);
	}

	//scene.setInput("fftImage", mFft);
	scene.setInput("waveImage", mAudio);
	scene.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	mAudio.draw(0, 0, 1920, 10);
	mFft.draw(0, 10, 1920, 20);
	scene.draw(0, 30);

}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & input) {

	vector<float>& rawAudioBackLeft = rawAudioLeft.getBack();
	vector<float>& rawAudioBackRight = rawAudioRight.getBack();
	rawAudioBackLeft.assign(input.getNumFrames(), 0);
	rawAudioBackRight.assign(input.getNumFrames(), 0);
	
	for (int j = 0; j < input.getNumFrames(); j++) {
		rawAudioBackLeft[j] = input[j * input.getNumChannels()];
		rawAudioBackRight[j] = input[j * input.getNumChannels() + 1];
	}
	
	fft->setSignal(&rawAudioBackLeft[0]);
	float* curFft = fft->getAmplitude();
	rawFft.getBack().assign(curFft, curFft + fft->getBinSize());

	rawAudioLeft.swapBack();
	rawAudioRight.swapBack();
	rawFft.swapBack();

}

void ofApp::plot(vector<float>& buffer, float scale, float offset) {
	ofNoFill();
	int n = buffer.size();
	ofDrawRectangle(0, 0, n, 100);
	glPushMatrix();
	glTranslatef(0, 100 / 2 + offset, 0);
	ofBeginShape();
	for (int i = 0; i < n; i++) {
		ofVertex(i, sqrt(buffer[i]) * scale);
	}
	ofEndShape();
	glPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's') {
		soundStream.start();
	}

	if (key == 'e') {
		soundStream.stop();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

