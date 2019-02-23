//
//  Animal.cpp
//  assignment2
//
//  Created by wenhe on 2019/2/23.
//

#include "Animal.hpp"
#include <ofMain.h>

Animal::Animal() = default;

void Animal::setup(ofVec2f _pos, vector<ofImage> _imgs) {
    pos = _pos;
    imgs = _imgs;
    ofLog() << _imgs.size();
    vel = ofVec2f(10, 0);
    current_frame = 0;
}

void Animal::update() {
    pos += vel;
    counter += 1;
    if (counter >= 5) {
        current_frame += 1;
        counter = 0;
    }
    current_frame %= imgs.size();

    if(pos.x >= ofGetWidth() - imgs[current_frame].getWidth() && !is_on_side) {
        is_on_side = true;
    }
    
    if (pos.x >= ofGetWidth()) {
        is_on_side = false;
        pos.x = 0;
    }
    
    
}

void Animal::draw() {
    imgs[current_frame].draw(pos, 400, 250);
    if (is_on_side) {
        float temp_pos = pos.x - ofGetWidth();
        imgs[current_frame].draw(temp_pos, pos.y, 400, 250);
    }
}


