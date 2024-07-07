#include "Singleton.hpp"
#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"

int main () {
    Secretary sec("Catherine");
    Headmaster hed("Didier");

    NeedCourseCreationForm *f1 = (NeedCourseCreationForm *)sec.createForm(FormType::NeedCourseCreation);
    // CourseFinishedForm *f2 = (CourseFinishedForm *)sec.createForm(FormType::CourseFinished);
    NeedMoreClassRoomForm *f3 = (NeedMoreClassRoomForm *)sec.createForm(FormType::NeedMoreClassRoom);
    // SubscriptionToCourseForm *f4 = (SubscriptionToCourseForm *)sec.createForm(FormType::SubscriptionToCourse);

    FillNeedCourseCreationForm t1(f1, "test");
    FillNeedMoreClassRoomForm t3(f3, 1);

    hed.receiveForm(&t1);
    hed.receiveForm(f1);
    hed.receiveForm(f3);
    hed.receiveForm(&t3);
    hed.receiveForm(f3);
    hed.exec();

    // FillCourseFinishedForm t2();
    // FillSubscriptionToCourseForm t4();
}