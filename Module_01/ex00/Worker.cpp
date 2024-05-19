#include "Worker.hpp"

Worker::Worker() {
    std::cout << "Worker constructor" << std::endl;
    this->_coordonnee.x = 0;
    this->_coordonnee.y = 0;
    this->_coordonnee.z = 0;
    this->_stat.level = 0;
    this->_stat.exp = 0;
    for (int i = 0; i < 4; i++)
        this->_tool[i] = NULL;
    this->_status = 0;
}

Worker::~Worker() {
    std::cout << "Worker destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_tool[i] = NULL;
}

void    Worker::grab(Tool *tool) {
    std::cout << "Worker grab" << std::endl;
    if (tool != NULL) {
        for (int i = 0; i < 4; i++) {
            if (this->_tool[i] == NULL) {
                tool->changeUser(this);
                this->_tool[i] = tool;
                this->_tool[i]->setPlace(i);
                break;
            }
        }
    }
}

void    Worker::drop(int place) {
    std::cout << "worker drop" << std::endl;
    this->_tool[place]->removeUser();
    this->_tool[place] = NULL;
}

void    Worker::use(int place) {
    if (this->_tool[place] != NULL) {
        std::cout << "worker use" << std::endl;
        this->_tool[place]->use();
    }
}

void    Worker::print() {
    for (int i = 0; i < 4; i++) {
        if (this->_tool[i] == NULL)
            std::cout << "false ";
        else
            std::cout << "true ";
    }
    std::cout << std::endl;
}

void    Worker::hire() {
    std::cout << "Worker changed status" << std::endl;
    this->_status += 1;
}

void    Worker::fire() {
    std::cout << "Worker changed status" << std::endl;
    this->_status -= 1;
}

void    Worker::work() {
    if (this->_status > 0) {
        std::cout << "Worker work" << std::endl;
    }
    else {
        std::cout << "Worker not in a workshop" << std::endl;
    }
}