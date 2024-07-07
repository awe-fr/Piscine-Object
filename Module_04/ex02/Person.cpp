#include "Person.hpp"

Form* Secretary::createForm(FormType p_formType) {
    Form *ret = nullptr;
    switch (p_formType)
    {
    case FormType::CourseFinished:
        ret = new CourseFinishedForm();
        return ret;
        break;
    case FormType::NeedMoreClassRoom:
        ret = new NeedMoreClassRoomForm();
        return ret;
        break;
    case FormType::NeedCourseCreation:
        ret = new NeedCourseCreationForm();
        return ret;
        break;
    case FormType::SubscriptionToCourse:
        ret = new SubscriptionToCourseForm();
        return ret;
        break;
    default:
        return nullptr;
        break;
    }
}

void Student::sub(Course *course) {
    if (course != nullptr) {
        this->_subscribedCourse.push_back(course);
        std::cout << "Student Subscibe to a new Course" << std::endl;
    }
}

void Professor::assignCourse(Course* p_course) {
    if (p_course != nullptr && this->_currentCourse == nullptr) {
        this->_currentCourse = p_course;
        std::cout << "Professor teaching new course" << std::endl;
    }
    std::cout << "Professor already have a course" << std::endl;
}

void Headmaster::receiveForm(Form* p_form) {
    this->_formToValidate.push_back(p_form);
}

void Headmaster::exec() {
    for (unsigned long int i = 0; i < this->_formToValidate.size(); i++) {
        this->_formToValidate[i]->execute();
    }
    this->_formToValidate.clear();
}