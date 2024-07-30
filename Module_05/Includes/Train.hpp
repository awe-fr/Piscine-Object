#pragma once

#include "Node.hpp"
#include "Rail.hpp"

class Node;
class Rail;

class Train {
    private:
        std::vector<Rail *> _path;
        std::string _name;
		std::string _status;
        Node        *_departure;
        Node        *_arrival;
        float       _maxAcceleration;
        float       _maxBrakeForce;
        float       _departureHour;
		float		_speed;
    public:
        Train(std::string name, Node *a, Node *b, float acc, float brake, float departure);
        Node *getDeparture();
        Node *getArrival();
        void addSegment(Rail *rail);
        std::string getName();
		float getAcc();
		float getBrake();
		int railNumber();
		float railLenght();
		float getSpeed();
		std::string getStatus();
		void setStatus(std::string status);
		float getHour();
};