//
//  main.cpp
//  src
//
//  Created by David María Arribas on 28/9/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "GameEngineClasses/Sphere.hpp"
#include "GameEngineClasses/Cube.hpp"
#include "GameEngineClasses/Scene.hpp"
#include "GameEngineClasses/Game.hpp"

Game* game;
Camera* camera;

void initObjects(Scene* scene);

/* Input handlers */
void forwardHandler(bool pressed);
void backHandler(bool pressed);
void leftHandler(bool pressed);
void rightHandler(bool pressed);
void escHandler(bool pressed);
void mouseXHandler(float f);
void mouseYHandler(float f);


int main(int argc, char** argv) {
    game = new Game();
    camera = game->getScene()->getCamera();
    game->init(argc, argv);
    game->initScene(initObjects);
    game->getInputHandler()->registerActionCallback(forwardHandler, 'w');
    game->getInputHandler()->registerActionCallback(backHandler, 's');
    game->getInputHandler()->registerActionCallback(leftHandler, 'a');
    game->getInputHandler()->registerActionCallback(rightHandler, 'd');
    game->getInputHandler()->registerActionCallback(escHandler, 27);
    game->getInputHandler()->registerAxisCallback(mouseXHandler, MOUSE_X_AXIS);
    game->getInputHandler()->registerAxisCallback(mouseYHandler, MOUSE_Y_AXIS);
    game->start();
}

void escHandler(bool pressed) {
    exit(0);
}

void forwardHandler(bool pressed) {
    Vertex3D vel = camera->getVelocity();
    vel.z = pressed ? 10.0f : 0.0f;
    camera->setVelocity(vel);
}

void backHandler(bool pressed) {
    Vertex3D vel = camera->getVelocity();
    vel.z = pressed ? -10.0f : 0.0f;
    camera->setVelocity(vel);
}

void leftHandler(bool pressed) {
    Vertex3D vel = camera->getVelocity();
    vel.x = pressed ? 10.0f : 0.0f;
    camera->setVelocity(vel);
}

void rightHandler(bool pressed) {
    Vertex3D vel = camera->getVelocity();
    vel.x = pressed ? -10.0f : 0.0f;
    camera->setVelocity(vel);
}

void mouseXHandler(float f) {
    Vertex3D rotation_velocity = camera->getRotationVelocity();
    rotation_velocity.y = 10.0f * f;
    camera->setRotationVelocity(rotation_velocity);
}

void mouseYHandler(float f) {
    Vertex3D rotation_velocity = camera->getRotationVelocity();
    rotation_velocity.x = 10.0f * f;
    camera->setRotationVelocity(rotation_velocity);
}

void initObjects(Scene* scene) {
    Sphere* esfera = new Sphere();
    esfera->setPosition(Vertex3D(-4.0f, 10.0f, 0.0f));
    esfera->setColor(Color(1.0f, 0.0f, 0.0f));
    esfera->setRadius(2.0f);
    scene->addPrimitive(esfera);
    
    esfera = new Sphere();
    esfera->setPosition(Vertex3D(4.0f, 16.0f, 0.0f));
    esfera->setColor(Color(0.0f, 0.0f, 1.0f));
    esfera->setRadius(2.0f);
    scene->addPrimitive(esfera);
    
    Cube* cubo = new Cube[10];
    cubo->setPosition(Vertex3D(0.0f, -11.0f, 0.0f));
    cubo->setSize(Vertex3D(200.0f, 0.5f, 200.0f));
    cubo->setColor(Color(0.0f, 1.0f, 0.0f));
    scene->addPrimitive(cubo);
}


