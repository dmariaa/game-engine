//
//  Cube.cpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Cube.hpp"

Cube::Cube() : BasePrimitive() {};

Cube::Cube(Vertex3D size, Vertex3D position, Vertex3D velocity, Color color)
    : BasePrimitive(position, velocity, color), size(size) {};

Cube::Cube(const Cube &cube) : BasePrimitive(cube), size(cube.size) {}

void Cube::render() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glScaled(size.x, size.y, size.z);
    glColor3f(color.r, color.g, color.b);
    glutSolidCube(1);
    glPopMatrix();
}

void Cube::update(float dt) {
}

BoundingBox Cube::calculateBoundingBox() {
    Vertex3D b_position(position.x - (size.x / 2), position.y - (size.y / 2), position.x - (size.z / 2));
    BoundingBox b(b_position, size);
    return b;
}

void Cube::setSize(Vertex3D size) {
    this->size = size;
}

BasePrimitive *Cube::clone() {
    return new Cube(*this);
}
