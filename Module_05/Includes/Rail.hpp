#pragma once

#include "Node.hpp"
#include "Singleton.hpp"

class Node;

class Rail {
    private:
        Node    *_a;
        Node    *_b;
        float   _lenght;
    public:
        Rail(Node *a, Node *b, float lenght);
        Node *getStart();
        Node *getArrival();
        float   getLenght();
};