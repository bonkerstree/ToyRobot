#include "CommandParser.h"
#include <regex>
#include <algorithm>

CommandParser::CommandParser(std::vector<std::string>commands)
{
  validCommands = commands;
}

CommandParser::~CommandParser()
{
  
}

void CommandParser::parseCommand(std::string input)
{
  std::string inputLine = strMakeUpper(input);
  std::string match;
  std::smatch matchResults;
  std::string token;

  // Trim spaces
  inputLine = std::regex_replace(inputLine, std::regex("^\\s+"), std::string(""));
  inputLine = std::regex_replace(inputLine, std::regex("\\s+$"), std::string(""));

  // Get the command
  std::regex_search(inputLine, matchResults, std::regex("[A-Za-z0-9]+\\s*"));
  command = matchResults.str();
  command = std::regex_replace(command, std::regex("\\s+$"), std::string(""));

  // Get the arguments
  arguments.clear();
  inputLine = matchResults.suffix();
  while(std::regex_search(inputLine, matchResults, std::regex("-*[A-Za-z0-9]+\\s*,*")))
  {
    token = matchResults.str();
    token = std::regex_replace(token, std::regex(",$"), std::string(""));
    token = std::regex_replace(token, std::regex("^,"), std::string(""));

    arguments.push_back(token);
    inputLine = matchResults.suffix();
  }
}

std::string CommandParser::strMakeUpper(std::string input)
{
  std::string output = input;
  std::transform(output.cbegin(),
                 output.cend(),
                 output.begin(),
                 [](unsigned char c) { return std::toupper(c);});

  return output;
}
  
bool CommandParser::isCommandValid()
{
  bool isValid = false;

  if(validCommands.empty())
  {
    return isValid;
  }

  for(auto &vc : validCommands)
  {
    if(vc == strMakeUpper(command))
    {
      isValid = true;
      break;
    }
  }

  return isValid;
}

std::string CommandParser::getCommand()
{
  return command;
}

std::vector<std::string> CommandParser::getArguments()
{
  return arguments;
}