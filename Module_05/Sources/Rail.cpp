#include "./../Includes/Rail.hpp"

Rail::Rail(Node *a, Node *b, float lenght) : _a(a), _b(b), _lenght(lenght), _maxSpeed(200) {
    RailList *lst = RailList::getInstance();
    lst->add(this);
}

Node *Rail::getStart() {
    return(this->_a);
}

Node *Rail::getArrival() {
    return(this->_b);
}

float   Rail::getLenght() {
    return(this->_lenght);
}

float   Rail::getSpeed() {
    return(this->_maxSpeed);
}