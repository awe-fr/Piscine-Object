#pragma once

class Person;

#include <vector>

#include "Course.hpp"
#include "Person.hpp"
#include "Form.hpp"

class Form;

class Room
{
    private:
        long long ID;
        std::vector<Person*> _occupants;

    public:
        Room(long long id) : ID(id) {};
        bool canEnter(Person*);
        void enter(Person*);
        void exit(Person*);
        
        void printOccupant();
};

class Classroom : public Room
{
    private:
        Course* _currentRoom;
    public:
        Classroom(long long id) : Room(id) {};
        void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
    private:
        std::vector<Form*> _archivedForms;

    public:

};

class HeadmasterOffice : public Room
{
    private:

    public:

};

class StaffRestRoom : public Room
{
    private:

    public:

};

class Courtyard : public Room
{
    private:

    public:

};