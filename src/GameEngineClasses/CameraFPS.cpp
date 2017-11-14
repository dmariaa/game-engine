//
//  CameraFPS.cpp
//  src
//
//  Created by David María Arribas on 7/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "CameraFPS.hpp"
#include <cmath>
	
void CameraFPS::update(float dt) {
    this->rotation = this->rotation + this->rotation_velocity * dt * 10.0f;
    float rotY = rot2rad(this->rotation.y);
    float rotX = rot2rad(this->rotation.x);
    this->position.x = this->position.x + (this->velocity.z * dt * -sin(rotY));
    this->position.y = this->position.y + this->velocity.z * dt * sin(rotX);
    this->position.z = this->position.z + (this->velocity.z * dt * cos(rotY) * cos(rotX));
}

void CameraFPS::render() {
    glRotatef(this->rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation.z, 0.0f, 0.0f, 1.0f);
    glTranslatef(this->position.x, this->position.y, this->position.z);
}
