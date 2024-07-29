#pragma once

#include "Node.hpp"
#include "Rail.hpp"

class Node;
class Rail;

class Train {
    private:
        std::vector<Rail *> _path;
        std::string _name;
        Node        *_departure;
        Node        *_arrival;
        float       _maxAcceleration;
        float       _maxBrakeForce;
        float       _departureHour;
    public:
        Train(std::string name, Node *a, Node *b, float acc, float brake, float departure);
        Node *getDeparture();
        Node *getArrival();
        void addSegment(Rail *rail);
        std::string getName();
		float getSpeed();
		float getBrake();
		int railNumber();
		float railLenght();
};