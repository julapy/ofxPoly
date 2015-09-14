//
//  ofxLine.h
//  example
//
//  Created by Lukasz Karluk on 14/09/2015.
//
//

#include "ofMain.h"

class ofxLine {
    
public:
    
    ofxLine();
    ~ofxLine();
    
    void setup(const ofPolyline & poly);
    void setup(const vector<ofVec3f> & points);
    void setup(const vector<ofVec3f *> & points);
    
    void update();

    void draw();
    
    ofPolyline poly;
};