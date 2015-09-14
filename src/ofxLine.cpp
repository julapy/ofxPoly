//
//  ofxLine.cpp
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofxLine.h"

ofxLine::ofxLine() {
    //
}

ofxLine::~ofxLine() {
    //
}

//--------------------------------------------------------------
void ofxLine::setup(const ofPolyline & polyNew) {
    poly = polyNew;
}

void ofxLine::setup(const vector<ofVec3f> & points) {
    poly.clear();
    poly.addVertices(points);
}

void ofxLine::setup(const vector<ofVec3f *> & points) {
    poly.clear();
    for(int i=0; i<points.size(); i++) {
        const ofVec3f & point = *points[i];
        poly.addVertex(point);
    }
}

//--------------------------------------------------------------
void ofxLine::update() {
    //
}

//--------------------------------------------------------------
void ofxLine::draw() {
    //
}
