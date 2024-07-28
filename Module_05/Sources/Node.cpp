#include "./../Includes/Node.hpp"

Node::Node(std::string name) : _name(name) {
    NodeList *lst = NodeList::getInstance();
    lst->add(this);
}

std::string Node::getName() const {
    return(this->_name);
}