#include "./../Includes/Train.hpp"

Train::Train(std::string name, Node *a, Node *b, float acc, float brake, float departure) : _name(name) , _departure(a), _arrival(b), _maxAcceleration(acc), _maxBrakeForce(brake), _departureHour(departure) {
    TrainList *lst = TrainList::getInstance();
    lst->add(this);
}

Node *Train::getDeparture() {
    return(this->_departure);
}


Node *Train::getArrival() {
    return(this->_arrival);
}