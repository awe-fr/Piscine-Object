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
    case FormType::Graduate:
        ret = new GraduateForm();
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
    else
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

void Headmaster::askFormnewCourse(FormType p_formType, Professor *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((TeachCourseForm *)toRet);
}

void Headmaster::askFormGraduate(FormType p_formType, Professor *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((GraduateForm *)toRet);
}

void Professor::formrcv(TeachCourseForm *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Student::formrcv(Form *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Professor::formrcv(GraduateForm *ret) {
    if (this->_waitFillGrad != nullptr)
        delete this->_waitFillGrad;
    this->_waitFillGrad = ret;
}

void Professor::fillCourse(Course *course) {
    if (_waitFill != nullptr) {
        Headmaster master("thiery");
        FillTeachCourseForm fill(this->_waitFill, course, this);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFill);
        master.exec();
    }
}

void Professor::fillGrad(Course *course, Student *stud) {
    if (_waitFillGrad != nullptr) {
        Headmaster master("thiery");
        FillGraduateForm fill(this->_waitFillGrad, course, stud);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFillGrad);
        master.exec();
    }
}

void Student::fill() {

}

void Professor::doClass() {
    if (this->_currentCourse != nullptr) {
        std::cout << this->_name << " is teaching " << this->_currentCourse->getName() << std::endl;
    }
    else
        std::cout << this->_name << " didn't have course to teach" << std::endl;
} 

void Professor::askCourse() {
    if (this->_currentCourse == nullptr) {
        Headmaster master("thiery");
        master.askFormnewCourse(FormType::TeachCourse, this);
    }
}

void Professor::askGraduate() {
    Headmaster master("thiery");
    master.askFormGraduate(FormType::Graduate, this);
}

Professor::~Professor() {
    if (this->_waitFill != nullptr)
        delete _waitFill;
    if (this->_waitFillGrad != nullptr)
        delete _waitFillGrad;
}

Professor::Professor(std::string name) : Staff(name), _currentCourse(nullptr), _waitFill(nullptr), _waitFillGrad(nullptr) {};

void Student::graduate(Course* p_course) {
    for (int i = this->_subscribedCourse.size(); i > 0; i--) {
        if (this->_subscribedCourse[i - 1] == p_course) {
            p_course->unsub(this);
            this->_subscribedCourse[i - 1] = nullptr;
        }
    }
}