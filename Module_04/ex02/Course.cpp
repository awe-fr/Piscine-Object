#include "Course.hpp"

void Course::assign(Professor* p_professor) {
    if (p_professor != nullptr) {
        if(this->_responsable == nullptr) {
            this->_responsable = p_professor;
            std::cout << "New professor try to be added to the course" << std::endl;
            p_professor->assignCourse(this);
        }
        else {
            std::cout << "A professor is already teaching that course" << std::endl;
        }
    }
}

void Course::subscribe(Student* p_student) {
    if (p_student != nullptr) {
        p_student->sub(this);
        this->_students.push_back(p_student);
        std::cout << "Student added to the course" << std::endl;
    }
}