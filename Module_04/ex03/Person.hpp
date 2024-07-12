#pragma once

#include <string>

#include "Room.hpp"
#include "Form.hpp"

class GraduateForm;
class SubscriptionToCourseForm;
class NeedCourseCreationForm;
class NeedMoreClassRoomForm;

enum class FormType;

class Person
{
    protected:
        std::string _name;
        Room* _currentRoom;
    public:
        Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {};
        Room* room() {return (_currentRoom);}
};

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
	SubscriptionToCourseForm * _waitFill;
public:
	Student(std::string p_name);
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void joinAsk();
	void graduate(Course* p_course);
	void sub(Course *course);
	void formrcv(SubscriptionToCourseForm *ret);
	void fill(Course *course);
	void takeNote();
	~Student();
};

class Staff : public Person
{
    private:

    public:
		Staff(std::string p_name) : Person(p_name) {};
        void sign(Form* p_form);
};

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	Headmaster(std::string name) : Staff(name) {};
	void askFormnewCourse(FormType p_formType, Professor *asked);
	void askFormnewRoom(FormType p_formType, Professor *asked);
	void askFormGraduate(FormType p_formType, Professor *asked);
	void askFormjoinCourse(FormType p_formType, Student *asked);
	void receiveForm(Form* p_form);
	void attendClasses();
	void exec();
};

class Secretary : public Staff
{
private:

public:
	Secretary(std::string name) : Staff(name) {};
	Form* createForm(FormType p_formType);
	void archiveForm();
};

class Professor : public Staff
{
private:
	Course* _currentCourse;
	NeedCourseCreationForm* _waitFill;
	GraduateForm * _waitFillGrad;
	NeedMoreClassRoomForm *_waitFillRoom;
public:
	Professor(std::string name);
	void assignCourse(Course* p_course);
	void askCourse();
	void askRoom();
	void askGraduate();
	void formrcv(NeedCourseCreationForm *ret);
	void formrcv(NeedMoreClassRoomForm *ret);
	void formrcv(GraduateForm *ret);
	void doClass();
	void closeCourse();
	void fillCourse(std::string name);
	void fillGrad(Course *course, Student *stud);
	void fillRoom();
	~Professor();
};