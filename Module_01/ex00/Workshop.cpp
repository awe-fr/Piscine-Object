#include "Workshop.hpp"

Workshop::Workshop() {
    std::cout << "Workshop constructor" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructor" << std::endl;
}

void    Workshop::executeWorkDay() {
    if (this->_workers.empty() == true) {
        std::cout << "Nobody in the workshop" << std::endl;
    }
    else {
        for (int i = this->_workers.size(); i > 0; i--) {
            this->_workers[i - 1]->work();
        }
    }
}

void    Workshop::hire(Worker *worker) {
    if (worker != NULL) {
        std::cout << "Worker hired" << std::endl;
        this->_workers.push_back(worker);
        worker->hire();
    }
}

void    Workshop::fire(Worker *worker) {
    if (worker != NULL) {
        for (int i = this->_workers.size(); i > 0; i--) {
            if (this->_workers[i - 1] == worker) {
                std::cout << "Worker fired" << std::endl;
                this->_workers[i - 1]->fire();
                this->_workers.erase (this->_workers.begin() + i - 1);
                break;
            }
        }
    }

}