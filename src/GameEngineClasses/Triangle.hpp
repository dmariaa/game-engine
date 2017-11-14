//
//  Triangle.hpp
//  src
//
//  Created by David María Arribas on 9/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "BasePrimitive.hpp"
#include "Plane.hpp"

#include <stdio.h>

class Triangle : public Plane {
    Vertex3D p0, p1, p2;
public:
    Triangle(Vertex3D p0, Vertex3D p1, Vertex3D p2);
};

#endif /* Triangle_hpp */
