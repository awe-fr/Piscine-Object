#pragma once

#include "command.hpp"

class PackageReductionDiscount : public Command{
    public:
        PackageReductionDiscount(std::vector<article> *a, std::string b, std::string c, int d) : Command(a, b, c, d) {};
        float get_total_price() {
            float cal = 0;
            for (int i = this->articles->size(); i > 0; i--) {
                cal += this->articles->at(i - 1).price * this->articles->at(i - 1).quantity;
            }
            if (cal >= 150) {
                article reduc = {"Package reduction", -10, 1};
                this->articles->push_back(reduc);
            }
            return 0;
        };
};