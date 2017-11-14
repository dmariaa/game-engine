//
//  BasePrimitive.cpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "BasePrimitive.hpp"

BasePrimitive::BasePrimitive() :
    position(Vertex3D()), velocity(Vertex3D()), color(Color()), force(Vertex3D()), mass(0.0f) {}

BasePrimitive::BasePrimitive(Vertex3D position, Vertex3D velocity, Color color, Vertex3D force, float mass)
    : position(position), velocity(velocity), color(color), force(force), mass(mass) {}

BasePrimitive::BasePrimitive(const BasePrimitive &primitive)
    : position(primitive.position), velocity(primitive.velocity), color(primitive.color), force(primitive.force), mass(primitive.mass) {}

BasePrimitive::~BasePrimitive() {}

bool BasePrimitive::collides(BasePrimitive *b) {
    return false;
}

/** Setters and getters */
void BasePrimitive::setPosition(Vertex3D position) {
    this->position = position;
}
Vertex3D BasePrimitive::getPosition() {
    return this->position;
}
Vertex3D BasePrimitive::getRotation() {
    return this->rotation;
}
void BasePrimitive::setRotation(Vertex3D rotation) {
    this->rotation = rotation;
}
void BasePrimitive::setVelocity(Vertex3D velocity) {
    this->velocity = velocity;
}
Vertex3D BasePrimitive::getVelocity() {
    return this->velocity;
}
void BasePrimitive::setRotationVelocity(Vertex3D velocity) {
    this->rotation_velocity = velocity;
}
Vertex3D BasePrimitive::getRotationVelocity() {
    return this->rotation_velocity;
}
void BasePrimitive::setColor(Color color) {
    this->color = color;
}
Color BasePrimitive::getColor() {
    return this->color;
}

/** Operators */
ostream &operator<<(ostream &os, const BasePrimitive &primitive) {
    os << "Primitive:" << endl;
    os << "Position => " << primitive.position << endl;
    os << "Velocity => " << primitive.velocity << endl;
    os << "Color => " << primitive.color << endl;
    os << "Mass => " << primitive.mass << endl;
    
    return os;
}
