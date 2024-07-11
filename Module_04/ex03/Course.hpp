#pragma once

class Student;
class Professor;

#include "Person.hpp"

class Course
{
    private:
        std::string _name;
        Professor* _responsable;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
    public:
        Course(std::string p_name) : _name(p_name), _responsable(nullptr) {};
        void assign(Professor* p_professor);
        void subscribe(Student* p_student);
        void unsub(Student *stud);
        std::string getName() {return _name;};
};