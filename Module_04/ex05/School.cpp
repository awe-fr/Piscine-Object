#include "School.hpp"

Headmaster School::getHeadmaster() {
    return (*this->_master);
}

Secretary School::getSecretary() {
    return (*this->_sec);
}

void School::runDayRoutine() {
    this->launchClasses();
    std::cout << "----" << std::endl;
    this->requestRingBell();
    this->requestRingBell();
    std::cout << "----" << std::endl;
    this->launchClasses();
    std::cout << "----" << std::endl;
    this->_master->lunch();
    this->_master->lunch();
    std::cout << "----" << std::endl;
    this->launchClasses();
    std::cout << "----" << std::endl;
    this->requestRingBell();
    this->requestRingBell();
    std::cout << "----" << std::endl;
    this->launchClasses();
}

void School::launchClasses() {
    this->_master->attendClasses();
}

void School::requestRingBell() {
    this->_master->ring();
}

void School::recruteProfessor() {
    Professor *teacher = new Professor("Bob");
}

void School::recruteStudent() {
    Student *teacher = new Student("Kevin");
}

std::vector<Student *> School::getStudents() {
    StudentList *ex = StudentList::getInstance();
    std::vector<Student *> *tmp = ex->getList();
    return (*tmp);
}

std::vector<Professor *> School::getProfessors() {
    ProfessorList *ex = ProfessorList::getInstance();
    std::vector<Professor *> *tmp = ex->getList();
    return (*tmp);
}

Course* School::getCourse(std::string p_name) {
    CourseList *ex = CourseList::getInstance();
    std::vector<Course *> *tmp = ex->getList();
    for (int i = 0; i < tmp->size(); i++) {
        if ((* tmp)[i] != nullptr && (* tmp)[i]->getName() == p_name)
            return ((* tmp)[i]);
    }
    return (nullptr);
}

void School::graduationCeremony() {
    CourseList *ex = CourseList::getInstance();
    std::vector<Course *> *tmp = ex->getList();
    for (int i = 0; i < tmp->size(); i++) {
        if ((* tmp)[i] != nullptr) {
            std::vector<Student*> listStud = (* tmp)[i]->getStud();
            for (int y = 0; y < listStud.size(); y++) {
                Form *toRet = this->_sec->createForm(FormType::Graduate);
                FillGraduateForm fill((GraduateForm *)toRet, (* tmp)[i], listStud[y]);
                this->_master->receiveForm(&fill);
                this->_master->receiveForm(toRet);
                this->_master->exec();
                delete toRet;
            }
        }
            
    }
}