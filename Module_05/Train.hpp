#pragma once

#include "Node.hpp"

class Train {
    private:
        std::string _name;
        Node        *_departure;
        Node        *_arrival;
        int         _maxAcceleration;
        int         _maxBrakeForce;
        int         _departureHour;
    public:
        Train(std::string name, Node *a, Node *b, int acc, int brake, int departure);
};