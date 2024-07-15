#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "School.hpp"

int main () {

    School *school = new School();
    school->recruteProfessor();
    school->recruteProfessor();
    school->recruteStudent();
    school->recruteStudent();
    school->recruteStudent();
    school->launchClasses();

    std::cout << "------------------" << std::endl;

    std::vector<Professor *> lst1 = school->getProfessors();
    lst1[0]->fillCourse("Math");
    lst1[1]->fillCourse("Math mais plus dure");
    std::vector<Student *> lst2 = school->getStudents();
    lst2[0]->fill(school->getCourse("Math"));
    lst2[1]->fill(school->getCourse("Math mais plus dure"));
    lst2[2]->fill(school->getCourse("Math"));
    
    std::cout << "------------------" << std::endl;

    school->runDayRoutine();

    std::cout << "------------------" << std::endl;

    school->graduationCeremony();

    std::cout << "------------------" << std::endl;

    ProfessorList *ex1 = ProfessorList::getInstance();
    StudentList *ex2 = StudentList::getInstance();
    RoomList *ex3 = RoomList::getInstance();
    CourseList *ex4 = CourseList::getInstance();

    ex1->cleanup();
    ex2->cleanup();
    ex3->cleanup();
    ex4->cleanup();

    delete ex1;
    delete ex2;
    delete ex3;
    delete ex4;

    std::cout << "------------------" << std::endl;

    delete school;

}