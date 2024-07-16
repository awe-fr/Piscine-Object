#pragma once

#include "Node.hpp"

class Event {
    private:
        std::string _reason;
        Node        *_location;
        int         _probability;
        int         _time;
    public:
        Event(std::string reason, Node *location, int prob, int time);
};