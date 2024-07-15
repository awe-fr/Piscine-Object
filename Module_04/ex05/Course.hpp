#pragma once

class Student;
class Professor;
enum class Event;

#include "Person.hpp"
#include "Form.hpp"

class Course
{
    private:
        std::string _name;
        Professor* _responsable;
        std::vector<Student*> _students;
    public:
        Course(std::string p_name) : _name(p_name), _responsable(nullptr) {};
        void assign(Professor* p_professor);
        void subscribe(Student* p_student);
        void unsub(Student *stud);
        void studTakeNote();
        std::string getName() {return _name;};
        Professor* getRes() {if (_responsable != nullptr) {return _responsable;} return nullptr;};
        std::vector<Student*> getStud() {return(this->_students);};
};