#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include <iostream>

int main() {
    Circle circle(4);
    Triangle triangle(9, 12, 15);
    Rectangle rectangle(10, 15);

    std::cout << "area is : " << circle.area() << std::endl << "perimeter is : " << circle.perimeter() << std::endl;
    std::cout << "area is : " << triangle.area() << std::endl << "perimeter is : " << triangle.perimeter() << std::endl;
    std::cout << "area is : " << rectangle.area() << std::endl << "perimeter is : " << rectangle.perimeter() << std::endl;

}