//
//  KeyboardHandler.hpp
//  src
//
//  Created by David María Arribas on 24/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef KeyboardHandler_hpp
#define KeyboardHandler_hpp

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include "InputDefinitions.h"

typedef std::unordered_map<unsigned int, void (*)(bool)> ActionMapping;
typedef std::unordered_map<unsigned int, void (*)(float)> AxisMapping;

class InputHandler {
    friend class Game;
    ActionMapping keys;
    AxisMapping axis;
    
    int mouseX = 0;
    int mouseY = 0;
    
    void keyPressed(unsigned char key, int x, int y);
    void keyReleased(unsigned char key, int x, int y);
    void mouseMove(int x, int y);
    void mouseClick(int button, int state, int x, int y);
public:
    InputHandler();
    void registerActionCallback(void (*callback)(bool), const unsigned int key);
    void registerAxisCallback(void (*callback)(float f), const unsigned int axis);
};

#endif /* KeyboardHandler_hpp */
