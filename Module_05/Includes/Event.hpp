#pragma once

#include "Node.hpp"

class Node;

class Event {
    private:
        std::string _reason;
        Node        *_location;
        float       _probability;
        float       _time;
    public:
        Event(std::string reason, Node *location, float prob, float time);
};