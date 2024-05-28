#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Room.hpp"

#include <iostream>

template <typename T, typename L>
class Singleton {
    protected:
        static T *_instance;
        std::vector<L *> _list;

        Singleton() {std::cout << "Init Singleton list" << std::endl;};
        virtual ~Singleton() {std::cout << "Delete Singleton list" << std::endl;};
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    public:
        static T *getInstance() {
            if (_instance == nullptr)
                _instance = new T();
            return _instance;
        }
        std::vector<L *> *getList() {return this->_list;};
        void    add(L *toAdd) {
            if (toAdd != nullptr)
                this->_list.push_back(toAdd);
        };
        void    remove(L *toRm) {
            if (toRm != nullptr) {
                for (int i = this->_list.size(); i > 0; i--) {
                    if (this->_list[i - 1] == toRm) {
                        this->_list.erase(this->_list.begin() + i - 1);
                        std::cout << "Removed from list" << std::endl;
                        break;
                    }
                }
            }
        };
};

template <typename T, typename L>
T* Singleton<T, L>::_instance = nullptr;

class StudentList : public Singleton<StudentList, Student> {
    private:

    public:
};

class StaffList : public Singleton<StaffList, Staff> {
    private:

    public:
};

class CourseList : public Singleton<CourseList, Course> {
    private:

    public:
};

class RoomList : public Singleton<RoomList, Room> {
    private:

    public:
};