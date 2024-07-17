#pragma once

#include <fstream>

#include "Event.hpp"
#include "Node.hpp"
#include "Rail.hpp"
#include "Train.hpp"
#include "Singleton.hpp"

void checkFile(char **filePath);
void trainParsing(std::ifstream &file);
void railParsing(std::ifstream &file);
void nodeParsing(std::string line);
void railParsing(std::string line);
void eventParsing(std::string line);

void clearSingletons();