#include "./../Includes/Event.hpp"

Event::Event(std::string reason, Node *location, float prob, float time) : _reason(reason), _location(location), _probability(prob), _time(time) {
    EventList *lst = EventList::getInstance();
    lst->add(this);
}