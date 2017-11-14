//
//  CompoundPrimitive.hpp
//  src
//
//  Created by David María Arribas on 14/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef CompoundPrimitive_hpp
#define CompoundPrimitive_hpp

#include <stdio.h>
#include <vector>
#include "BasePrimitive.hpp"

class CompoundPrimitive : public BasePrimitive {
    vector<BasePrimitive*> primitives;
public:
    CompoundPrimitive();
    CompoundPrimitive(const CompoundPrimitive &primitive);
    CompoundPrimitive* clone() override;
    
    virtual ~CompoundPrimitive();

    // Parent implementations
    void render() override;
    void update(float dt) override;
    BoundingBox calculateBoundingBox() override;

};
#endif /* CompoundPrimitive_hpp */
