#include "./../Includes/Rail.hpp"

Rail::Rail(Node *a, Node *b, float lenght) : _a(a), _b(b), _lenght(lenght) {
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