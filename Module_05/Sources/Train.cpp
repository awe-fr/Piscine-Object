#include "./../Includes/Train.hpp"

Train::Train(std::string name, Node *a, Node *b, float acc, float brake, float departure) : _name(name) , _departure(a), _arrival(b), _maxAcceleration(acc), _maxBrakeForce(brake), _departureHour(departure), _status("Starting"), _speed(0), _traveled(0), _time(0) {
    TrainList *lst = TrainList::getInstance();
    lst->add(this);
	this->_id = lst->getList()->size();
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

int Train::changeRail() {
	if (this->_path.size() > 1) {
		this->_path.pop_back();
		return 1;
	}
	return 0;
}

int Train::loadEvent(Node *node, std::vector<Event *> events) {
	std::vector<Event *> lst;
	int ret = 0;
	for (int i = 0; i < events.size(); i++) {
		if (events[i]->getLoc()->getName() == node->getName()) {
			lst.push_back(events[i]);
		}
	}
	std::srand(time(0));
	for (int i = 0; i < lst.size(); i++) {
		int prob = 1 / lst[i]->getProb();
		int num = std::rand();
		if (num % prob == 0) {
			if (this->_time < lst[i]->getTime()) {
				this->_time = lst[i]->getTime();
			}
			std::cout << "[" << this->_name << "] trigger a " << lst[i]->getReason() << " in " << node->getName() << " train stopped for " << this->_time << " minutes"<< std::endl;
			ret = 1;
		}
	}
	return ret;
}

float Train::getTime() {
	return this->_time;
}

void Train::subTime() {
	this->_time -= 1;
}