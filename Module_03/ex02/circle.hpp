#pragma once

#include "shape.hpp"
#include <math.h>

class Circle : public Shape {
    private:
        float   _radius;
    public:
        Circle(float radius) {this->_radius = radius;};
        float perimeter() {return (2 * M_PI * this->_radius);};
        float area() {return (M_PI * (this->_radius * this->_radius));};
};