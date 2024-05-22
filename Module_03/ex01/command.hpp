#pragma once

#include <iostream>
#include <vector>

struct article {
    std::string name;
    float       price;
    int         quantity;
};

class Command {
    protected:
        std::vector<article>    *articles;
        std::string             client;
        std::string             date;
        int                     id;
    public:
        Command(std::vector<article> *a, std::string b, std::string c, int d) {
            this->articles = a;
            this->client = b;
            this->date = c;
            this->id = d;
        };
        virtual float   get_total_price() {
            float cal = 0;
            for (int i = this->articles->size(); i > 0; i--) {
                cal += this->articles->at(i - 1).price * this->articles->at(i - 1).quantity;
            }
            return cal;
        };
};