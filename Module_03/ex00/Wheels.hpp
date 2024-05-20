#pragma once

#include <iostream>

class Wheels {
    private:
        float _wheelsAngle;
    public:
        Wheels() {this->_wheelsAngle = 0;};
        void    turn(int degre) {
            this->_wheelsAngle += degre;
            if (this->_wheelsAngle > 25)
                this->_wheelsAngle = 25;
            else if (this->_wheelsAngle < -25)
                this->_wheelsAngle = -25;
            std::cout << "New the wheel are rotating at " << this->_wheelsAngle << std::endl;
        };
        void    reset() {
            this->_wheelsAngle = 0;
            std::cout << "Wheel position reset to 0" << std::endl;
        };
};