//
//  Scene.cpp
//  src
//
//  Created by David María Arribas on 17/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene() {
    this->camera = new CameraFPS();
};

void Scene::addPrimitive(BasePrimitive* primitive) {
    primitives.push_back(primitive);
}

void Scene::initScene(void (*initSceneCallback)(Scene *)) {
    (*initSceneCallback)(this);
}

void Scene::render() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLfloat lightpos[]={ 5.0f, 15.0f, 5.0f, 0.0f };
    glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
    
    this->camera->render();

    /* Usando iteradores
     for(std::vector<BasePrimitive *>::iterator primitivesIterator = primitives.begin();
     primitivesIterator != primitives.end(); ++primitivesIterator) {
     (*primitivesIterator)->render();
     }
     */
    for(BasePrimitive* prim : primitives) {
        prim->render();
    }
}

void Scene::update(float dt) {
    /* Usando iteradores
    for(std::vector<BasePrimitive *>::iterator primitivesIterator = primitives.begin();
        primitivesIterator != primitives.end(); ++primitivesIterator) {
        (*primitivesIterator)->update(dt);
    }
     */
    this->camera->update(dt);
    
    for(BasePrimitive* prim : primitives) {
        prim->update(dt);
    }
}

Camera* Scene::getCamera() {
    return this->camera;
}
