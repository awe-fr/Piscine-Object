#pragma once

class IHourlyEmployee {
    public:
        virtual int    executeWorkday() = 0;
};

class IHourlyEmployeeM {
    public:
        virtual void    executeWorkday() = 0;
};