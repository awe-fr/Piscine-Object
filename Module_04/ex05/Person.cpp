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

void Headmaster::askFormnewRoom(FormType p_formType, Professor *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((NeedMoreClassRoomForm *)toRet);
}

void Headmaster::askFormnewCourse(FormType p_formType, Professor *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((NeedCourseCreationForm *)toRet);
}

void Headmaster::askFormGraduate(FormType p_formType, Professor *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((GraduateForm *)toRet);
}

void Professor::formrcv(NeedMoreClassRoomForm *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFillRoom;
    this->_waitFillRoom = ret;
}

void Professor::formrcv(NeedCourseCreationForm *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Student::formrcv(SubscriptionToCourseForm *ret) {
    if (this->_waitFill != nullptr)
        delete this->_waitFill;
    this->_waitFill = ret;
}

void Professor::formrcv(GraduateForm *ret) {
    if (this->_waitFillGrad != nullptr)
        delete this->_waitFillGrad;
    this->_waitFillGrad = ret;
}

void Professor::fillCourse(std::string name) {
    if (_waitFill != nullptr) {
        Headmaster master("thiery");
        FillNeedCourseCreationForm fill(this->_waitFill, name, this);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFill);
        master.exec();
    }
}

void Professor::fillRoom() {
    if (_waitFillRoom != nullptr) {
        Headmaster master("thiery");
        RoomList *ex1 = RoomList::getInstance();
        std::vector<Room *> *lst = ex1->getList();
        FillNeedMoreClassRoomForm fill(this->_waitFillRoom, lst->size() + 1);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFillRoom);
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

void Student::fill(Course *course) {
    if (_waitFill != nullptr) {
        Headmaster master("thiery");
        FillSubscriptionToCourseForm fill(this->_waitFill, course, this);
        master.receiveForm(&fill);
        master.receiveForm(this->_waitFill);
        master.exec();
    }
}

void Professor::doClass() {
    if (this->_currentCourse == nullptr) {
        this->askCourse();
        return;
    }
    if (this->_currentRoom == nullptr && this->_currentCourse != nullptr) {
        askRoom();
        fillRoom();
        RoomList *ex1 = RoomList::getInstance();
        std::vector<Room *> *lst = ex1->getList();
        Classroom * cla = (Classroom *)(* lst)[lst->size() - 1];
        this->_currentRoom = cla;
        cla->assignCourse(this->_currentCourse);
    }
    if (this->_currentCourse != nullptr) {
        std::cout << this->_name << " is teaching " << this->_currentCourse->getName() << std::endl;
        this->_currentCourse->studTakeNote();
    }
    else
        std::cout << this->_name << " didn't have course to teach" << std::endl;
} 

void Professor::askRoom() {
    if (this->_currentRoom == nullptr) {
        Headmaster master("thiery");
        master.askFormnewRoom(FormType::NeedMoreClassRoom, this);
    }
}

void Professor::askCourse() {
    if (this->_currentCourse == nullptr) {
        Headmaster master("thiery");
        master.askFormnewCourse(FormType::NeedCourseCreation, this);
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
    if (this->_waitFillRoom != nullptr)
        delete _waitFillRoom;
}

Professor::Professor(std::string name) : Staff(name), _currentCourse(nullptr), _waitFill(nullptr), _waitFillGrad(nullptr), _waitFillRoom(nullptr) {
    ProfessorList *lst = ProfessorList::getInstance();
    lst->add(this);
};

void Student::graduate(Course* p_course) {
    for (int i = this->_subscribedCourse.size(); i > 0; i--) {
        if (this->_subscribedCourse[i - 1] == p_course) {
            p_course->unsub(this);
            this->_subscribedCourse[i - 1] = nullptr;
        }
    }
}

void Student::takeNote() {
    std::cout << "Student take note" << std::endl;
}

void Student::joinAsk() {
    Headmaster master("thiery");
    master.askFormjoinCourse(FormType::SubscriptionToCourse, this);
}

void Headmaster::askFormjoinCourse(FormType p_formType, Student *asked) {
    Secretary sec("Catoch");
    Form *toRet = sec.createForm(p_formType);
    asked->formrcv((SubscriptionToCourseForm *)toRet);
}

Student::~Student() {
    if (this->_waitFill != nullptr) {
        delete this->_waitFill;
    }
}

void Headmaster::attendClasses() {
    if (this->_paused == true) {
        std::cout << "Professor and student in break" << std::endl;
        return;
    }
    ProfessorList *ex1 = ProfessorList::getInstance();
    std::vector<Professor *> *lst = ex1->getList();

    for (int i = 0; i < lst->size(); i++) {
        if ((* lst)[i] != nullptr) {
            (* lst)[i]->doClass();
        }
    }

    StudentList *ex2 = StudentList::getInstance();
    std::vector<Student *> *lst2 = ex2->getList();
    for (int i = lst2->size(); i > 0; i--) {
        if ((* lst2)[i - 1] != nullptr) {
            (* lst2)[i - 1]->joinAsk();
        }
    }
}

Student::Student(std::string p_name) : Person(p_name), _waitFill(nullptr) {
    StudentList *lst = StudentList::getInstance();
    lst->add(this);
}

void Person::alert(std::string msg) {
    std::cout << this->_name << msg << std::endl;
}

void Headmaster::ring() {
    this->_sub.ping(Event::RingBell, this->_paused);
    this->_paused = !this->_paused;
}

void Headmaster::lunch() {
    this->_sub.ping(Event::LunchBell, this->_paused);
    this->_paused = !this->_paused;
}