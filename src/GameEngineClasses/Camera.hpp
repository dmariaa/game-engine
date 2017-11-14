//
//  Camera.hpp
//  src
//
//  Created by David María Arribas on 19/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <iostream>
#include "BasePrimitive.hpp"

class Camera : public BasePrimitive {
public:
    Camera();
    Camera(Vertex3D position, Vertex3D velocity, Color color);
    Camera(const Camera &camera);
    Camera* clone() override;

    virtual void render() override;
    virtual void update(float dt) override;
    BoundingBox calculateBoundingBox() override;
};

#endif /* Camera_hpp */
