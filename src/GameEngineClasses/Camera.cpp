//
//  Camera.cpp
//  src
//
//  Created by David María Arribas on 19/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() : BasePrimitive(Vertex3D(0.0f, 0.0f, -40.0f), Vertex3D(), Color()) {}

Camera::Camera(Vertex3D position, Vertex3D velocity, Color color)
    : BasePrimitive(position, velocity, color) {}

Camera::Camera(const Camera &camera) : BasePrimitive(camera.position, camera.velocity, camera.color, camera.force, camera.mass) {}

Camera *Camera::clone() {
    return new Camera(*this);
}

void Camera::render() {
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glRotatef(this->rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation.z, 0.0f, 0.0f, 1.0f);
}

void Camera::update(float dt) {
    this->position = this->position + this->velocity * dt;
    this->rotation = this->rotation + this->rotation_velocity * dt;
}

BoundingBox Camera::calculateBoundingBox() {
    Vertex3D v;
    BoundingBox b(v, v);
    return b;
}
