//
//  ofxLines.h
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofMain.h"

void ofxPolyGrow(ofPolyline & poly, const ofPolyline & polySource, float amount);
void ofxPolyGrowAlongNormals(ofPolyline & poly, const ofPolyline & polySource, float normalLength);
void ofxPolyGrowAlongNormals(ofPolyline & poly, const ofPolyline & polySource, const vector<float> & normalLengths);

void ofxPolyToMesh(ofMesh & mesh, const ofPolyline & polySource, float normalLength);
void ofxPolyToMesh(ofMesh & mesh, const ofPolyline & polySource, const vector<float> & normalLengths);
void ofxPolyToMesh(ofMesh & mesh, const ofPolyline & poly0, const ofPolyline & poly1);

void ofxPolyDrawNormals(const ofPolyline & poly, float normalLength);

void ofxPolySave(const ofPolyline & poly, string xmlPath);
void ofxPolyLoad(ofPolyline & poly, string xmlPath);