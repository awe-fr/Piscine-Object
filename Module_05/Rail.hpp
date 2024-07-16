#pragma once

#include "Node.hpp"

class Rail {
    private:
        Node    *_a;
        Node    *_b;
        int     _lenght;
    public:
        Rail(Node *a, Node *b, int lenght);
};