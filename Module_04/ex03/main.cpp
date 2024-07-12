#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"

int main () {
    Secretary sec("Catherine");
    Headmaster hed("Didier");
    Professor *prof = new Professor("Seb");
    
    hed.attendClasses();
    prof->fillCourse("Math");
    
    CourseList *ex1 = CourseList::getInstance();
    RoomList *ex2 = RoomList::getInstance();
    ProfessorList *ex3 = ProfessorList::getInstance();
    StudentList *ex4 = StudentList::getInstance();
    std::vector<Course *> *lst = ex1->getList();

    std::cout << "------------------" << std::endl;

    Student *stud = new Student("Paul");
    hed.attendClasses();
    stud->fill((*lst)[0]);
    hed.attendClasses();
    
    std::cout << "------------------" << std::endl;
    
    prof->askGraduate();
    prof->fillGrad((*lst)[0], stud);

    std::cout << "------------------" << std::endl;

    ex1->cleanup();
    ex2->cleanup();
    ex3->cleanup();
    ex4->cleanup();
    delete ex1;
    delete ex2;
    delete ex3;
    delete ex4;
}