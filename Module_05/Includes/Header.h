#pragma once

#include <fstream>
#include <bits/stdc++.h>
#include <map>

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
int eventAssign(std::string reason, float rate, float time, std::string node);
int trainCut(std::string line);
int trainAssign(std::string name, std::string a, std::string b, float acc, float brake, float hour);

void assignTravel();
void findPath(Train *train);
Rail *getRail(Node *a, Node *b);

void clearSingletons();