#ifndef MY_RECTANGLE_H
#define MY_RECTANGLE_H

#include "Screen.h"
#include "MyShape.h"

class MyRectangle : public MyShape {
 private:
  int x1_;
  int y1_;
  int x2_;
  int y2_;

 public:
  MyRectangle(int x1, int y1, int x2, int y2);

  MyRectangle();

  void setCoordinates(int x1, int y1, int x2, int y2);
  virtual void Draw();
};

#endif