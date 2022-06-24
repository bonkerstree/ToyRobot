#include "MainApp.h"

typedef void (*actionFuncPtr)(std::vector<std::string>);

std::map <std::string, actionFuncPtr> commandActionMap = 
{
  {"EXIT",   doNothing},
  {"PLACE",  place},
  {"MOVE",   move},
  {"LEFT",   left},
  {"RIGHT",  right},
  {"REPORT", report}
};

ToyRobot robot;
UserInterface ui;
bool isRobotPlaced = false;

int main()
{
  robot.setBounds(5, 5);

  std::vector<std::string>commandList;
  for(auto &mapping : commandActionMap)
  {
    commandList.push_back(mapping.first);
  }

  CommandParser parser(commandList);
  while(1)
  {
    if(!isRobotPlaced)
    {
      ui.displayInitialPrompt();
    }
    else
    {
      ui.displayPrompt();
    }

    parser.parseCommand(ui.getInput());

    if(parser.isCommandValid())
    {
      std::string command = parser.getCommand();
      std::vector<std::string> arguments = parser.getArguments();

      if(command == "EXIT")
      {
        break;
      }

      if(!isRobotPlaced)
      {
        if(command != "PLACE")
        {
          ui.displayOutput("Invalid command: \"" + command + "\". Please first use the PLACE command to place the robot on the table.\n");
        }
        else
        {
          commandActionMap[command](arguments);
        }
      }
      else
      {
        commandActionMap[command](arguments);
      }
    }
    else
    {
      ui.displayOutput("Invalid command: \"" + parser.getCommand() + "\". Please try again.\n");
    }
  }

  return 0;
}

void doNothing(std::vector<std::string>arguments)
{
  // do nothing
}

void place(std::vector<std::string>arguments)
{
  bool checkOk = true;

  if(arguments.size() >= 3)
  { 
    Point pt(-1,-1);

    try
    {
      pt = Point(std::stoi(arguments.at(0)), std::stoi(arguments.at(1)));
    }
    catch (const std::invalid_argument&)
    {
      checkOk = false;
      ui.displayOutput("X,Y arguments are invalid. They should be integers.\n");
    }
    
    std::string orientation = arguments.at(2);
    if(checkOk)
    {
      if(!robot.checkBounds(pt))
      {
        checkOk = false;
        ui.displayOutput("X,Y arguments provided go beyond the allowed bounds\n");
      }
    
      if(!ToyRobot::isValidOrientation(orientation))
      {
        checkOk = false;
        ui.displayOutput("DIRECTION argument provided is invalid. Should be NORTH, SOUTH, EAST or WEST.\n");
      }
    }

    if(checkOk)
    {
      robot.setPosition(pt);
      robot.setOrientation(orientation);
      isRobotPlaced = true;
    }
  }
  else
  {
    ui.displayOutput("Please provide 3 arguments for PLACE: X,Y,DIRECTION\n");
  }
}

void move(std::vector<std::string>arguments)
{
  if(!robot.moveForward())
  {
    ui.displayOutput("Unable to move. Robot will go beyond the bounds of the table.\n");
  }
}

void left(std::vector<std::string>arguments)
{
  robot.rotateLeft();
}

void right(std::vector<std::string>arguments)
{
  robot.rotateRight();
}

void report(std::vector<std::string>arguments)
{
  std::string output("Output: "
                      + std::to_string(robot.getPosition().x)
                      + ", " + std::to_string(robot.getPosition().y)
                      + ", " + robot.getOrientationStr() + "\n\n");
  ui.displayOutput(output);
}

