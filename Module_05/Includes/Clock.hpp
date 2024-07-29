#pragma once

#include<unistd.h>

class Clock {
    private:
        int _hour;
    public:
        Clock();
        int getHour();
        void passTime();
};