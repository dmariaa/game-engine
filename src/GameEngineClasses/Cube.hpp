//
//  Cube.hpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "BasePrimitive.hpp"

class Cube : public BasePrimitive {
    Vertex3D size;
    
public:
    Cube();
    Cube(Vertex3D size, Vertex3D position, Vertex3D velocity, Color color);
    Cube(const Cube &cube);

    // Parent functions
    void render() override;
    void update(float dt) override;
    BoundingBox calculateBoundingBox() override;
    BasePrimitive *clone() override;
    
    // Getters and setters
    void setSize(Vertex3D size);
    Vertex3D getSize();
};

#endif /* Cube_hpp */
