#pragma once

class Point {
public:
  Point();
  Point(int px, int py);
  ~Point();
  int x;
  int y;
  bool operator==(Point point);
};