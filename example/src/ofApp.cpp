#include "ofApp.h"

void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	cam.initGrabber(640, 480);
	
	blur.setup(cam.getWidth(), cam.getHeight(), 4, .2, 4);
}

void ofApp::update() {	
	cam.update();
	blur.setScale(ofMap(mouseX, 0, ofGetWidth(), 1, 4));
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
