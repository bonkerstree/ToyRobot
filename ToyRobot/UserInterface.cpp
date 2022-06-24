#include "UserInterface.h"

UserInterface::UserInterface()
{
  
}

UserInterface::~UserInterface()
{
  
}

std::string UserInterface::getInput()
{
  std::string input;
  std::getline(std::cin, input);

  return input;
}

void UserInterface::displayOutput(std::string output)
{
  std::cout << output;
}

void UserInterface::displayInitialPrompt()
{
  std::cout << "\nPlease provide a command. Available commands:\n  PLACE\n  EXIT\n\n";
}

void UserInterface::displayPrompt()
{
  std::cout << "\nPlease provide a command. Available commands:\n  PLACE\n  MOVE\n  LEFT\n  RIGHT\n  REPORT\n  EXIT\n\n";
}