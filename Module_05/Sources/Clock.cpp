#include "../Includes/Clock.hpp"

Clock::Clock() : _hour(0) {

}

int Clock::getHour() {
    return this->_hour;
}

void Clock::passTime() {
    usleep(1);
    this->_hour += 1;
    if (this->_hour % 100 >= 60) {
        this->_hour -= 60;
        this->_hour += 100;
    }
    if (this->_hour / 100 >= 24) {
        this->_hour -= 2400;
    }
}