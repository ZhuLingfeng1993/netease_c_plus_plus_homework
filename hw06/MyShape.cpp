//
// Created by zhulingfeng on 19-2-5.
//

#include "MyShape.h"
MyShape::MyShape() : enter_("enter myShape"), leave_("leave myShape")
{
  r_ = 255;
  g_ = 255;
  b_ = 255;
  std::cout << "my shape" << std::endl;
}

int MyShape::getR() const {
  return r_;
}

int MyShape::getG() const {
  return g_;
}

int MyShape::getB() const {
  return b_;
}

void MyShape::setColor(int r, int g, int b) {
  r_ = r;
  g_ = g;
  b_ = b;
}

const Screen *MyShape::getScreen() const {
  return screen_;
}

void MyShape::setScreen(const Screen &screen) {
  screen_ = &screen;
}
