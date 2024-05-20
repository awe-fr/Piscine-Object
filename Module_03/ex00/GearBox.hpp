#pragma once

#include <iostream>

class GearBox {
    private:
        int _gear;
    public:
        GearBox() {this->_gear = 0;};
        void    up() {
            if (this->_gear >= 5)
                std::cout << "Gear cannot go higher" << std::endl;
            else {
                this->_gear++;
                std::cout << "Actual gear is " << this->_gear << std::endl;
            }
        };
        void    down() {
            if (this->_gear <= 0)
                std::cout << "Gear cannot go lower" << std::endl;
            else {
                this->_gear--;
                std::cout << "Actual gear is " << this->_gear << std::endl;
            }
        };
        void    rear() {
            if (this->_gear == -1)
                std::cout << "Already in rear" << std::endl;
            else {
                this->_gear = -1;
                std::cout << "Actual gear is rear" << std::endl;
            }
        }
};