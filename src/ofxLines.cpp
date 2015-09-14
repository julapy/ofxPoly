//
//  ofxLines.cpp
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofxLines.h"

void ofxLinesGrow(const ofPolyline & polyIn, ofPolyline & polyOut, float amount) {
    
    polyOut.clear();
    polyOut.setClosed(polyIn.isClosed());
    
    const vector<ofVec3f> & points = polyIn.getVertices();
    
    for(int i=0; i<points.size(); i++) {
        ofVec3f point = points[i];
        ofVec3f normal = polyIn.getNormalAtIndex(i);
        point += normal * amount;
        
        polyOut.addVertex(point);
    }
}


void ofxLinesDrawNormals(const ofPolyline & poly, float normalLength) {

    const vector<ofVec3f> & points = poly.getVertices();
    
    for(int i=0; i<points.size(); i++) {
        const ofVec3f & point = points[i];
        ofVec3f normal = poly.getNormalAtIndex(i);

        ofDrawLine(point, point + (normal * normalLength));
    }
}