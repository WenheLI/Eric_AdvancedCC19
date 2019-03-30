//
//  Ball.cpp
//  Project4
//
//  Created by wenhe on 2019/3/29.
//

#include "Ball.hpp"

void Ball::init() {
    this->pos = glm::vec3(ofRandom(0, 500), ofRandom(0, 500), 0);
    this->vel = glm::vec3(ofRandom(-.5, .5), ofRandom(-.5, .5), 0);
    this->acc = glm::vec3( ofRandom(-.1, .1), ofRandom(-.1, .1) , 0);
    this->r = ofRandom(50, 100);
    this->G = .9;
}

bool Ball::update(Ball other) {
    bool isColl = false;
    if (this->pos.x <= this->r) {
        this->pos.x = this->r+5;
        this->vel.x *= -1;
    } else if (this->pos.y <= this->r) {
        this->pos.y = this->r+5;
        this->vel.y *= -1;
    } else if (this->pos.x >= ofGetWidth() - this->r) {
        this->pos.x = ofGetWidth() - this->r - 5;
        this->vel.x *= -1;
    } else if (this->pos.y >= ofGetHeight() - this->r) {
        this->pos.y = ofGetHeight() - this->r - 5;
        this->vel.y *= -1;
    }
    
    auto dist = glm::distance(this->pos, other.pos);
    
    auto force = this->pos - other.pos;
    force /= dist;
    
    auto strength = (this->G * this->r * other.r) / glm::pow(dist, 2);
    
    
    force *= strength;
    
//    applyForce(force);
//    if (dist <= this->r + other.r + 5) {
//        ofLog() << "boom";
//        auto temp = this->vel - other.vel;
//        this->vel = -1 * temp;
//        other.vel =  temp;
//        this->acc *= -1;
//        other.acc *= -1;
//        isColl = true;
//    }
    
    this->vel += this->acc;
    auto tempVel = glm::abs(this->vel);
    for (int i = 0; i < 3; i++) {
        if (tempVel[i] > 5) this->vel[i] = 5;
    }

    this->pos += this->vel;
    
    return isColl;
}

void Ball::draw() {
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawSphere(this->pos, this->r);
}

void Ball::applyForce(glm::vec3 force){
    auto tempAcc = force / this->r;
    this->acc += tempAcc;
    ofLog() << this->acc;
}
