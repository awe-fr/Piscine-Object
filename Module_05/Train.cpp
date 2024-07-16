#include "Train.hpp"

Train::Train(std::string name, Node *a, Node *b, int acc, int brake, int departure) : _name(name) , _departure(a), _arrival(b), _maxAcceleration(acc), _maxBrakeForce(brake), _departureHour(departure) {

}