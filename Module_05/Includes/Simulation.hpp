#pragma once

#include "Header.h"

class Event;
class Train;
class Rail;

class Simulation {
    private:
        std::vector<Train *> _trains;
        std::vector<Event *> _events;
        std::vector<Rail *> _rails;
        std::vector<Node *> _nodes;
        Clock *_clock;
    public:
        Simulation();
        ~Simulation();
		void StartSimulation();
        void printEstimateTime();
        void exec();
        void printTrainStatus(int i);
        float getTimeToStop(Train *train, float speed);
};