#pragma once

class Workshop;
class Tool;

#include "Workshop.hpp"
#include "Tool.hpp"
#include <iostream>
#include <cstddef>

typedef struct s_pos
{
    int x;
    int y;
    int z;
}   Position;

typedef struct s_stat
{
    int level;
    int exp;
}   Statistic;


class Worker {
    private:
        Statistic   _stat;
        Position    _coordonnee;
        Tool        *_tool[4];
        int        _status;
    public:
        Worker();
        ~Worker();
        void    grab(Tool *shovel);
        void    drop(int place);
        void    use(int place);
        void    print();
        void    hire();
        void    fire();
        void    work();
};