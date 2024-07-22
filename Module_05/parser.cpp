#include "Header.h"

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
                std::cerr << "Parsing failed : '" << line << "'" << std::endl;
                return 1;
            }
        }
        else if (type == "Rail") {
            if (railParsing(line) == 1) {
                std::cerr << "Parsing failed : '" << line << "'" << std::endl;
                return 1;
            }
        }
        else if (type == "Event") {
            if (eventParsing(line) == 1) {
                std::cerr << "Parsing failed : '" << line << "'" << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "Parsing failed : '" << line << "'" << std::endl;
            return 1;
        }
    }
    return 0;
}

int nodeParsing(std::string line) {
    std::string seg;
    for (int i = 5; line[i] != '\n' && line[i] != '\0' && line[i] != ' '; i++)
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
    float lenght = 0;
    int i = 5;
    while (line[i] != '\n' && line[i] != '\0' && line[i] != ' ') {
        nodeA += line[i];
        i++;
    }
    i++;
    while (line[i] != '\n' && line[i] != '\0' && line[i] != ' ') {
        nodeB += line[i];
        i++;
    }
    i++;
    while (line[i] != '\n' && line[i] != '\0' && line[i] != ' ') {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
            lenghtS += line[i];
        }
        else
            return 1;
        i++;
    }
    if (!lenghtS.empty())
        lenght = std::stof(lenghtS);
    if ((lenght == 0 || nodeA.empty() || nodeB.empty() || lenghtS.empty()) || (line.size() > i))
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
    std::string rates;
    std::string times;
    std::string node;
    float rate = 0;
    float time = 0;
    int i = 6;



    return 0;
}

int trainParsing(std::ifstream &file) {
    std::string line;
    
    while(getline(file, line)) {

    }
    return 0;
}