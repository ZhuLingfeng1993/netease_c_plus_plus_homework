#include <iostream>
#include "Screen.h"
#include "MyRectangle.h"

MyRectangle::MyRectangle(int x1, int y1,
                         int x2, int y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2),
    r_(255), g_(255), b_(255) {
  std::cout << "myRectangle\n";
}

MyRectangle::MyRectangle() {
  *this = MyRectangle(10, 10, 100, 100);
}

void MyRectangle::setCoordinates(int x1, int y1, int x2, int y2) {
  x1_ = x1;
  y1_ = y1;
  x2_ = x2;
  y2_ = y2;
}

void MyRectangle::setColor(int r, int g, int b) {
  r_ = r;
  g_ = g;
  b_ = b;
}

void MyRectangle::setScreen(const Screen &screen) {
  screen_ = &screen;
}

void MyRectangle::Draw() {
    int w = x2_ - x1_;
    int h = y2_ - y1_;
    std::cout << x1_ << " " << y1_ << " " <<
              w << " " << h << std::endl;

    std::cout << r_ << " " << g_ << " " << b_ << std::endl;

}
