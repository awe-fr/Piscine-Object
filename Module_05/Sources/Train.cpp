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

void Train::addSegment(Rail *rail) {
    this->_path.push_back(rail);
}

std::string Train::getName() {
    return (this->_name);
}

float Train::getSpeed() {
	return (this->_maxAcceleration);
}

float Train::getBrake() {
	return (this->_maxBrakeForce);
}

int Train::railNumber() {
	return (this->_path.size());
}

float Train::railLenght() {
	float lenght;
	for (int i = 0; i < _path.size(); i++) {
		lenght += this->_path[i]->getLenght();
	}
	return lenght;
}