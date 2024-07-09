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
    case FormType::TeachCourse:
        ret = new TeachCourseForm();
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
        std::cout << i << std::endl;
    }
    this->_formToValidate.clear();
}

void Headmaster::askForm(FormType p_formType, Person *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv(toRet);
}

void Professor::formrcv(Form *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Student::formrcv(Form *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Professor::fill(Course *course) {
    if (_waitFill != nullptr) {
        Headmaster master("thiery");
        FillTeachCourseForm fill(this->_waitFill, course, this);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFill);
        master.exec();
    }
}

void Student::fill() {

}