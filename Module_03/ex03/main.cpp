#include "employee.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
#include "employeeManagement.hpp"

int main() {
    EmployeeManager *manager = new EmployeeManager;

    for(int i = 0; i < 10; i++)
        manager->executeWorkday();

    Employee E1(12);
    TempWorker E2(15, 4);
    ContractEmployee E3(21, 1);
    Apprentice E4(4, 1);

    manager->addEmployee(&E1);
    manager->addEmployee(&E2);
    manager->addEmployee(&E3);
    manager->addEmployee(&E4);

    for(int i = 0; i < 20; i++)
        manager->executeWorkday();

    for(int i = 0; i < 10; i++)
        manager->executeWorkday();

    manager->removeEmployee(&E1);
    manager->removeEmployee(&E2);
    manager->removeEmployee(&E3);
    manager->removeEmployee(&E4);
}