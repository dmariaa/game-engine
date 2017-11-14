//
//  CameraFPS.hpp
//  motorJuegos
//
//  Created by David María Arribas on 7/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef CameraFPS_hpp
#define CameraFPS_hpp

#include "Camera.hpp"

#include <stdio.h>
#include <math.h>

inline double rot2rad(float a){ return a * M_PI/ 180; }

class CameraFPS : public Camera {
public:
    void render() override;
    void update(float dt) override;
};

#endif /* CameraFPS_hpp */
