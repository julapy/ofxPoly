#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofColor::black);
    
    bPolyClosed = false;
    polyThickness = 20;
}

//--------------------------------------------------------------
void ofApp::update(){

    poly.setClosed(bPolyClosed);
    
    ofxPolyGrow(poly, polyOuter, polyThickness);
    ofxPolyGrow(poly, polyInner, -polyThickness);
}

//--------------------------------------------------------------
void ofApp::draw(){

    poly.draw();
    
    const vector<ofVec3f> & points = poly.getVertices();
    for(int i=0; i<points.size(); i++) {
        const ofVec3f & point = points[i];
        ofDrawCircle(point.x, point.y, 4);
    }
    
    ofxPolyDrawNormals(poly, polyThickness);
    
    ofSetColor(ofColor::magenta);
    polyOuter.draw();
    
    ofSetColor(ofColor::cyan);
    polyInner.draw();
    
    ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c' || key == 'C') {
        bPolyClosed ^= true;
    }
    if(key == 'r' || key == 'R') {
        poly.clear();
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
    poly.addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
