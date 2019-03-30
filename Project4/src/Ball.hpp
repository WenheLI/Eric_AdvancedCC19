//
//  Ball.hpp
//  Project4
//
//  Created by wenhe on 2019/3/29.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball {
    
public:
    
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 acc;
    
    glm::vec3 maxSpeed = glm::vec3(5, 5, 5);
    glm::vec3 minSpeed = glm::vec3(-5, -5, -5);
    
    float r;
    float G;
    
    
    void init();
    bool update(Ball other);
    void draw();
    
    void applyForce(glm::vec3 force);
    
};

#endif /* Ball_hpp */
