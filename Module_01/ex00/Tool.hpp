#pragma once

class Worker;

#include "Worker.hpp"
#include <iostream>
#include <cstddef>

class Tool {
    protected:
        std::string _type;
        Worker *_worker;
        int _numberOfUses;
        int _place;
    public:
        Tool();
        virtual ~Tool();
        virtual void    removeUser();
        virtual void    changeUser(Worker *worker);
        virtual void    setPlace(int num);
        virtual int     getPlace();
        virtual void    use() = 0;  
};