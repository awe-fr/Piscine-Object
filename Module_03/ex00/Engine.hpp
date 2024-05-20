#pragma once

#include <iostream>

class Engine {
    private:
        float   _speed;
    public:
        Engine() {this->_speed = 0;};
        void    setSpeed(float newSpeed) {
            this->_speed = newSpeed;
            if (this->_speed > 320) {
                this->_speed = 320;
                std::cout << "Maximum speed reached 320 !!" << std::endl;
            }
            if (this->_speed < 0) {
                this->_speed = 0;
                std::cout << "Minimum speed is 0" << std::endl;
            }
            std::cout << "Now speed is " << this->_speed << std::endl;
        };
        float    getSpeed() {return (this->_speed);};
};