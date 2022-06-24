#pragma once
#include <string>
#include <vector>
#include <map>
#include "UserInterface.h"
#include "ToyRobot.h"
#include "CommandParser.h"


void doNothing(std::vector<std::string>arguments);
void place(std::vector<std::string>arguments);
void move(std::vector<std::string>arguments);
void left(std::vector<std::string>arguments);
void right(std::vector<std::string>arguments);
void report(std::vector<std::string>arguments);