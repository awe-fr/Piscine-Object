#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
    private:
        float   _lenght;
        float   _width;
    public:
        Rectangle(float lenght, float width) {this->_lenght = lenght; this->_width = width;};
        float perimeter() {return ((this->_lenght + this->_width) * 2);};
        float area() {return (this->_lenght * this->_width);};
};