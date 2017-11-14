//
//  Color.cpp
//  src
//
//  Created by David María Arribas on 3/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Color.hpp"

Color::Color() : r(0.0f), g(0.0f), b(0.0f) {};

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {};

std::ostream &operator<<(std::ostream &os, const Color &color) {
    os << "(" << color.r << "," << color.g << "," << color.b << ")";
    return os;
}
