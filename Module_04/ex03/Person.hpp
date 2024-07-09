#pragma once

#include <string>

#include "Room.hpp"
#include "Form.hpp"

enum class FormType;

class Person
{
    protected:
        std::string _name;
        Room* _currentRoom;
    public:
        Person(std::string p_name) : _name(p_name) {};
        Room* room() {return (_currentRoom);}
		virtual void formrcv(Form *ret) {};
};

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
	Form * _waitFill;
public:
	Student(std::string p_name) : Person(p_name), _waitFill(nullptr) {};
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
	void sub(Course *course);
	void formrcv(Form *ret);
	void fill();
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
	void askForm(FormType p_formType, Person *asked);
	void receiveForm(Form* p_form);
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
	Form * _waitFill;
public:
	Professor(std::string name) : Staff(name), _currentCourse(nullptr), _waitFill(nullptr) {};
	void assignCourse(Course* p_course);
	void formrcv(Form *ret);
	void doClass();
	void closeCourse();
	void fill(Course *course);
};