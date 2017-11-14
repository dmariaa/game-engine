//
//  Sphere.cpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include <math.h>
#include "Sphere.hpp"

Sphere::Sphere() : BasePrimitive() {};

Sphere::Sphere(float radius, Vertex3D position, Vertex3D velocity, Color color)
    : BasePrimitive(position, velocity, color), radius(radius) {
};

Sphere::Sphere(const Sphere &sphere)
    : BasePrimitive(sphere.position, sphere.velocity, sphere.color), radius(sphere.radius) {}

Sphere* Sphere::clone() {
    return new Sphere(*this);
}

void Sphere::render() {
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glColor3d(color.r, color.g, color.b);
    glutSolidSphere(radius, 30, 30);
    glPopMatrix();
}

void Sphere::update(float dt) {
    float accel = 9.8f * 5;
    float direction = -1.0f;
    float flexible_collission_factor = 0.9f;

    velocity.y = velocity.y + (direction * accel * dt);
    position.y = position.y + velocity.y * dt;
    
    if(position.y < -10.0f + (radius / 2)) {
        velocity.y = -velocity.y * flexible_collission_factor;
        position.y = -10.0f + (radius / 2);
    }
}

BoundingBox Sphere::calculateBoundingBox() {
    Vertex3D b_position(position.x - (radius / 2), position.y - (radius / 2), position.x - (radius / 2));
    Vertex3D b_size(radius, radius, radius);
    BoundingBox b(b_position, b_size);
    return b;
}

void Sphere::setRadius(float radius) {
    this->radius = radius;
}

float Sphere::getRadius() {
    return this->radius;
}
