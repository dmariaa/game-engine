//
//  KeyboardHandler.cpp
//  src
//
//  Created by David María Arribas on 24/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "InputHandler.hpp"

InputHandler::InputHandler() : keys() {}

void InputHandler::registerActionCallback(void (*callback)(bool), const unsigned int key) {
    this->keys[key] = callback;
}

void InputHandler::registerAxisCallback(void (*callback)(float), const unsigned int axis) {
    this->axis[axis] = callback;
}

void InputHandler::keyPressed(unsigned char key, int x, int y) {
    // std::cout << "Pressed " << key << " key" << std::endl;
    try {
        void (*handler)(bool) = this->keys.at(key);
        if(handler != nullptr) {
            (*handler)(true);
        }
    } catch(...) {}
    try {
        void (*handler)(float) = this->axis.at(key);
        handler = this->axis.at(key);
        if(handler != nullptr) {
            (*handler)(1.0f);
        }
    } catch(...) {}
}

void InputHandler::keyReleased(unsigned char key, int x, int y) {
    // std::cout << "Released " << key << " key" << std::endl;
    try {
        void (*handler)(bool) = this->keys.at(key);
        if(handler != nullptr) {
            (*handler)(false);
        }
    } catch(...) {}
    try {
        void (*handler)(float) = this->axis.at(key);
        handler = this->axis.at(key);
        if(handler != nullptr) {
            (*handler)(-1.0f);
        }
    } catch(...) {}
}

void InputHandler::mouseMove(int x, int y) {
    int mouseDeltaX = x - this->mouseX;
    int mouseDeltaY = y - this->mouseY;
    float windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    float windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    if(mouseDeltaX) {
        try {
            void (*handler)(bool) = this->keys.at(MOUSE_X_AXIS);
            if(handler != nullptr) {
                (*handler)(true);
            }
        } catch(...) {}
        try {
            void (*handler)(float) = this->axis.at(MOUSE_X_AXIS);
            if(handler != nullptr) {
                (*handler)((float)mouseDeltaX / (windowWidth * 0.5f));
            }
        } catch(...) {}
    }
    if(mouseDeltaY) {
        try {
            void (*handler)(bool) = this->keys.at(MOUSE_Y_AXIS);
            if(handler != nullptr) {
                (*handler)(true);
            }
        } catch(...) {}
        try {
            void (*handler)(float) = this->axis.at(MOUSE_Y_AXIS);
            if(handler != nullptr) {
                (*handler)((float)mouseDeltaY / (windowHeight * 0.5f));
            }
        } catch(...) {}
    }
}

void InputHandler::mouseClick(int button, int state, int x, int y) {
    if(state==GLUT_DOWN) {
        this->mouseX = x;
        this->mouseY = y;
    } else {
        try {
            void (*handler)(float) = this->axis.at(MOUSE_Y_AXIS);
            if(handler != nullptr) {
                (*handler)(0.0f);
            }
        } catch(...) {}
        try {
            void (*handler)(float) = this->axis.at(MOUSE_X_AXIS);
            if(handler != nullptr) {
                (*handler)(0.0f);
            }
        } catch(...) {}
    }
}
