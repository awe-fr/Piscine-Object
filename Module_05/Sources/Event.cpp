#include "./../Includes/Event.hpp"

Event::Event(std::string reason, Node *location, float prob, float time) : _reason(reason), _location(location), _probability(prob), _time(time) {
    EventList *lst = EventList::getInstance();
    lst->add(this);
}

std::string Event::getReason() {
    return this->_reason;
}

Node *Event::getLoc() {
    return this->_location;
}

float Event::getProb() {
    return this->_probability;
}

float Event::getTime() {
    return this->_time;
}