#include "Form.hpp"

void FillNeedMoreClassRoomForm::execute() {
    this->_form->fill(this->_id);
}

void NeedMoreClassRoomForm::fill(long long id) {
    this->_id = id;
    this->_roomList = RoomList::getInstance();
    this->_filled = true;
}

void NeedMoreClassRoomForm::execute() {
    if (this->_filled == true) {
        Classroom *push = new Classroom(this->_id);
        this->_roomList->add(push);
        std::cout << "Classroom added to room list" << std::endl;
        return;
    }
    std::cout << "Form not complited" << std::endl;
}

void FillCourseFinishedForm::execute() {
    this->_form->fill(this->_course);
}

void CourseFinishedForm::fill(Course *course) {
    this->_courseList = CourseList::getInstance();
    this->_course = course;
    this->_filled = true;
}

void CourseFinishedForm::execute() {
    if(this->_filled == true) {
        this->_courseList->remove(this->_course);
        std::cout << "Course removed" << std::endl;
    }
    std::cout << "Form not complited" << std::endl;
}

FillSubscriptionToCourseForm::FillSubscriptionToCourseForm(SubscriptionToCourseForm *form, Course *toSub, Student *stud) {
    this->_form = form;
    this->_toSub = toSub;
    this->_stud = stud;
    CourseList *list = CourseList::getInstance();
    this->_list = list->getList();
}

void FillSubscriptionToCourseForm::execute() {
    this->_form->fill(this->_list, this->_toSub, this->_stud);
};

void SubscriptionToCourseForm::fill(std::vector<Course *> *list, Course *toSub, Student *stud) {
    this->_list = list;
    this->_toSub = toSub;
    this->_stud = stud;
    this->_filled = true;
};

void SubscriptionToCourseForm::execute() {
    if (this->_filled == true) {
        // std::vector<Course *> conv = *this->_list;
        for (long unsigned int i = 0; i < (*_list).size(); i++) {
            if ((*_list)[i] == this->_toSub) {
                (*_list)[i]->subscribe(this->_stud);
                std::cout << "Student subscribed" << std::endl;
                return;
            }
        }
        std::cout << "Unknown course" <<std::endl;
        return;
    }
    std::cout << "Form not complited" << std::endl;
}

void FillNeedCourseCreationForm::execute() {
    this->_form->fill(this->_name, this->_prof);
}

void NeedCourseCreationForm::fill(std::string name, Professor *prof) {
    this->_name = name;
    this->_courseList = CourseList::getInstance();
    this->_filled = true;
    this->_prof = prof;
} 

void NeedCourseCreationForm::execute() {
    if (this->_filled == true) {
        Course *push = new Course(this->_name);
        this->_courseList->add(push);
        push->assign(this->_prof);
        std::cout << "Course added to courses list" << std::endl;
        return;
    }
    std::cout << "FoSubscriptionToCourseForm not complited" << std::endl;
}

void GraduateForm::fill(Course *course, Student *stud) {
    this->_course = course;
    this->_stud = stud;
    CourseList *list = CourseList::getInstance();
    this->_list = list->getList();
    this->_filled = true;
} 

void FillGraduateForm::execute() {
    this->_form->fill(this->_course, this->_stud);
}

void GraduateForm::execute() {
    if (this->_filled == true) {
        for (long unsigned int i = 0; i < (*_list).size(); i++) {
            if ((*_list)[i] == this->_course) {
                this->_stud->graduate(this->_course);
                std::cout << "Student graduated" << std::endl;
                return;
            }
        }
        std::cout << "Unknown course" <<std::endl;
        return;
    }
    std::cout << "Form not complited" << std::endl;
}