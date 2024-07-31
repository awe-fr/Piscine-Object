#include "./../Includes/Train.hpp"

Train::Train(std::string name, Node *a, Node *b, float acc, float brake, float departure) : _name(name) , _departure(a), _arrival(b), _maxAcceleration(acc), _maxBrakeForce(brake), _departureHour(departure), _status("Starting"), _speed(0), _traveled(0) {
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

float Train::getAcc() {
	return (this->_maxAcceleration);
}

float Train::getBrake() {
	return (this->_maxBrakeForce);
}

int Train::railNumber() {
	return (this->_path.size());
}

float Train::railLenght() {
	float lenght = 0;
	for (int i = 0; i < _path.size(); i++) {
		lenght += this->_path[i]->getLenght();
	}
	return lenght;
}

float Train::getSpeed() {
	return this->_speed;
}

std::string Train::getStatus() {
	return this->_status;
}

void Train::setStatus(std::string status) {
	this->_status = status;
}

float Train::getHour() {
	return this->_departureHour;
}

Rail *Train::getRail() {
	return (this->_path[this->_path.size() - 1]);
}

float Train::getTraveled() {
	return (this->_traveled);
}

void Train::setTraveled(float value) {
	this->_traveled = value;
}

void Train::setSpeed(float value) {
	this->_speed = value;
}