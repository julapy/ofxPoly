//
//  ofxLines.cpp
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofxPoly.h"

//--------------------------------------------------------------
void ofxPolyGrow(const ofPolyline & polyIn, ofPolyline & polyOut, float amount) {
    
    polyOut.clear();
    polyOut.setClosed(polyIn.isClosed());
    
    if(polyIn.size() < 2) {
        polyOut = polyIn;
        return;
    }
    
    const vector<ofVec3f> & points = polyIn.getVertices();
    int numOfPoints = points.size();

    bool bClosed = true;
    bClosed = bClosed && (polyIn.isClosed() == true);
    bClosed = bClosed && (numOfPoints >= 3);
    
    for(int i=0; i<numOfPoints; i++) {
        
        bool bEndings = false;
        bEndings = bEndings || (i == 0);
        bEndings = bEndings || (i == numOfPoints-1);
        bEndings = bEndings && (bClosed == false);
        
        if(bEndings == true) {

            const ofVec3f & p0 = points[i];
            ofVec3f n0 = polyIn.getNormalAtIndex(i);
            ofVec3f point = p0 + (n0 * amount);
            polyOut.addVertex(point);

            continue;
        }
        
        int i0 = i-1;
        if(i0 < 0) {
            i0 += numOfPoints;
        }
        
        const ofVec3f & p0 = points[i0];
        const ofVec3f & p1 = points[i];
        ofVec3f n0 = ofVec2f(p0 - p1).getPerpendicular();
        ofVec3f n1 = polyIn.getNormalAtIndex(i);
        
        float angle = ofVec2f(n0).angle(ofVec2f(n1));
        float length = amount / cos(angle * DEG_TO_RAD);
        
        ofVec3f point = p1 + (n1 * length);
        polyOut.addVertex(point);
    }
}

//--------------------------------------------------------------
void ofxPolyDrawNormals(const ofPolyline & poly, float normalLength) {

    const vector<ofVec3f> & points = poly.getVertices();
    
    for(int i=0; i<points.size(); i++) {
        const ofVec3f & point = points[i];
        ofVec3f normal = poly.getNormalAtIndex(i);

        ofDrawLine(point, point + (normal * normalLength));
    }
}

//--------------------------------------------------------------
void ofxPolySave(const ofPolyline & poly, string xmlPath) {
    ofXml xml;
    xml.addChild("poly");
    xml.setAttribute("closed", ofToString(poly.isClosed()));
    for(int i=0; i<poly.size(); i++) {
        const ofPoint & point = poly.getVertices()[i];
        
        xml.addChild("point");
        xml.setToChild(i);
        xml.setAttribute("x", ofToString(point.x));
        xml.setAttribute("y", ofToString(point.y));
        xml.setToParent();
    }
    
    xml.save(xmlPath);
}

//--------------------------------------------------------------
void ofxPolyLoad(ofPolyline & poly, string xmlPath) {
    ofXml xml;
    bool bLoaded = xml.load(xmlPath);
    if(bLoaded == false) {
        return;
    }
    
    xml.setTo("poly");
    bool bClosed = ofToInt(xml.getAttribute("closed"));
    
    poly.clear();
    
    int numOfPoints = xml.getNumChildren();
    for(int i=0; i<numOfPoints; i++) {
        xml.setToChild(i);
        float x = ofToFloat(xml.getAttribute("x"));
        float y = ofToFloat(xml.getAttribute("y"));
        
        poly.addVertex(x, y);
    }
    
    poly.setClosed(bClosed);
}

