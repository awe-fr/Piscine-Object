#pragma once

#include "command.hpp"

class ThuesdayDiscount : public Command {
    public:
        ThuesdayDiscount(std::vector<article> *a, std::string b, std::string c, int d) : Command(a, b, c, d) {};
        float get_total_price() {
            if (this->date == "Jeudi") {
                for (int i = this->articles->size(); i > 0; i--) {
                    this->articles->at(i - 1).price *= 0.90;
                }
            }
            return 0;
        };
};