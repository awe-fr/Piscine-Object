#pragma once

#include "Header.h"

class Simulation {
    private:
        std::vector<Train *> _trains;
        std::vector<Event *> _events;
        std::vector<Rail *> _rails;
        std::vector<Node *> _nodes;
        Clock *_clock;
    public:
        Simulation();
		void StartSimulation();
        void printEstimateTime();
        void exec();
};