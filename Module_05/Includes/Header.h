#pragma once

#include <map>
#include <cmath>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

#include "Node.hpp"
#include "Rail.hpp"
#include "Event.hpp"
#include "Train.hpp"
#include "Clock.hpp"
#include "Singleton.hpp"
#include "Simulation.hpp"

class Rail;
class Node;
class Event;
class Train;

void checkFile(char **filePath);
int trainCut(std::string line);
int checkNode(std::string name);
int nodeParsing(std::string line);
int railParsing(std::string line);
int eventParsing(std::string line);
int trainParsing(std::ifstream &file);
int systempParsing(std::ifstream &file);
int railAssign(std::string nodeA,std::string nodeB, float lenght);
int eventAssign(std::string reason, float rate, float time, std::string node);
int trainAssign(std::string name, std::string a, std::string b, float acc, float brake, float hour);

void assignTravel();
void findPath(Train *train);
Rail *getRail(Node *a, Node *b);

void clearSingletons();