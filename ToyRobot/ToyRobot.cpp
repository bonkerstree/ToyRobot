#include "ToyRobot.h"
#include <map>

std::map<ToyRobot::Orientation, std::string>orientationMap = 
{
  { ToyRobot::Orientation::North, "NORTH" },
  { ToyRobot::Orientation::East,  "EAST"  },
  { ToyRobot::Orientation::South, "SOUTH" },
  { ToyRobot::Orientation::West,  "WEST"  },
};

ToyRobot::ToyRobot()
{
  currPosition    = Point(-1,-1);
  currOrientation = Orientation::North;
  moveStep        = 1;
  setBounds( 1, 1);
}

ToyRobot::~ToyRobot()
{
  
}

bool ToyRobot::setPosition(int x, int y)
{
  bool isValid = false;
  if(checkBounds(Point(x, y)))
  {
    currPosition = Point(x, y);
    isValid = true;
  }

  return isValid;
}

bool ToyRobot::setPosition(Point pt)
{
  bool isValid = false;
  isValid = setPosition(pt.x, pt.y);

  return isValid;
}

Point ToyRobot::getPosition()
{
  return currPosition;
}

void ToyRobot::setOrientation(Orientation orientation)
{
  currOrientation = orientation;
}

void ToyRobot::setOrientation(std::string orientationStr)
{
  for(auto &mapping : orientationMap)
  {
    if(mapping.second == orientationStr)
    {
      setOrientation(mapping.first);
    }
  }
}

/*static*/ bool ToyRobot::isValidOrientation(std::string orientationStr)
{
  bool isValid = false;

  for(auto &mapping : orientationMap)
  {
    if(mapping.second == orientationStr)
    {
      isValid = true;
      break;
    }
  }

  return isValid;
}

ToyRobot::Orientation ToyRobot::getOrientation()
{
  return currOrientation;
}

std::string ToyRobot::getOrientationStr()
{
  std::string orientationStr = orientationMap.at(currOrientation);
  return orientationStr;
}

bool ToyRobot::moveForward()
{
  bool isValid = false;
  Point newPosition;

  switch(currOrientation)
  {
    case Orientation::North:
    {
      newPosition = Point(getPosition().x, getPosition().y + moveStep);
      break;
    }
    case Orientation::East:
    {
      newPosition = Point(getPosition().x + moveStep, getPosition().y);
      break;
    }
    case Orientation::South:
    {
      newPosition = Point(getPosition().x, getPosition().y - moveStep);
      break;
    }
    case Orientation::West:
    {
      newPosition = Point(getPosition().x - moveStep, getPosition().y);
      break;
    }
    default:
      break;
  }

  if(checkBounds(newPosition))
  {
    setPosition(newPosition.x, newPosition.y);
    isValid = true;
  }

  return isValid;
}

void ToyRobot::setBounds(int length, int width)
{
  bounds = Point(length, width);
}

bool ToyRobot::checkBounds(Point position)
{
  bool isYWithinBounds = (position.y < bounds.y) && (position.y >= 0);
  bool isXWithinBounds = (position.x < bounds.x) && (position.x >= 0);

  return (isYWithinBounds && isXWithinBounds);
}

void ToyRobot::rotateLeft()
{
  int newOrientation = static_cast<int>(getOrientation()) - 1;
  if(newOrientation < 0)
  {
    newOrientation = static_cast<int>(Orientation::West);
  }

  setOrientation(static_cast<Orientation>(newOrientation));
}

void ToyRobot::rotateRight()
{
  int newOrientation = (static_cast<int>(getOrientation()) + 1) % 4;

  setOrientation(static_cast<Orientation>(newOrientation));
}