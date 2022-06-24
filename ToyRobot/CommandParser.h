#pragma once
#include <string>
#include <vector>

class CommandParser
{
public:
  CommandParser(std::vector<std::string>commands);
  ~CommandParser();
  void parseCommand(std::string input);
  std::string getCommand();
  std::vector<std::string> getArguments();
  bool isCommandValid();

 private:
  std::string strMakeUpper(std::string input);

  std::string command;
  std::vector<std::string> validCommands;
  std::vector<std::string> arguments;
};