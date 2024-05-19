#include "Shovel.hpp"

Shovel::Shovel() {
    this->_type = "Shovel";
    std::cout << this->_type << " constructor" << std::endl;
    this->_numberOfUses = 0;
    this->_place = -1;
    this->_worker = NULL;
}
        
Shovel::~Shovel() {
    std::cout << this->_type << " destructor" << std::endl;
    this->_worker = NULL;
}

void    Shovel::use() {
    std::cout << this->_type << " used" << std::endl;
    this->_numberOfUses++;
}
