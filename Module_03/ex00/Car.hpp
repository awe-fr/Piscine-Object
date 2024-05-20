#pragma once

#include "Contact.hpp"
#include "Engine.hpp"
#include "GearBox.hpp"
#include "Accelerator.hpp"
#include "Break.hpp"
#include "Wheels.hpp"
#include <iostream>

class Car {
    private:
        Accelerator _accelerator;
        GearBox     _gearBox;
        Contact     _contact;
        Engine      _engine;
        Wheels      _wheels;
        Break       _break;
        
    public:
        Car() {};
        ~Car() {};
        void    start() {this->_contact.on();};
        void    stop() {this->_contact.off(&this->_break, &this->_engine);};
        void    accelerate(float speed) {this->_accelerator.accelerate(&this->_engine, this->_contact.getStatus(), speed);};
        void    shift_gear_up() {this->_gearBox.up();};
        void    shift_gear_down() {this->_gearBox.down();};
        void    reverse() {this->_gearBox.rear();};
        void    turn_wheel(float angle) {this->_wheels.turn(angle);};
        void    straighten_wheels() {this->_wheels.reset();};
        void    apply_force_on_brakes(float force) {this->_break.breaked(&this->_engine, force);};
        void    apply_emergency_brakes() {this->_break.EmergencyBreaked(&this->_engine);};
};