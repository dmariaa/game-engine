//
//  BasePrimitive.hpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef BasePrimitive_hpp
#define BasePrimitive_hpp

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Vertex3D.hpp"
#include "Color.hpp"
#include "BoundingBox.hpp"

using namespace std;

class BasePrimitive {
protected:
    Vertex3D position;
    Vertex3D rotation;
    Vertex3D velocity;
    Vertex3D rotation_velocity;
    Vertex3D force;
    Color color;
    float mass;
    
public:
    /** Constructors */
    BasePrimitive();
    BasePrimitive(Vertex3D position, Vertex3D velociy, Color color, Vertex3D force = Vertex3D(), float mass = 0.0f);
    BasePrimitive(const BasePrimitive &primitive);
    virtual ~BasePrimitive();
    virtual BasePrimitive* clone() = 0;

    bool collides(BasePrimitive* b);

    virtual void render() = 0;
    virtual void update(float dt) = 0;
    virtual BoundingBox calculateBoundingBox() = 0;
    
    /** Setters and getters */
    void setPosition(Vertex3D position);
    Vertex3D getPosition();
    void setVelocity(Vertex3D velocity);
    Vertex3D getVelocity();
    void setRotationVelocity(Vertex3D velocity);
    Vertex3D getRotationVelocity();
    void setColor(Color color);
    Color getColor();
    Vertex3D getRotation();
    void setRotation(Vertex3D rotation);
    
    /** Operators */
    friend ostream &operator<<(ostream &os, const BasePrimitive &primitive);
};

#endif /* BasePrimitive_hpp */
