//
//  BoundingBox.hpp
//  src
//
//  Created by David María Arribas on 10/10/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#ifndef BoundingBox_hpp
#define BoundingBox_hpp

#include <stdio.h>
#include "Vertex3D.hpp"

class BoundingBox {
public:
    Vertex3D position;
    Vertex3D size;
    BoundingBox(Vertex3D position, Vertex3D size);
};

#endif /* BoundingBox_hpp */
