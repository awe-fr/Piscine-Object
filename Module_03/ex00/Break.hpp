#pragma once

#include <iostream>
#include "Engine.hpp"

class Break  {
    private:

    public:
        Break() {};
        void    breaked(Engine *engine, float speed) {
            if (engine == NULL)
                return;
            if (speed < 0) {
                std::cout << "Use accelerator next time" << std::endl;
                return;
            }
            engine->setSpeed(engine->getSpeed() - speed);
        };
        void    EmergencyBreaked(Engine *engine) {
            engine->setSpeed(0);
        }
};