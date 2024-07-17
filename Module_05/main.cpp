#include "Header.h"

int main(char **av, int ac) {
    if (ac != 3) {
        std::cerr << "[Train Composition] [Rail Network]" << std::endl;
        exit(1);
    }
    checkFile(av);
}