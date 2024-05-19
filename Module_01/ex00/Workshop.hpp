#pragma once

class Worker;

#include "Worker.hpp"
#include <vector>

class Workshop {
    private:
        std::vector<Worker *> _workers;
    public:
        Workshop();
        ~Workshop();
        void    executeWorkDay();
        void    hire(Worker *worker);
        void    fire(Worker *worker);
};