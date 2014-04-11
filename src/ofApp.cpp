#include "ofApp.h"

//
//  ofxSpirograph
//  A simple spirograph implementation
//

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
    
	gui.setup("ofxSpirograph");
	gui.add(spiroColor.setup("color",ofColor(255, 0, 0, 80),ofColor(0,0),ofColor(255,255)));
    gui.add(spiroLineWeight.setup("line weight", 2, 1, 5));
    gui.add(ratioNum.setup("ratio (n)", 25, 1, 200));
    gui.add(ratioDen.setup("ratio (d)", 81, 1, 200));
    gui.add(spiroRenderStep.setup("render step", 80, 1, 100));
    gui.add(spiroFill.setup("fill", false));
    
	bHide = true;
    bFullscreen	= 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::grey);
    
    float ratio_num = ratioNum;
    float ratio_den = ratioDen;
    float ratio = ratio_num/ratio_den;
    float R = 20;
    float r = R/ratio;
    float angle = ratio_den*TWO_PI;
    float renderStep = PI/spiroRenderStep;
    
    if (ratio < 1) {
        R = 325*ratio/(1-ratio/2);
        r = R/ratio;
    }
    
    ofPushMatrix();
    if (!bFullscreen) {
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    } else if (bFullscreen == 1) {
        ofTranslate(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    }
    
    ofSetColor(spiroColor);
    if (spiroFill) {
		ofFill();
	} else {
		ofNoFill();
	}
    ofSetLineWidth(spiroLineWeight);
    
    ofBeginShape();
    for (float i=0; i<angle; i+= renderStep) {
        float x = abs(R-r)/2*cos(i) + r/2*cos(-i*ratio);
        float y = abs(R-r)/2*sin(i) + r/2*sin(-i*ratio);
        ofVertex(x, y);
    }
    ofEndShape();
    
    ofPopMatrix();
    
	if ( bHide ) {
        gui.draw();
        ofSetColor(255);
        ofDrawBitmapString("(f) fullscreen\n(h) hide controls\n(b) draw black", 20, ofGetHeight() - 50);
        ofDrawBitmapString("(s) save settings\n(l) load settings", 20 + 200, ofGetHeight() - 50);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'h' ) {
        bHide = !bHide;
    }
    
	if ( key == 's' ) {
        gui.saveToFile("settings.xml");
    }
    
	if ( key == 'l' ) {
        gui.loadFromFile("settings.xml");
    }
    
	if ( key == 'b' ) {
        spiroColor = ofColor(0, 200);
    }
    
    if ( key == 'f' ) {
		bFullscreen = !bFullscreen;
		
		if (!bFullscreen) {
			ofSetFullscreen(false);
			int screenW = ofGetScreenWidth();
			int screenH = ofGetScreenHeight();
			ofSetWindowPosition(screenW/2-1024/2, screenH/2-768/2);
		} else if (bFullscreen == 1) {
			ofSetFullscreen(true);
		}
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
