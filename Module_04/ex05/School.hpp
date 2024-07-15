#pragma once

#include "Person.hpp"

class School {
    private:
        Headmaster *_master;
        Secretary *_sec;
    public:
        School() : _master(new Headmaster("Thiery")), _sec(new Secretary("Catherine")) {};
        void runDayRoutine();
        void launchClasses();
        void requestRingBell();
        void recruteProfessor();
        void recruteStudent();
        Course* getCourse(std::string p_name);
        std::vector<Student *> getStudents();
        std::vector<Professor *> getProfessors();
        Headmaster getHeadmaster();
        Secretary getSecretary();
        void graduationCeremony();
        ~School() {delete _master; delete _sec;};
};