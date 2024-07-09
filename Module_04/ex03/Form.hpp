#pragma once

#include <iostream>
#include "Singleton.hpp"

class CourseList;
class RoomList;

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
    TeachCourse
};

enum class Event
{
	RingBell
};

class Form
{
    protected:

    public:
        Form() {};
        virtual ~Form() {};

        virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
    private:
        CourseList *_courseList;
        Course *_course;
        bool _filled;
    public:
        CourseFinishedForm() : _filled(false) {};
        void fill(Course *course);
        void execute();
};

class FillCourseFinishedForm : public Form
{
    private:
        CourseFinishedForm *_form;
        Course *_course;
    public:
        FillCourseFinishedForm(CourseFinishedForm *form, Course *course) : _form(form), _course(course) {};
        void execute();
};

class NeedMoreClassRoomForm : public Form
{
    private:
        RoomList *_roomList;
        long long _id;
        bool _filled;
    public:
        NeedMoreClassRoomForm() : _filled(false) {};
        void fill(long long id);
        void execute();
};

class FillNeedMoreClassRoomForm : public Form
{
    private:
        NeedMoreClassRoomForm *_form;
        long long _id;
    public:
        FillNeedMoreClassRoomForm(NeedMoreClassRoomForm *form, long long id) : _form(form), _id(id) {};
        void execute();
};

class NeedCourseCreationForm : public Form
{
    private:
        CourseList *_courseList;
        std::string _name;
        bool _filled;
    public:
        NeedCourseCreationForm() : _filled(false) {};
        void fill(std::string name);
        void execute();
};

class FillNeedCourseCreationForm : public Form
{
    private:
        NeedCourseCreationForm *_form;
        std::string _name;
    public:
        FillNeedCourseCreationForm(NeedCourseCreationForm *form, std::string name) : _form(form), _name(name) {};
        void execute();
};

class SubscriptionToCourseForm : public Form
{
    private:
        std::vector<Course *> *_list;
        Course *_toSub;
        Student *_stud;
        bool _filled;
    public:
        SubscriptionToCourseForm() : _filled(false) {};
        void fill(std::vector<Course *> *list, Course *toSub, Student *stud);
        void execute();
};


class FillSubscriptionToCourseForm : public Form
{
    private:
        SubscriptionToCourseForm *_form;
        std::vector<Course *> *_list;
        Course *_toSub;
        Student *_stud;
    public:
        FillSubscriptionToCourseForm(SubscriptionToCourseForm *form, Course *toSub, Student *stud);
        void execute();
};

class TeachCourseForm : public Form
{
    private:
        std::vector<Course *> *_list;
        Course *_toSub;
        Professor *_stud;
        bool _filled;
    public:
        TeachCourseForm() : _filled(false) {};
        void fill(std::vector<Course *> *list, Course *toSub, Professor *stud);
        void execute();
};

class FillTeachCourseForm : public Form
{
    private:
        TeachCourseForm *_form;
        std::vector<Course *> *_list;
        Course *_toSub;
        Professor *_stud;
    public:
        FillTeachCourseForm(Form *form, Course *toSub, Professor *stud);
        void execute();
};