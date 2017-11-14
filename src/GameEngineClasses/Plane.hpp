//
//  Plane.hpp
//  src
//
//  Created by David María Arribas on 14/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include "BasePrimitive.hpp"
#include "Vertex3D.hpp"

#include <stdio.h>

class Plane : public BasePrimitive {
    float a, b, c, d;
    
public:
    Plane();
    Plane(Vertex3D vn, Vertex3D p);
    Plane(const Plane &plane);

    // Setters and getters
    float getA() const;
    void setA(float a);
    float getB() const;
    void setB(float b);
    float getC() const;
    void setC(float c);
    float getD() const;
    void setD(float d);
};

#endif /* Plane_hpp */
