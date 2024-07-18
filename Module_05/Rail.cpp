#include "Rail.hpp"

Rail::Rail(Node *a, Node *b, float lenght) : _a(a), _b(b), _lenght(lenght) {
    RailList *lst = RailList::getInstance();
    lst->add(this);
}