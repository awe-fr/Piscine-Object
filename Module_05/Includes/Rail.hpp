#pragma once

#include "Header.h"

class Node;
class Train;

class Rail {
    private:
        Node    *_a;
        Node    *_b;
        float   _lenght;
		float	_maxSpeed;
    public:
        Rail(Node *a, Node *b, float lenght);
        Node *getStart();
        Node *getArrival();
		float   getSpeed();
        float   getLenght();
        std::string getTrafic(Train *train);
        std::string cutTrafic(std::string line);
};