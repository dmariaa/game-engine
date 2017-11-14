//
//  Sphere.hpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include "BasePrimitive.hpp"

class Sphere : public BasePrimitive {
    float radius = 0.0f;
    
public:
    Sphere();
    Sphere(float radius, Vertex3D position, Vertex3D velocity, Color color);
    Sphere(const Sphere &sphere);
    Sphere* clone();
    void render();
    void update(float dt);
    BoundingBox calculateBoundingBox();
    
    // Setters y getters
    void setRadius(float radius);
    float getRadius();
};

#endif /* Sphere_hpp */
