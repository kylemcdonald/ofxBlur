#include "ofApp.h"

int main() {
    ofGLWindowSettings settings;
    settings.setSize(640, 480);
    settings.setGLVersion(3,2); // GL3
//    settings.setGLVersion(2,1); // GL2
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
