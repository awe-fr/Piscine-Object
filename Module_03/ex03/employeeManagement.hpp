#pragma once

class Employee;

class IEmployeeManagement {
    public:
        virtual void    addEmployee(Employee *) = 0;
        virtual void    removeEmployee(Employee *) = 0;
};