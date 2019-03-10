#ifndef MY_RECTANGLE_H
#define MY_RECTANGLE_H

#include "Screen.h"

class MyRectangle {
 private:
  const Screen *screen_;
  int x1_;
  int y1_;
  int x2_;
  int y2_;

  int r_;
  int g_;
  int b_;

 public:
  MyRectangle(int x1, int y1, int x2, int y2);

  MyRectangle();

  void setCoordinates(int x1, int y1, int x2, int y2);
  void setColor(int r, int g, int b);
  void setScreen(const Screen &screen);
  void Draw();
};

#endif