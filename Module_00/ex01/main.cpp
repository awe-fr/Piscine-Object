#include "Graph.hpp"

int main() {
    vec2 a1; a1.x = 6.0f; a1.y = 3.0f;
    vec2 a2; a2.x = 3.0f; a2.y = 6.0f;
    vec2 a3; a3.x = 2.0f; a3.y = 2.0f;
    vec2 a4; a4.x = 1.0f; a4.y = 3.0f;
    Graph graph = Graph(5, 5);
    graph.addPoint(2, 2);
    graph.addPoint(2, 1);
    graph.addPoint(3, 2);
    graph.addPoint(4, 4);
    graph.addPoint(5, 4);
    graph.addPoint(a1);
    graph.addPoint(a2);
    graph.addPoint(a3);
    graph.addPoint(a4);

    
}