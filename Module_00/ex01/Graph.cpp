#include "Graph.hpp"

Graph::Graph(float x, float y) {
    int setx = (int)x;
    int sety = (int)y;
    if (setx <= 0)
        setx = 1;
    if (sety <= 0)
        sety = 1;
    vec2 result; result.x = (float)setx; result.y = (float)sety;
    this->_size = result;
}

Graph::~Graph() {

}

void    Graph::addPoint(vec2 point) {
    if (point.x > this->_size.x || point.x <= 0) {
        std::cout << std::endl << "Point out of range" << std::endl;
        return;
    }
    if (point.y > this->_size.y || point.y <= 0) {
        std::cout << std::endl << "Point out of range" << std::endl;
        return;
    }
    if (alreadyHere(point) == true) {
        std::cout << std::endl << "Point already here" << std::endl;
        return;
    }
    this->_points.push_back(point);
    printGraph();
}

void    Graph::addPoint(float x, float y) {
    int setx = (int)x;
    if (setx > this->_size.x || setx <= 0) {
        std::cout << std::endl << "Point out of range" << std::endl;
        return;
    }
    int sety = (int)y;
    if (sety > this->_size.y || sety <= 0) {
        std::cout << std::endl << "Point out of range" << std::endl;
        return;
    }
    vec2 result; result.x = (float)setx; result.y = (float)sety;
    if (alreadyHere(result) == true) {
        std::cout << std::endl << "Point already here" << std::endl;
        return;
    }
    this->_points.push_back(result);
    printGraph();
}

void    Graph::printGraph() {
    std::cout << std::endl;
    for (int y = this->_size.y; y > 0; y--)  {
        std::cout << ">& " << y << " ";
        for (int x = 1; x <= this->_size.x; x++) {
            if (isPoint(x, y) == true)
                std::cout << "X ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << ">&   ";
    for (int x = 1; x <= this->_size.x; x++) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

bool    Graph::isPoint(int x, int y) {
    for (int i = this->_points.size(); i > 0; i--) {
        if (this->_points[i - 1].x == (float)x && this->_points[i - 1].y == (float)y) {
            return true;
        }
    }
    return false;
}

bool    Graph::alreadyHere(vec2 toCheck) {
    for (int i = this->_points.size(); i > 0; i--) {
        if (this->_points[i - 1].x == toCheck.x && this->_points[i - 1].y == toCheck.y) {
            return true;
        }
    }
    return false;
}