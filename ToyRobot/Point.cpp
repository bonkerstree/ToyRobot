#include "Point.h"

Point::Point()
{
  x = 0;
  y = 0;
}

Point::Point(int px, int py)
{
  x = px;
  y = py;
}

Point::~Point()
{
  
}

bool Point::operator==(Point point)
{
  return ( (point.x == this->x) && (point.y == this->y) );
}