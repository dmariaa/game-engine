//
//  Color.hpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include <ostream>

class Color {
public:
    float r;
    float g;
    float b;

    Color();
    Color(float r, float g, float b);
    
    friend std::ostream &operator<<(std::ostream &os, const Color &color);
};

#endif /* Color_hpp */
