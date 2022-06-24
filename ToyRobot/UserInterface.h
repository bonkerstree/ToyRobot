#pragma once
#include <vector>
#include <string>
#include <iostream>

class UserInterface
{
public:
  UserInterface();
  ~UserInterface();
  std::string getInput();
  void displayOutput(std::string output);
  void displayInitialPrompt();
  void displayPrompt();
};