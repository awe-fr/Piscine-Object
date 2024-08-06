#include "./../Includes/Simulation.hpp"

Simulation::Simulation() {
    TrainList *plst1 = TrainList::getInstance();
    std::vector<Train *> *lst1 = plst1->getList();
    this->_trains = *lst1;
    EventList *plst2 = EventList::getInstance();
    std::vector<Event *> *lst2 = plst2->getList();
    this->_events = *lst2;
    RailList *plst3 = RailList::getInstance();
    std::vector<Rail *> *lst3 = plst3->getList();
    this->_rails = *lst3;
    NodeList *plst4 = NodeList::getInstance();
    std::vector<Node *> *lst4 = plst4->getList();
    this->_nodes = *lst4;
	this->_clock = new Clock();
	for (int i = 0; i < this->_trains.size(); i++) {
		this->_files.push_back(new std::ofstream(this->_trains[i]->getName().c_str()));
	}
}

Simulation::~Simulation() {
	delete this->_clock;
}

void Simulation::printEstimateTime() {
    for (int i = 0; i < this->_trains.size(); i++) {
		float vmax = this->_rails[0]->getSpeed() / 3.6;
		float meter = 0;
		int sec = 0;
		for (float start = this->_trains[i]->getAcc(); start < vmax; start += this->_trains[i]->getAcc()) {
			sec += 1;
			meter += start;
		}
		float meter2 = 0;
		int sec2 = 0;
		for (float start = this->_trains[i]->getBrake(); start < vmax; start += this->_trains[i]->getBrake()) {
			sec2 += 1;
			meter2 += start;
		}
		sec *= this->_trains[i]->railNumber();
		sec2 *= this->_trains[i]->railNumber();
		int min = sec / 60;
		int min2 = sec2 / 60;
		int time = (((this->_trains[i]->railLenght() - (((meter / 1000) - (meter2 / 1000)) * this->_trains[i]->railNumber())) / this->_rails[0]->getSpeed()) * 100) + min + min2;
		*this->_files[i] << "Train : " << this->_trains[i]->getName() << std::endl;
		*this->_files[i] << "Estimated optimal travel time : " << time / 100 << "h" << ((time % 100) * 60) / 100 << "m" << std::endl;
		*this->_files[i] << std::endl; 
    }
}

void Simulation::exec() {
	while (!this->_trains.empty()) {
		for (int i = 0; i < this->_trains.size(); i++) {
			if (this->_trains[i]->getStatus() == "Starting" && this->_clock->getHour() == this->_trains[i]->getHour()) {
					printTrainStatus(i);
					this->_trains[i]->setStatus("Speed up");
			}
			if (this->_trains[i]->getStatus() == "Speed up") {
				float tmpSpeed = this->_trains[i]->getSpeed() / 3.6;
				float vmax = this->_rails[0]->getSpeed() / 3.6;
				float mtr = this->_trains[i]->getTraveled() * 1000;
				for (int y = 0; y < 60; y++) {
					if (tmpSpeed < vmax)
						tmpSpeed += this->_trains[i]->getAcc();
					else if (tmpSpeed > vmax)
						tmpSpeed = vmax;
					mtr += tmpSpeed;
					if (this->_trains[i]->getRail()->getLenght() - (mtr / 1000) <= getTimeToStop(this->_trains[i], tmpSpeed) / 1000) {
						this->_trains[i]->setTraveled(mtr / 1000);
						this->_trains[i]->setSpeed(tmpSpeed * 3.6);
						this->_trains[i]->setStatus("Braking");
						break;
					}
				}
				if (tmpSpeed == vmax) {
					this->_trains[i]->setStatus("Maintain");

				}
				this->_trains[i]->setTraveled(mtr / 1000);
				this->_trains[i]->setSpeed(tmpSpeed * 3.6);
			}
			else if (this->_trains[i]->getStatus() == "Maintain") {
				float tmpSpeed = this->_trains[i]->getSpeed() / 3.6;
				float mtr = this->_trains[i]->getTraveled() * 1000;
				for (int y = 0; y < 60; y++) {
					mtr += tmpSpeed;
					if (this->_trains[i]->getRail()->getLenght() - (mtr / 1000) <= getTimeToStop(this->_trains[i], tmpSpeed) / 1000) {
						this->_trains[i]->setTraveled(mtr / 1000);
						this->_trains[i]->setStatus("Braking");
						break;
					}
				}
				this->_trains[i]->setTraveled(mtr / 1000);
			}
			else if (this->_trains[i]->getStatus() == "Braking") {
				float tmpSpeed = this->_trains[i]->getSpeed() / 3.6;
				float mtr = this->_trains[i]->getTraveled() * 1000;
				for (int y = 0; y < 60; y++) {
					if (this->_trains[i]->getRail()->getLenght() - (mtr / 1000) < 0) {
						mtr = this->_trains[i]->getRail()->getLenght() * 1000;
					}
					if (this->_trains[i]->getRail()->getLenght() - (mtr / 1000) == 0) {
						this->_trains[i]->setTraveled(mtr / 1000);
						this->_trains[i]->setSpeed(0);
						this->_trains[i]->setStatus("Stopped");
						break;
					}
					mtr += tmpSpeed;
					if (tmpSpeed * 3.6 > 10)
						tmpSpeed -= this->_trains[i]->getBrake();
					else if (tmpSpeed * 3.6 < 10)
						tmpSpeed = 10 / 3.6;
				}
				this->_trains[i]->setTraveled(mtr / 1000);
				this->_trains[i]->setSpeed(tmpSpeed * 3.6);
			}
			if (this->_trains[i]->getStatus() == "Stopped") {
				if (this->_trains[i]->changeRail() == 1) {
					this->_trains[i]->setTraveled(0);
					if (this->_trains[i]->loadEvent(this->_trains[i]->getRail()->getStart(), this->_events, this->_files[i]) == 1)
						this->_trains[i]->setStatus("Event");
					else
						this->_trains[i]->setStatus("Speed up");
				}
			}
			else if (this->_trains[i]->getStatus() == "Event") {
				this->_trains[i]->subTime();
				if (this->_trains[i]->getTime() == 0)
					this->_trains[i]->setStatus("Speed up");
			}
		}
		for (int i = 0; i < this->_trains.size(); i++) {
			if (this->_trains[i]->getStatus() == "Stopped") {
				for (int z = this->_trains.size(); z > 0; z--) {
					if (this->_trains[z - 1] == this->_trains[i]) {
						printTrainStatus(i);
						this->_trains.erase(this->_trains.begin() + z - 1);
						this->_files[z - 1]->close();
						delete this->_files[z - 1];
						this->_files.erase(this->_files.begin() + z - 1);
					}
				}
			}
		}
		for (int i = 0; i < this->_trains.size(); i++) {
			if (this->_clock->getHour() % 5 == 0 && this->_trains[i]->getStatus() != "Starting") {
				printTrainStatus(i);
			}
		}
		this->_clock->passTime();
	}
}

void Simulation::StartSimulation() {
	printEstimateTime();
	exec();
}

void Simulation::printTrainStatus(int i) {
	*this->_files[i] << "[" << this->_clock->getHour() / 100 << "h" << this->_clock->getHour() % 100 << "] - [";
	*this->_files[i] << this->_trains[i]->getName() << "] - [";
	*this->_files[i] << this->_trains[i]->getRail()->getStart()->getName() << "][" << this->_trains[i]->getRail()->getArrival()->getName() << "] - [";
	*this->_files[i] << this->_trains[i]->getRail()->getLenght() - this->_trains[i]->getTraveled() << "km] - [";
	*this->_files[i] << this->_trains[i]->getStatus() << "] - ";
	*this->_files[i] << this->_trains[i]->getRail()->getTrafic(this->_trains[i]);
	*this->_files[i] << std::endl;
}

float Simulation::getTimeToStop(Train *train, float speed) {
	float brakeForce = train->getBrake();
	float mtr = 0;
	while(speed > 0) {
		mtr += speed;
		speed -= brakeForce;
	}
	return mtr;
}