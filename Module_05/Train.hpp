#pragma once

#include "Node.hpp"

class Train {
    private:
        std::string _name;
        Node        *_departure;
        Node        *_arrival;
        float       _maxAcceleration;
        float       _maxBrakeForce;
        float       _departureHour;
    public:
        Train(std::string name, Node *a, Node *b, float acc, float brake, float departure);
};