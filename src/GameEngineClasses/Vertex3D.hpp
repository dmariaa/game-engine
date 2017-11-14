//
//  Vector3D.hpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Vertex3D_hpp
#define Vertex3D_hpp

#include <stdio.h>
#include <iostream>

class Vertex3D {
public:
    float x;
    float y;
    float z;

public:
    Vertex3D();
    Vertex3D(float x, float y, float z);

    // Getters and setters
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getZ() const;
    void setZ(float z);

    // Operators
    Vertex3D operator+(Vertex3D b);
    Vertex3D operator-(Vertex3D b);
    Vertex3D operator*(float f);
    float operator*(Vertex3D b);
    friend std::ostream &operator<<(std::ostream &os, const Vertex3D &v);

    // Other functions
    Vertex3D crossProduct(Vertex3D &v);
    float lengthSquared();
    float length();
    bool equalsZero(float a);
    void normalize();
};

#endif /* Vertex3D_hpp */
