#include "./../Includes/Header.h"

int main(int ac, char **av) {
    if (ac != 3) {
        std::cerr << "[exec] [Train Composition] [Rail Network]" << std::endl;
        exit(1);
    }
    checkFile(av);

    assignTravel();


    clearSingletons();
    return 0;
}

void assignTravel() {
    TrainList *obj = TrainList::getInstance();
    std::vector<Train *> *lst = obj->getList();
    findPath((* lst)[0]);
}

void findPath(Train *train) {
    RailList *obj1 = RailList::getInstance();
    std::vector<Rail *> *lstR = obj1->getList();
    NodeList *obj2 = NodeList::getInstance();
    std::vector<Node *> *lstN = obj2->getList();
    Node *start = train->getDeparture();
    Node *end = train->getArrival();
    std::map<Node *, float> distances;
    std::map<Node *, int> pinned;
    std::map<Node *, Node *> quick;
    
    for (int i = 0; i < lstN->size(); i++) {
        distances[(* lstN)[i]] = -1;
        pinned[(* lstN)[i]] = 0;
        quick[(* lstN)[i]] = nullptr;
        if ((* lstN)[i] == start) {
            distances[(* lstN)[i]] = 0;
            quick[(* lstN)[i]] = (* lstN)[i];
        }
    }
    for (int i = 0; i < lstN->size(); i++) {
        std::map<Node *, float>::iterator itd = distances.begin();
        std::map<Node *, int>::iterator itp = pinned.begin();
        Node *toTreat = nullptr;
        while(itd != distances.end()) {
            if (toTreat == nullptr) {
                if (itd->second != -1 && itp->second == 0)
                    toTreat = itd->first;
            }
            else {
                if (distances[toTreat] > itd->second && itp->second == 0 && itd->second != -1)
                    toTreat = itd->first;
            }
            ++itd;
            ++itp;
        }
        if (toTreat == nullptr)
            break;
        for (int y = 0; y < lstR->size(); y++) {
            if (toTreat == (* lstR)[y]->getStart()) {
                if (pinned[(* lstR)[y]->getArrival()] == 0)
                    if (distances[(* lstR)[y]->getArrival()] > (* lstR)[y]->getLenght() + distances[toTreat] || distances[(* lstR)[y]->getArrival()] == -1) {
                        distances[(* lstR)[y]->getArrival()] = (* lstR)[y]->getLenght() + distances[toTreat]; 
                        quick[(* lstR)[y]->getArrival()] = (* lstR)[y]->getStart();
                    }
            }
            else if (toTreat == (* lstR)[y]->getArrival()) {
                if (pinned[(* lstR)[y]->getStart()] == 0)
                    if (distances[(* lstR)[y]->getStart()] > (* lstR)[y]->getLenght() + distances[toTreat] || distances[(* lstR)[y]->getStart()] == -1) {
                        distances[(* lstR)[y]->getStart()] = (* lstR)[y]->getLenght() + distances[toTreat];
                        quick[(* lstR)[y]->getStart()] = (* lstR)[y]->getArrival();
                    }
            }
        }
        pinned[toTreat] = 1;
    }
    std::cout << end->getName() << std::endl;
    Node *un = quick[end];
    std::cout << un->getName() << std::endl;
    un = quick[un];
    std::cout << un->getName() << std::endl;
    un = quick[un];
    std::cout << un->getName() << std::endl;


    for (int i = 0; i < lstN->size(); i++) {
        std::map<Node *, float>::iterator itd = distances.begin();
        std::cout << distances[(* lstN)[i]] << std::endl;
        ++itd;
    }
}