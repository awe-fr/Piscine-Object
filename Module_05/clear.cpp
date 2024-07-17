#include "Header.h"

void clearSingletons() {
    TrainList * trainList= TrainList::getInstance();
    NodeList * nodeList= NodeList::getInstance();

    trainList->cleanup();
    nodeList->cleanup();

    delete trainList;
    delete nodeList;

    exit(1);
}