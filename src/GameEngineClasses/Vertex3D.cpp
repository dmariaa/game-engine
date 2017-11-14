//
//  Vector3D.cpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include <cmath>
#include <cassert>
#include "Vertex3D.hpp"

Vertex3D::Vertex3D() : x(0.0f), y(0.0f), z(0.0f) {};

Vertex3D::Vertex3D(float x, float y, float z) : x(x), y(y), z(z) {
}

Vertex3D Vertex3D::operator+(Vertex3D b) {
    Vertex3D ret(0.0f, 0.0f, 0.0f);
    ret.x = this->x + b.x;
    ret.y = this->y + b.y;
    ret.z = this->z + b.z;
    return ret;
}

Vertex3D Vertex3D::operator-(Vertex3D b) {
    Vertex3D ret(0.0f, 0.0f, 0.0f);
    ret.x = this->x - b.x;
    ret.y = this->y - b.y;
    ret.z = this->z - b.z;
    return ret;
}

Vertex3D Vertex3D::operator*(float f) {
    Vertex3D ret(0.0f, 0.0f, 0.0f);
    ret.x = this->x * f;
    ret.y = this->y * f;
    ret.z = this->z * f;
    return ret;
}

float Vertex3D::operator*(Vertex3D b) {
    Vertex3D &a = *this;
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

std::ostream &operator<<(std::ostream &os, const Vertex3D &v) {
    os << "(" << v.x << "," << v.y << "," << v.z << ")";
    return os;
}

Vertex3D Vertex3D::crossProduct(Vertex3D &v) {
    Vertex3D &v0 = *this;
    return Vertex3D(
            v0.y * v.z - v0.z * v.y,
            v0.z * v.x - v0.x * v.z,
            v0.x * v.y - v0.y * v.x);
}

float Vertex3D::lengthSquared() {
    return x * x + y * y + z * z;
}

float Vertex3D::length() {
    return sqrt(this->lengthSquared());
}

bool Vertex3D::equalsZero(float a) {
    return fabs(0) < 0.00001;
}

void Vertex3D::normalize() {
    float magnitude = this->length();
    assert(!this->equalsZero(magnitude));

    magnitude = 1.0f / magnitude;
    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}

float Vertex3D::getX() const {
    return x;
}

void Vertex3D::setX(float x) {
    Vertex3D::x = x;
}

float Vertex3D::getY() const {
    return y;
}

void Vertex3D::setY(float y) {
    Vertex3D::y = y;
}

float Vertex3D::getZ() const {
    return z;
}

void Vertex3D::setZ(float z) {
    Vertex3D::z = z;
}




