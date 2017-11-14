//
//  Plane.cpp
//  src
//
//  Created by David María Arribas on 14/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane() {
    a = b = c = d = 0;
}

Plane::Plane(Vertex3D vn, Vertex3D p)
    : a(vn.x), b(vn.y), c(vn.z), d(vn * p) {}
    
Plane::Plane(const Plane &plane)
    : BasePrimitive(plane), a(plane.a), b(plane.b), c(plane.c), d(plane.d)  {}

float Plane::getA() const {
    return a;
}

void Plane::setA(float a) {
    Plane::a = a;
}

float Plane::getB() const {
    return b;
}

void Plane::setB(float b) {
    Plane::b = b;
}

float Plane::getC() const {
    return c;
}

void Plane::setC(float c) {
    Plane::c = c;
}

float Plane::getD() const {
    return d;
}

void Plane::setD(float d) {
    Plane::d = d;
}
