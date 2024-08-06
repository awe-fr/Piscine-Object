#include "./../Includes/Header.h"

int main(int ac, char **av) {
    if (ac != 3) {
        std::cerr << "[exec] [Train Composition] [Rail Network]" << std::endl;
        exit(1);
    }
    checkFile(av);

    assignTravel();

    Simulation *sim = new Simulation();
	sim->StartSimulation();
    delete sim;

    clearSingletons();
    return 0;
}