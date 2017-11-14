//
//  CompoundPrimitive.cpp
//  motorJuegos
//
//  Created by David María Arribas on 14/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "CompoundPrimitive.hpp"

CompoundPrimitive::CompoundPrimitive() {}

CompoundPrimitive::CompoundPrimitive(const CompoundPrimitive &primitive)
    : BasePrimitive() {
    for(BasePrimitive* p : primitive.primitives) {
        BasePrimitive *bp = p->clone();
        this->primitives.push_back(bp);
    }
}

CompoundPrimitive* CompoundPrimitive::clone() {
    return new CompoundPrimitive(*this);
}

CompoundPrimitive::~CompoundPrimitive() {
    for(BasePrimitive* primitive : this->primitives) {
        delete primitive;
    }
    primitives.clear();
}

void CompoundPrimitive::render() {

}

void CompoundPrimitive::update(float dt) {

}

BoundingBox CompoundPrimitive::calculateBoundingBox() {
    return BoundingBox(Vertex3D(), Vertex3D());
}

