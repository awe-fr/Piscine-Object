#pragma once

#include <iostream>
#include "Engine.hpp"

class Accelerator {
    private:

    public:
        Accelerator() {};
        void    accelerate(Engine *engine, bool status, float speed) {
            if (status == true) {
                if (engine == NULL)
                    return;
                if (speed < 0) {
                    std::cout << "Use break next time" << std::endl;
                    return;
                }
                engine->setSpeed(engine->getSpeed() + speed);
            }
            else
                std::cout << "Please turn the engine on" << std::endl;
        };
};