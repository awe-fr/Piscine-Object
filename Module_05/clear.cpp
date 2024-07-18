#include "Header.h"

void clearSingletons() {
    TrainList * trainList= TrainList::getInstance();
    NodeList * nodeList= NodeList::getInstance();
    RailList * railList= RailList::getInstance();
    EventList * eventList= EventList::getInstance();

    trainList->cleanup();
    nodeList->cleanup();
    railList->cleanup();
    eventList->cleanup();

    delete trainList;
    delete nodeList;
    delete railList;
    delete eventList;
    exit(1);
}