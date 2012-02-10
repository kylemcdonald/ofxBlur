/*
	only call setup() once. you must specify the width and height. radius
	describes the radius of the blur kernel. the larger the radius, the slower the
	blur. if you want a larger apparent radius at the same speed, use setScale(x)
	where x>1. shape describes the circularity/squareness of the kernel. for a
	more circular kernel, use smaller values like .2 and for a more square kernel
	use larger values like 10. for more square kernels, rotating the kernel has
	an obvious visual effect. use setRotation() to set the rotation of the kernel
	in radians. finally, using the passes and downsample arguments you can run
	the blur filter multiple times at different scales and ofxBlur will combine
	the results for you. this can be used to create a more bloom-like or fog-like
	effect.
*/

#pragma once

#include "ofMain.h"

class ofxBlur {
protected:
	ofFbo base;
	vector<ofFbo*> ping, pong;
	
	ofShader blurShader, combineShader;
	float scale, rotation;
	float downsample;
	float brightness;
public:
	ofxBlur();
	
	void setup(int width, int height, int radius = 32, float shape = .2, int passes = 1, float downsample = .5);
	
	void setScale(float scale);
	void setRotation(float rotation);
	void setBrightness(float brightness); // only applies to multipass
	
	void begin();
	void end();
	void draw();
	
	ofTexture& getTextureReference();
};

// <3 kyle