//
//  Triangle.cpp
//  src
//
//  Created by David María Arribas on 9/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Triangle.hpp"

//
//  Triangle.cpp
//  src
//
//  Created by David María Arribas on 14/11/17.
//  Copyright © 2017 David María Arribas. All rights reserved.
//

#include "Triangle.hpp"

#include <iostream>

using namespace std;

Triangle::Triangle(Vertex3D p0, Vertex3D p1, Vertex3D p2)
        : Plane(), p0(p0), p1(p1), p2(p2) {
    Vertex3D v0 = p1 - p0;
    Vertex3D v1 = p2 - p1;
    Vertex3D vn = v0.crossProduct(v1);
    if(vn.length() < 0.001) {
        cout << "Very small normal length" << endl;
    } else {
        vn.normalize();
    }
    float d = vn * p2;
    this->setA(vn.getX());
    this->setB(vn.getY());
    this->setC(vn.getZ());
    this->setD(d);
}





