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
}

void Simulation::printEstimateTime() {
    for (int i = 0; i < this->_trains.size(); i++) {
		float vmax = this->_rails[0]->getSpeed() / 3.6;
		float meter = 0;
		int sec = 0;
		for (float start = this->_trains[i]->getSpeed(); start < vmax; start += this->_trains[i]->getSpeed()) {
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
		int time = (((this->_trains[i]->railLenght() - (meter / 1000) - (meter2 / 1000)) / this->_rails[0]->getSpeed()) * 100) + min + min2;
        std::cout << "Train : " << this->_trains[i]->getName() << std::endl;
		std::cout << "Estimated optimal travel time : " << time / 60 << "h" << time % 60 << "m" << std::endl;
		std::cout << std::endl;
    }
}

void Simulation::StartSimulation() {
	printEstimateTime();
}