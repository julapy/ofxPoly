//
//  ofxLines.h
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofMain.h"

void ofxPolyGrow(const ofPolyline & polyIn, ofPolyline & polyOut, float amount);

void ofxPolyDrawNormals(const ofPolyline & poly, float normalLength);

void ofxPolySave(const ofPolyline & poly, string xmlPath);
void ofxPolyLoad(ofPolyline & poly, string xmlPath);