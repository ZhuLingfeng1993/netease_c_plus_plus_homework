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

 public:
  MyRectangle(int x1, int y1, int x2, int y2, Screen *screen);

  MyRectangle();

  void setCoordinates(int x1, int y1, int x2, int y2);

  void setScreen(const Screen &screen);
  void Draw();
};

#endif