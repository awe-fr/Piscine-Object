#include "./../Includes/Header.h"

void checkFile(char **filePath) {
    std::ifstream trainFile(filePath[1]);
    std::ifstream railFile(filePath[2]);

    if(!trainFile.is_open() || !railFile.is_open()) {
        std::cerr << "File cannot be opened !" << std::endl;
        trainFile.close();
        railFile.close();
        exit(1);
    }

    if (systempParsing(railFile) == 1 || trainParsing(trainFile) == 1) {
        trainFile.close();
        railFile.close();
        clearSingletons();
    }

    trainFile.close();
    railFile.close();
    return;
}

int systempParsing(std::ifstream &file) {
    std::string line;
    
    while(getline(file, line)) {
        std::string type;
        for (int i = 0; line[i] != ' ' && line[i] != '\0'; i++)
            type += line[i];
        if (type == "Node") {
            if (nodeParsing(line) == 1) {
                std::cerr << "Parsing failed : \"" << line << "\"" << std::endl;
                return 1;
            }
        }
        else if (type == "Rail") {
            if (railParsing(line) == 1) {
                std::cerr << "Parsing failed : \"" << line << "\"" << std::endl;
                return 1;
            }
        }
        else if (type == "Event") {
            if (eventParsing(line) == 1) {
                std::cerr << "Parsing failed : \"" << line << "\"" << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "Parsing failed : \"" << line << "\"" << std::endl;
            return 1;
        }
    }
    return 0;
}

int nodeParsing(std::string line) {
    std::string seg;
    for (int i = 5; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++)
        seg += line[i];
    if (line.size() > seg.size() + 5)
        return 1;
    Node *node = new Node(seg);
    return 0;
}

int railParsing(std::string line) {
    std::string nodeA;
    std::string nodeB;
    std::string lenghtS;
    float lenght = -1;
    int i = 5;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ') {
        nodeA += line[i];
        i++;
    }
    i++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ') {
        nodeB += line[i];
        i++;
    }
    i++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ') {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
            lenghtS += line[i];
        }
        else
            return 1;
        i++;
    }
    if (!lenghtS.empty())
        lenght = std::stof(lenghtS);
    if (lenght < 0 || nodeA.empty() || nodeB.empty() || (line.size() > i))
        return 1;
    if (railAssign(nodeA, nodeB, lenght) == 1)
        return 1;
    return 0;
}

int railAssign(std::string nodeA,std::string nodeB, float lenght) {
    int aNum = -1;
    int bNum = -1;
    NodeList *nodes = NodeList::getInstance();
    std::vector<Node *> *lst = nodes->getList();
    for (int i = 0; i < lst->size(); i ++) {
        if ((* lst)[i]->getName() == nodeA)
            aNum = i;
        else if ((* lst)[i]->getName() == nodeB)
            bNum = i;
    }
    if (aNum == -1 || bNum == -1)
        return 1;
    Rail *rail = new Rail((* lst)[aNum], (* lst)[bNum], lenght);
    return 0;
}

int eventParsing(std::string line) {
    std::string event;
    std::string rateS;
    std::string timeS;
    std::string node;
    float rate = -1;
    float time = -1;
    int mult = 0;
    int i = 6;
    if (line[i] == '\"') {
        i++;
        while(line[i] != '\0' && line[i] != '\"' && line[i] != '\n') {
            event += line[i];
            i++;
        }
        i++;
    }
    else {
        while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
            event += line[i];
            i++;
        }
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
            rateS += line[i];
        }
        else
            return 1;
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        if ((line[i] >= '0' && line[i] <= '9')) {
            timeS += line[i];
        }
        else if (line[i] == 'm')
            mult = 1;
        else if (line[i] == 'h')
            mult = 60;
        else if (line[i] == 'd')
            mult = 1440;
        else
            return 1;
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        node += line[i];
        i++;
    }
    if (!rateS.empty() && !timeS.empty()) {
        rate = std::stof(rateS);
        time = std::stof(timeS);
        time *= mult;
    }
    else
        return 1;
    if (rate < 0 || time < 0 || mult == 0 || event.empty() || node.empty() || (line.size() > i))
        return 1;
    if (eventAssign(event, rate, time, node) == 1)
        return 1;
    return 0;
}

int eventAssign(std::string reason, float rate, float time, std::string node) {
    int Num = -1;
    NodeList *nodes = NodeList::getInstance();
    std::vector<Node *> *lst = nodes->getList();
    for (int i = 0; i < lst->size(); i ++) {
        if ((* lst)[i]->getName() == node)
            Num = i;
    }
    if (Num == -1)
        return 1;
    Event *event = new Event(reason, (* lst)[Num], rate, time);
    return 0;
}

int trainParsing(std::ifstream &file) {
    std::string line;
    
    while(getline(file, line)) {
        if (trainCut(line) == 1)  {
            std::cerr << "Parsing failed : \"" << line << "\"" << std::endl;
            return 1;
        }
    }
    return 0;
}

int trainCut(std::string line) {
    std::string name;
    std::string a;
    std::string b;
    std::string accS;
    std::string brakeS;
    std::string hourS;
    float acc = -1;
    float brake = -1;
    float hour = -1;
    int i = 0;

    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        name += line[i];
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
            accS += line[i];
        }
        else
            return 1;
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
            brakeS += line[i];
        }
        else
            return 1;
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        a += line[i];
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        b += line[i];
        i++;
    }
    i++;
    while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
        if ((line[i] >= '0' && line[i] <= '9')) {
            hourS += line[i];
        }
        else if (line[i] != 'h')
            return 1;
        i++;
    }
    if (!accS.empty() && !brakeS.empty() && !hourS.empty()) {
        acc = std::stof(accS);
        brake = std::stof(brakeS);
        hour = std::stof(hourS);
    }
    else
        return 1;
    if (acc < 0 || brake < 0 || hour < 0 || name.empty() || a.empty() || b.empty() || (line.size() > i))
        return 1;
    if (hour / 100 >= 24 || (int)hour % 100 >= 60)
        return 1;
    if (trainAssign(name, a, b, acc, brake, hour) == 1)
        return 1;
    return 0;
}

int trainAssign(std::string name, std::string a, std::string b, float acc, float brake, float hour) {
    int aNum = -1;
    int bNum = -1;
    NodeList *nodes = NodeList::getInstance();
    std::vector<Node *> *lst = nodes->getList();
    for (int i = 0; i < lst->size(); i ++) {
        if ((* lst)[i]->getName() == a)
            aNum = i;
        else if ((* lst)[i]->getName() == b)
            bNum = i;
    }
    if (aNum == -1 || bNum == -1)
        return 1;
    Train *train = new Train(name, (* lst)[aNum], (* lst)[bNum], acc, brake, hour);
    return 0;
}