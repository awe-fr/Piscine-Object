#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

class ILogger {
    public:
        virtual void write(std::string n) = 0;
};

class Logger1 : public ILogger {
    private:
        std::string filePath;
    public:
        Logger1(std::string path) : filePath(path) {
            std::ofstream file(this->filePath.c_str());
            file << "";
            file.close();
        };
        void write(std::string n) {
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::ofstream file(this->filePath.c_str(), std::ios::app);
            char *date = std::ctime(&end_time);
            std::string ret;
            ret += "[";
            int i = 0;
            while(date[i] != '\n')
                ret += date[i++];
            ret += "] ";
            ret += n;
            ret += "\n";
            file << ret;
            file.close();
        };
};

class Logger2 : public ILogger {
    private:
        std::ostream& stream;
    public:
        Logger2(std::ostream& out) : stream(out) {};
        void write(std::string n) {
            n += "\n";
            stream.write(n.c_str(), n.length());
        };
};