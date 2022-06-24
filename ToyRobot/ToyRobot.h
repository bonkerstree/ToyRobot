#pragma once
#include "Point.h"
#include <string>

class ToyRobot
{
public:
  ToyRobot();
  ~ToyRobot();

  enum class Orientation {North, East, South, West};

  bool setPosition(int x, int y);
  bool setPosition(Point pt);
  Point getPosition();
  void setOrientation(Orientation orientation);
  void setOrientation(std::string orientationStr);
  static bool isValidOrientation(std::string orientationStr);
  void rotateLeft();
  void rotateRight();
  Orientation getOrientation();
  std::string getOrientationStr();
  bool moveForward();
  void setBounds(int length, int width);
  bool checkBounds(Point position);

private:
  Point currPosition;
  Point bounds;
  Orientation currOrientation;
  int moveStep;
};