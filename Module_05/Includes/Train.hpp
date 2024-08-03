#pragma once

#include "Node.hpp"
#include "Rail.hpp"
#include "Event.hpp"

class Node;
class Rail;
class Event;

class Train {
    private:
        std::vector<Rail *> _path;
        std::string _name;
		std::string _status;
        Node        *_departure;
        Node        *_arrival;
        int         _id;
        float       _maxAcceleration;
        float       _maxBrakeForce;
        float       _departureHour;
		float		_speed;
        float       _traveled;
        float       _time;
    public:
        Train(std::string name, Node *a, Node *b, float acc, float brake, float departure);
        std::string getName();
		std::string getStatus();
        Rail *getRail();
        Node *getArrival();
        Node *getDeparture();
		int railNumber();
        int changeRail();
        int loadEvent(Node *node, std::vector<Event *> lst);
        void subTime();
        void setSpeed(float value);
        void addSegment(Rail *rail);
        void setTraveled(float value);
		void setStatus(std::string status);
		float getAcc();
        float getTime();
		float getHour();
		float getBrake();
		float getSpeed();
		float railLenght();
        float getTraveled();
};