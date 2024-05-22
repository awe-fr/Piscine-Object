#pragma once

#include "shape.hpp"

class Triangle : public Shape {
    private:
        float   _a;  
        float   _b;
        float   _c;
    public:
        Triangle(float a, float b, float c) {this->_a = a; this->_b = b; this->_c = c;};
        float perimeter() {return (this->_a + this->_b + this->_c);};
        float area() {return ((this->_a * this->_b) / 2);};
};