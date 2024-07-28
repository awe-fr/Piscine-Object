#pragma once

#include <iostream>

#include "Singleton.hpp"

class Node {
    private:
        std::string _name;
    public:
        Node(std::string name);
        std::string getName() const;
};