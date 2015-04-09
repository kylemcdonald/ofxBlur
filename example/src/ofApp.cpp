#include "ofApp.h"

void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	cam.initGrabber(640, 480);
	
    // there are a 6 ways to control what's going on with ofxBlur
    // 4 parameters are in the setup() function:
    // - radius corresponds to how many points you want to use when blurring
    //   this usually corresponds to how big you want your blur to be
    //   so a 10 pixel radius means you want 10 samples to have perfect blur
    //   if you set this too high, the blur will start to get slow
    // - shape corresponds to the variance of the gaussian function used for
    //   the blur kernel. a larger variance means you will have more like a
    //   box blur, a smaller variance means it will be more "gaussian" blur
    //   this has no effect on the speed of the blur
    // - passes corresponds to how many downsampling blur passes are used
    //   setting this number higher will give more of a "fog" or "bloom" look
    //   if you set this too high, the blur will start to get slow
    // - downsample (not shown here, defaults to .5) corresponds to the scale
    //   factor when downsampling when passes is greater than 1
    //   this has no effect on the speed of the blur
    blur.setup(cam.getWidth(), cam.getHeight(), 10, .2, 4);
}

void ofApp::update() {	
	cam.update();
    // 2 parameters can be controlled in real time after setup():
    // - scale corresponds to how much you "stretch" the blur kernel
    //   anything greater than 1 will start to look inaccurate, but it can be
    //   a fast way of getting a bigger blur. anything smaller than 1 will
    //   create an smaller blur, and eventually the blur will disappear
    //   this has no effect on the speed of the blur
    // - rotation corresponds to the two directions the blur is calculated in
    //   this only has a visible effect if the scale is greater than 1
    blur.setScale(ofMap(mouseX, 0, ofGetWidth(), 0, 10));
    blur.setRotation(ofMap(mouseY, 0, ofGetHeight(), -PI, PI));
    
}

void ofApp::draw() {
	ofBackground(0);
	
	blur.begin();
	ofSetColor(255);
	cam.draw(0, 0);
	ofSetCircleResolution(64);
	ofCircle(mouseX, mouseY, 32);
	blur.end();
	
	blur.draw();
	
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
}
