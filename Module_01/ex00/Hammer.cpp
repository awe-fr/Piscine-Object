#include "Hammer.hpp"

Hammer::Hammer() {
    this->_type = "Hammer";
    std::cout << this->_type << " constructor" << std::endl;
    this->_numberOfUses = 0;
    this->_place = -1;
    this->_worker = NULL;
}

Hammer::~Hammer() {
    std::cout << this->_type << " destructor" << std::endl;
    this->_worker = NULL;
}

void    Hammer::use() {
    std::cout << this->_type << " used" << std::endl;
    this->_numberOfUses++;
}