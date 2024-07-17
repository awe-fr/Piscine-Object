#pragma once

#include "Node.hpp"

class Rail {
    private:
        Node    *_a;
        Node    *_b;
        float   _lenght;
    public:
        Rail(Node *a, Node *b, float lenght);
};