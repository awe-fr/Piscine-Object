#include "singleton.hpp"

void testFonc(Student *t1, Staff *t2, Course *t3, Room *t4) {
    StudentList *s1 = StudentList::getInstance();
    StaffList *s2 = StaffList::getInstance();
    CourseList *s3 = CourseList::getInstance();
    RoomList *s4 = RoomList::getInstance();

    s1->remove(t1);
    s2->remove(t2);
    s3->remove(t3);
    s4->remove(t4);
}

int main () {
    StudentList *s1 = StudentList::getInstance();
    StaffList *s2 = StaffList::getInstance();
    CourseList *s3 = CourseList::getInstance();
    RoomList *s4 = RoomList::getInstance();

    Student *t1 = new Student("test1");
    Staff *t2 = new Staff("test2");
    Course *t3 = new Course("test3");
    Room *t4 = new Room(1);

    s1->add(t1);
    s2->add(t2);
    s3->add(t3);
    s4->add(t4);

    testFonc(t1, t2, t3, t4);

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    delete t1;
    delete t2;
    delete t3;
    delete t4;
}