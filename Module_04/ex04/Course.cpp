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

void Course::unsub(Student *stud) {
    for (int i = this->_students.size(); i > 0; i--) {
        if (this->_students[i - 1] == stud) {
            this->_students[i - 1] = nullptr;
        }
    }
}

void Course::studTakeNote() {
    for (int i = this->_students.size(); i > 0; i--) {
        this->_students[i - 1]->takeNote();
    }
}

Subject::Subject() {
    ProfessorList *prf = ProfessorList::getInstance();
    StudentList *std = StudentList::getInstance();
    this->lst1 = std->getList();
    this->lst2 = prf->getList();
}

void Subject::ping(Event event, bool p) {
    if (p == false) {
        if (event == Event::RingBell) {
            for (int i = lst1->size(); i > 0; i--) {
                if ((* lst1)[i - 1] != nullptr)
                    (* lst1)[i - 1]->alert(" go on break");
            }
            for (int i = lst2->size(); i > 0; i--) {
                if ((* lst2)[i - 1] != nullptr)
                    (* lst2)[i - 1]->alert(" go on break");
            }
        }
    }
    else {
        if (event == Event::RingBell) {
            for (int i = lst1->size(); i > 0; i--) {
                if ((* lst1)[i - 1] != nullptr)
                    (* lst1)[i - 1]->alert(" stop the break");
            }
            for (int i = lst2->size(); i > 0; i--) {
                if ((* lst2)[i - 1] != nullptr)
                    (* lst2)[i - 1]->alert(" stop the break");
            }
        }
    }
}