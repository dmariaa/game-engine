//
//  Scene.hpp
//  src
//
//  Created by David María Arribas on 17/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "BasePrimitive.hpp"
#include "Camera.hpp"
#include "CameraFPS.hpp"

class Scene {
    std::vector<BasePrimitive *> primitives;
    Camera* camera;
    
public:
    Scene();
    void initScene(void (*initSceneCallback)(Scene* scene));
    void addPrimitive(BasePrimitive* primitive);
    void render();
    void update(float dt);
    
    Camera* getCamera();
};

#endif /* Scene_hpp */
