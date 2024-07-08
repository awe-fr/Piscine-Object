#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"

int main () {
    Secretary sec("Catherine");
    Headmaster hed("Didier");

    NeedCourseCreationForm *f1 = (NeedCourseCreationForm *)sec.createForm(FormType::NeedCourseCreation);
    NeedMoreClassRoomForm *f3 = (NeedMoreClassRoomForm *)sec.createForm(FormType::NeedMoreClassRoom);

    CourseFinishedForm *f2 = (CourseFinishedForm *)sec.createForm(FormType::CourseFinished);
    SubscriptionToCourseForm *f4 = (SubscriptionToCourseForm *)sec.createForm(FormType::SubscriptionToCourse);

    FillNeedCourseCreationForm t1(f1, "test");
    FillNeedMoreClassRoomForm t3(f3, 1);

    hed.receiveForm(&t1);
    hed.receiveForm(f1);
    hed.receiveForm(f3);
    hed.receiveForm(&t3);
    hed.receiveForm(f3);
    hed.exec();

    std::cout << "------------------" << std::endl;

    CourseList *ex1 = CourseList::getInstance();
    RoomList *ex2 = RoomList::getInstance();
    std::vector<Course *> *lst = ex1->getList();
    Student s1("Paul");

    FillCourseFinishedForm t2(f2, (*lst)[0]);
    FillSubscriptionToCourseForm t4(f4, (*lst)[0], &s1);

    std::cout << "------------------" << std::endl;

    hed.receiveForm(&t4);
    hed.receiveForm(f4);
    // hed.receiveForm(&t2);
    // hed.receiveForm(f2);
    hed.exec();

    std::cout << "------------------" << std::endl;

    ex1->cleanup();
    ex2->cleanup();

    std::cout << "------------------" << std::endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete ex1;
    delete ex2;
}