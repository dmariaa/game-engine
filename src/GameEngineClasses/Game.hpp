//
//  Game.hpp
//  src
//
//  Created by David María Arribas on 17/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <stdio.h>
#include "Scene.hpp"
#include "InputHandler.hpp"

class Game {
    static Game* gameInstance;
    
    Scene* scene;
    InputHandler* keyboardHandler;
    double lastUpdateTime;
    int windowId;
    
    void initGlut(int argc, char** argv);

    // Instance callbacks
    void _display();
    void _idle();
    void _reshape(int width, int height);
    void _keyPressed(unsigned char key, int x, int y);
    void _keyReleased(unsigned char key, int x, int y);
    void _mouseMove(int x, int y);
    void _mouseClick(int button, int state, int x, int y);

    // Glut static callbacks
    static void display();
    static void idle();
    static void reshape(int width,int height);
    static void keyPressed(unsigned char key,int x,int y);
    static void keyReleased(unsigned char key,int x,int y);
    static void mouseMove(int x, int y);
    static void mouseClick(int button, int state, int x, int y);

public:
    Game();
    void init(int argc, char** argv);
    void initScene(void (*initSceneCallback)(Scene* ));
    void start();

    /** Getters and setters */
    void setInstance(Game* instance);
    Scene* getScene();
    InputHandler* getInputHandler();
};

#endif /* Game_hpp */
