//
//  Game.cpp
//  src
//
//  Created by David María Arribas on 17/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Game.hpp"

Game* Game::gameInstance = 0;

Game::Game() : scene(new Scene()), keyboardHandler(new InputHandler()) {}

void Game::init(int argc, char** argv) {
    gameInstance = this;
    lastUpdateTime = 0;
    initGlut(argc, argv);
}

void Game::start() {
    glutMainLoop();
}

Scene* Game::getScene() {
    return this->scene;
}

InputHandler* Game::getInputHandler() {
    return this->keyboardHandler;
}

void Game::initScene(void (*initSceneCallback)(Scene *)) {
    scene->initScene(initSceneCallback);
}

void Game::initGlut(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // glutInitWindowSize(800,600);
    // glutInitWindowPosition(100,100);
    windowId = glutCreateWindow("Hello wold :D");
    glutFullScreen();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
}

void Game::_display() {
    scene->render();
    glFlush();
    glutSwapBuffers();
}

void Game::_keyPressed(unsigned char key,int x,int y) {
    this->keyboardHandler->keyPressed(key, x, y);
}

void Game::_keyReleased(unsigned char key,int x,int y) {
    this->keyboardHandler->keyReleased(key, x, y);
}

void Game::_mouseClick(int button, int state, int x, int y) {
    this->keyboardHandler->mouseClick(button, state, x, y);
}

void Game::_mouseMove(int x, int y) {
    this->keyboardHandler->mouseMove(x, y);
}


void Game::_idle() {
    if(lastUpdateTime==0) {
        lastUpdateTime = glutGet(GLUT_ELAPSED_TIME);
        return;
    }
    
    double currentTime = glutGet(GLUT_ELAPSED_TIME);
    float dt = float((currentTime - lastUpdateTime) / 1000.0f);
    lastUpdateTime = currentTime;
    scene->update(dt);
    glutPostRedisplay();
}

void Game::_reshape(int width, int height) {
    glViewport(0 , 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f,(GLfloat)width/(GLfloat)height,1.0f,200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Game::setInstance(Game* instance){
    gameInstance = instance;
}

void Game::display() {
    gameInstance->_display();
}

void Game::idle() {
    gameInstance->_idle();
}

void Game::reshape(int width, int height) {
    gameInstance->_reshape(width, height);
}

void Game::keyPressed(unsigned char key, int x, int y) {
    gameInstance->_keyPressed(key, x, y);
}

void Game::keyReleased(unsigned char key, int x, int y) {
    gameInstance->_keyReleased(key, x, y);
}

void Game::mouseMove(int x, int y) {
    gameInstance->_mouseMove(x, y);
}

void Game::mouseClick(int button, int state, int x, int y) {
    gameInstance->_mouseClick(button, state, x, y);
}


