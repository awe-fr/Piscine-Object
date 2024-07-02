#include "Form.hpp"

void NeedMoreClassRoomForm::execute() {
    std::vector<Classroom *> list =  this->_classrooms->getList();
    if (list.size() < 10) {
        std::cout << "More classroom needed" << std::endl;
        Classroom *newclass = new Classroom();
        this->_classrooms->add(newclass);
        std::cout << "Classroom added" << std::endl;
    }
    else {
        std::cout << "No more classroom needed" << std::endl;
    }
}

void NeedCourseCreationForm::execute(std::string name) {
    Course *newcourse = new Course(name);
    this->_courses->add(newcourse);
    std::cout << "New course added" << std::endl;
}