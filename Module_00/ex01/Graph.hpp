#pragma once

#include <iostream>
#include <vector>

typedef struct Vector2 {
    float x;
    float y;
}   vec2;

class Graph {
    private:
        std::vector<vec2>   _points;
        Vector2             _size;

    public:
        Graph(float x, float y);
        ~Graph();
        void    addPoint(float x, float y);
        void    addPoint(vec2 point);
        void    printGraph();
        bool    isPoint(int x, int y);
        bool    alreadyHere(vec2 toCheck);
};