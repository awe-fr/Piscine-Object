#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"

int main () {
    Secretary sec("Catherine");
    Headmaster hed("Didier");
    NeedCourseCreationForm *f1 = (NeedCourseCreationForm *)sec.createForm(FormType::NeedCourseCreation);
    FillNeedCourseCreationForm t1(f1, "trisonometrie");
    hed.receiveForm(&t1);
    hed.receiveForm(f1);
    hed.exec();
    CourseList *ex1 = CourseList::getInstance();
    std::vector<Course *> *lst = ex1->getList();
    Professor prof("Le s");
    prof.askCourse();
    prof.fillCourse((*lst)[0]);
    prof.doClass();

    std::cout << "------------------" << std::endl;

    Student *stud = new Student("Paul");
    SubscriptionToCourseForm *f4 = (SubscriptionToCourseForm *)sec.createForm(FormType::SubscriptionToCourse);
    FillSubscriptionToCourseForm t4(f4, (*lst)[0], stud);
    hed.receiveForm(&t4);
    hed.receiveForm(f4);
    hed.exec();
    prof.doClass();
    
    std::cout << "------------------" << std::endl;
    
    prof.askGraduate();
    prof.fillGrad((*lst)[0], stud);

    // GraduateForm *f2 = (GraduateForm *)sec.createForm(FormType::NeedCourseCreation);
    // FillGraduateForm t2(f2, (*lst)[0], stud);


    std::cout << "------------------" << std::endl;

    ex1->cleanup();
    delete ex1;
    delete f4;
    delete stud;
    delete f1;
}