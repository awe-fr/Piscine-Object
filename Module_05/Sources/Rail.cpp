#include "./../Includes/Rail.hpp"

Rail::Rail(Node *a, Node *b, float lenght, int first) : _a(a), _b(b), _lenght(lenght), _maxSpeed(200) {
    RailList *lst = RailList::getInstance();
    lst->add(this);
    if (first == 1)
        Rail *rail = new Rail(b, a, lenght, 0);
}

Node *Rail::getStart() {
    return(this->_a);
}

Node *Rail::getArrival() {
    return(this->_b);
}

float   Rail::getLenght() {
    return(this->_lenght);
}

float   Rail::getSpeed() {
    return(this->_maxSpeed);
}

std::string Rail::getTrafic(Train *train) {
    TrainList *elm = TrainList::getInstance();
    std::vector<Train *> *lst = elm->getList();
    std::string line;
    for (float i = 0; i <= this->_lenght; i += 1) {
        line += "[ ]";
    }
    for (int i = 0; i < lst->size(); i++) {
        if ((* lst)[i]->getRail() == this) {
            int pos = (int)std::trunc((* lst)[i]->getTraveled());
            if(pos < 0 || pos >this->_lenght)
                pos = 0;
            pos *= 3; pos += 1;
            line[pos] = 'O';
        }
    }
    int posA = (int)std::trunc(train->getTraveled());
    if(posA < 0 || posA >this->_lenght)
        posA = 0;
    posA *= 3; posA += 1;
    line[posA] = 'X';
    line = cutTrafic(line);
    return line;
}

std::string Rail::cutTrafic(std::string line) {
    int i = 0;
    int y = 0;
    int km = 0;
    std::string newLine;
    while(line[i]) {
        if (line[i] == 'X' || line[i] == 'O') {
            if (i - 1 == y) {
                newLine += line[i - 1];
                newLine += line[i];
                newLine += line[i + 1];
                i++;
                y = i + 1;
            }
            else if (((i - y) / 3) <= 3) {
                for (int t = 0; t < (i - y) / 3; t++)
                    newLine += "[ ]";
                y = i - 1;
                i -= 1;
            }
            else {
                km = (i - y) / 3;
                newLine += "[ ][";
                newLine += std::to_string(km - 2);
                newLine += "km][ ]";
                y = i - 1;
                i -= 1;
            }
        }
        i++;
    }
    if (i - 1 == y) {
        newLine += line[i - 1];
        newLine += line[i];
        newLine += line[i + 1];
        i++;
        y = i + 1;
    }
    else {
        km = ((i - y) / 3) - 2;
        if (km > 0) {
            newLine += "[ ][";
            newLine += std::to_string(km);
            newLine += "km][ ]";
        }
        else if (km == -1) {
            newLine += "[ ]";
        }
    }
    return newLine;
}