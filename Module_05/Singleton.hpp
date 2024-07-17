#pragma once

#include <iostream>
#include <vector>

#include "Event.hpp"
#include "Node.hpp"
#include "Rail.hpp"
#include "Train.hpp"

template <typename T, typename L>
class Singleton {
    protected:
        static T *_instance;
        std::vector<L *> _list;

        Singleton() {};
        virtual ~Singleton() {};
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    public:
        static T *getInstance() {
            if (_instance == nullptr)
                _instance = new T();
            return _instance;
        }
        std::vector<L *> *getList() {return &this->_list;};
        void    add(L *toAdd) {
            if (toAdd != nullptr)
                this->_list.push_back(toAdd);
        };
        void    remove(L *toRm) {
            if (toRm != nullptr) {
                for (int i = this->_list.size(); i > 0; i--) {
                    if (this->_list[i - 1] == toRm) {
                        delete toRm;
                        this->_list.erase(this->_list.begin() + i - 1);
                        // std::cout << "Removed from list" << std::endl;
                        break;
                    }
                }
            }
        };
        void    cleanup() {
            for (int i = this->_list.size(); i > 0; i--) {
                delete this->_list[i - 1];
            }
            // std::cout << "Singleton cleanup" << std::endl;
        }
};

template <typename T, typename L>
T* Singleton<T, L>::_instance = nullptr;

class NodeList : public Singleton<NodeList, Node> {
    private:

    public:
};

class TrainList : public Singleton<TrainList, Train> {
    private:

    public:
};