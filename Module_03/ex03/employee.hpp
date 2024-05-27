#pragma once

#include "employeeManagement.hpp"
#include "salariedEmployee.hpp"
#include "hourlyEmployee.hpp"

#include <iostream>
#include <cstddef>
#include <vector>

class Employee : public IHourlyEmployee{
    protected:
        int hourlyValue;
    public:
        Employee(int price) : hourlyValue(price) {};
        int executeWorkday() {
            std::cout << "Employee working" << std::endl;
            return 7;
        };
        virtual int getPrice() {return (this->hourlyValue);};
};

class TempWorker : public Employee{
    private:
        int hoursOfWork;
    public:
        TempWorker(int price, int worktime) : Employee(price), hoursOfWork(worktime) {
            if (this->hoursOfWork > 24)
                this->hoursOfWork = 24;
        };
        int executeWorkday() {
            std::cout << "Temp employee working" << std::endl;
            return this->hoursOfWork;
        };
        int getPrice() {return (this->hourlyValue);}
};

class ContractEmployee : public Employee{
    private:
        int hoursoff;
    public:
        ContractEmployee(int price, int workoff) : Employee(price), hoursoff(workoff) {
            if (this->hoursoff > 7)
                this->hoursoff = 7;
        };
        int executeWorkday() {
            std::cout << "Contract employee working" << std::endl;
            return 7 - this->hoursoff;
        };
        int getPrice() {return (this->hourlyValue);}
};

class Apprentice : public Employee{
    private:
        int hoursoff;
        int dayLeftBeforePostChange;
        bool half;
    public:
        Apprentice(int price, int workoff) : Employee(price), hoursoff(workoff) {
            if (this->hoursoff > 7)
                this->hoursoff = 7;
            this->dayLeftBeforePostChange = 7;
            this->half = false;
        };
        int executeWorkday() {
            if (dayLeftBeforePostChange == 0) {
                dayLeftBeforePostChange = 7;
                if (this->half == true) {
                    this->hourlyValue *= 2;
                    this->half = false;
                }
                else {
                    this->hourlyValue /= 2;
                    this->half = true;
                }
            }
            if (this->half == false)
                std::cout << "Apprentice employee working" << std::endl;
            else
                std::cout << "Apprentice employee studying" << std::endl;
            this->dayLeftBeforePostChange--;
            return 7 - this->hoursoff;
        };
        int getPrice() {return (this->hourlyValue);}
};

class EmployeeManager : public IHourlyEmployeeM, public ISalariedEmployee, public IEmployeeManagement {
    private:
        std::vector<Employee *> employee;
        std::vector<float>      toPay;
    public:
        EmployeeManager() {};
        void    executeWorkday() {
            static int monthDay = 0;
            std::cout << "Manager working" << std::endl;
            for (int i = this->employee.size(); i > 0; i--) {
                this->toPay[i - 1] += (this->employee[i - 1]->executeWorkday() * this->employee[i - 1]->getPrice());
            }
            monthDay++;
            if (monthDay == 30) {
                calculatePayroll();
                monthDay = 0;
            }
        };
        void    calculatePayroll() {
            for (int i = this->employee.size(); i > 0; i--) {
                std::cout << "Employee paid : " << this->toPay[i - 1] << std::endl;
                this->toPay[i - 1] = 0;
            }
        };
        void    addEmployee(Employee *e) {
            if (e != NULL) {
                this->employee.push_back(e);
                this->toPay.push_back(0);
                std::cout << "Employee recruted" << std::endl;
            }
            else
                std::cout << "Employee cannot be recruted" << std::endl;
        };
        void    removeEmployee(Employee *e) {
            if (e != NULL) {
                for (int i = this->employee.size(); i > 0; i--) {
                    if (e == this->employee[i - 1]){
                        std::cout << "Employee paid : " << this->toPay[i - 1] << std::endl;
                        this->toPay[i - 1] = 0;
                        this->employee.erase (this->employee.begin() + i - 1);
                        this->toPay.erase (this->toPay.begin() + i - 1);
                        std::cout << "Employee fired" << std::endl;
                        return;
                    }
                }
            }
            std::cout << "Employee cannot be fired" << std::endl;
        };
};

