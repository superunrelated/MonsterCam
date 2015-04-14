#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new ofxUICanvas();
    
    gui->addSlider("BACKGROUND",0.0,255.0,100.0);
    gui->addToggle("FULLSCREEN", false);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");

    switch (ofGetTargetPlatform()){
        case OF_TARGET_OSX:
            cout << "OF_TARGET_OSX";
            volumePath = "/Volumes";
            break;
        case OF_TARGET_LINUX:
            cout << "OF_TARGET_LINUX";
            volumePath = "/media";
            break;
        case OF_TARGET_LINUXARMV6L:
            cout << "OF_TARGET_LINUXARMV6L";
            volumePath = "/media";
            break;
        case OF_TARGET_LINUXARMV7L:
            cout << "OF_TARGET_LINUXARMV7L";
            volumePath = "/media";
            break;
        default:
            break;
    }
}

void ofApp::exit(){
    gui->saveSettings("settings.xml");
    delete gui;
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    if(e.getName() == "BACKGROUND"){
        ofxUISlider *slider = e.getSlider();
        ofBackground(slider->getScaledValue());
    }
    else if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = e.getToggle();
        ofSetFullscreen(toggle->getValue());
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(200, 300, 60);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //some path, may be absolute or relative to bin/data
    ofDirectory dir(volumePath);
    //only show png files
    //    dir.allowExt("png");
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.numFiles(); i++){
        ofLogNotice(dir.getPath(i));
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
