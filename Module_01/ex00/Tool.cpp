#include "Tool.hpp"

Tool::Tool() : _type("tool"), _numberOfUses(0), _place(-1) {
    this->_worker = NULL;
}

Tool::~Tool() {
    this->_worker = NULL;
}

void    Tool::removeUser() {
    std::cout  << this->_type << " removed" << std::endl;
    this->_place = -1;
    this->_worker = NULL;
}

void    Tool::changeUser(Worker *worker) {
    if (worker != NULL) {
        if (this->_worker != NULL) {
            std::cout << this->_type << " change user" << std::endl;
            this->_worker->drop(this->_place);
        }
        else {
            std::cout  << this->_type << " get user" << std::endl;
        }
        this->_worker = worker;
    }
}

void    Tool::setPlace(int num) {
    this->_place = num;
}

int     Tool::getPlace() {
    return this->_place;
}