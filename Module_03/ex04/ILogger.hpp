#pragma once

#include <iostream>
#include <fstream>

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
            std::ofstream file(this->filePath.c_str(), std::ios::app);
            file << n;
            file.close();
        };
};

class Logger2 : public ILogger {
    private:
        std::ostream& stream;
    public:
        Logger2(std::ostream& out) : stream(out) {};
        void write(std::string n) {
            stream.write(n.c_str(), n.length());
        };
};