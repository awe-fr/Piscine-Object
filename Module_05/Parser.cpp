#include "Header.h"

void checkFile(char **filePath) {
    std::ifstream trainFile(filePath[0]);
    std::ifstream railFile(filePath[1]);

    if(!trainFile.is_open() || !railFile.is_open()) {
        std::cerr << "File cannot be opened !" << std::endl;
        exit(1);
    }

    railParsing(railFile);
    trainParsing(trainFile);

    trainFile.close();
    railFile.close();  
    return;
}

void railParsing(std::ifstream &file) {
    std::string line;
    
    while(getline(file, line)) {
        std::string type;
        for (int i = 0; i < 0; i++) {
            type += line[i];
            if (type == "Node ")
                nodeParsing(line);
            else if (type == "Rail ")
                railParsing(line);
            else if (type == "Event")
                eventParsing(line);
            else {
                std::cerr << "Parsing failed : '" << line << "'" << std::endl;
                clearSingletons();
            }
        }
    }
}

void nodeParsing(std::string line) {

}

void railParsing(std::string line) {

}

void eventParsing(std::string line) {

}

void trainParsing(std::ifstream &file) {
    std::string line;
    
    while(getline(file, line)) {

    }

}