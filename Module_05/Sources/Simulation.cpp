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
        std::cout << "Train : " << this->_trains[i]->getName() << std::endl;
		std::cout << "Estimated optimal travel time : " << time / 100 << "h" << ((time % 100) * 60) / 100 << "m" << std::endl;
		std::cout << std::endl; 
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
				}
				if (tmpSpeed == vmax) {
					this->_trains[i]->setStatus("Maintain");

				}
				this->_trains[i]->setTraveled(mtr / 1000);
				this->_trains[i]->setSpeed(tmpSpeed * 3.6);
			}
			if (this->_trains[i]->getStatus() == "Maintain") {
				float tmpSpeed = this->_trains[i]->getSpeed() / 3.6;
				float mtr = this->_trains[i]->getTraveled() * 1000;
				for (int y = 0; y < 60; y++) {
					mtr += tmpSpeed;
				}
				this->_trains[i]->setTraveled(mtr / 1000);
			}
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
	std::cout << "[" << this->_clock->getHour() / 100 << "h" << this->_clock->getHour() % 100 << "] - [";
	std::cout << this->_trains[i]->getRail()->getStart()->getName() << "][" << this->_trains[i]->getRail()->getArrival()->getName() << "] - [";
	std::cout << this->_trains[i]->getRail()->getLenght() - this->_trains[i]->getTraveled() << "km] - [";
	std::cout << this->_trains[i]->getStatus() << "] - ";
	std::cout << this->_trains[i]->getRail()->getTrafic(this->_trains[i]);
	std::cout << std::endl;
}