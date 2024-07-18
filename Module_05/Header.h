#pragma once

#include <fstream>
#include <bits/stdc++.h>

#include "Event.hpp"
#include "Node.hpp"
#include "Rail.hpp"
#include "Train.hpp"
#include "Singleton.hpp"

void checkFile(char **filePath);
int trainParsing(std::ifstream &file);
int systempParsing(std::ifstream &file);
int nodeParsing(std::string line);
int railParsing(std::string line);
int railAssign(std::string nodeA,std::string nodeB, float lenght);
int eventParsing(std::string line);

void clearSingletons();