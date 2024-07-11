#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"

int main () {
    Secretary sec("Catherine");
    Headmaster hed("Didier");
    Professor prof("Seb");
    prof.askCourse();
    prof.fillCourse("Math");
    prof.doClass();
    CourseList *ex1 = CourseList::getInstance();
    RoomList *ex2 = RoomList::getInstance();
    std::vector<Course *> *lst = ex1->getList();

    std::cout << "------------------" << std::endl;

    Student *stud = new Student("Paul");
    stud->joinAsk();
    stud->fill((*lst)[0]);
    prof.doClass();
    
    std::cout << "------------------" << std::endl;
    
    prof.askGraduate();
    prof.fillGrad((*lst)[0], stud);

    std::cout << "------------------" << std::endl;

    ex1->cleanup();
    ex2->cleanup();
    delete ex1;
    delete ex2;
    delete stud;
}