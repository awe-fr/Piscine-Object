#pragma once

#include <iostream>
#include "Break.hpp"
#include "Engine.hpp"

class Contact {
    private:
        bool    _status;
    public:
        Contact() {this->_status = false;};
        bool    getStatus() {return(this->_status);};
        void    on() {
            if (this->_status == false) {
                this->_status = true;
                std::cout << "Turned on" << std::endl;
            }
            else
                std::cout << "Already on" << std::endl;
        };
        void    off(Break *brea, Engine *engine) {
            if (this->_status == true) {
                this->_status = false;
                brea->EmergencyBreaked(engine);
                std::cout << "Turned off" << std::endl;
            }
            else
                std::cout << "Already off" << std::endl;
        };
};