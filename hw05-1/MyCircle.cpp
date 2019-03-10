//
// Created by zhulingfeng on 19-2-4.
//
#include <iostream>
#include "MyCircle.h"

void MyCircle::setColor(int r, int g, int b) {
  r_ = r;
  g_ = g;
  b_ = b;
}

// solution 1:
//MyCircle::MyCircle(int x, int y, int radius) :
//  x_(x), y_(y), radius_(radius), r_(255), g_(255), b_(255) {
//  std::cout << "my circle" << std::endl;
//}
//
//MyCircle::MyCircle() {
////  *this = MyCircle(200, 200, 100);
//  MyCircle(200, 200, 100);
//}

// solution 2:
void MyCircle::init(int x, int y, int radius){
  x_ = x;
  y_ = y;
  radius_ = radius;
  r_ = 255;
  g_ = 255;
  b_ = 255;
  std::cout << "my circle" << std::endl;
}

MyCircle::MyCircle(int x, int y, int radius) {
  init(x, y, radius);
}

MyCircle::MyCircle() {
  init(200, 200, 100);
}

//MyCircle::MyCircle(const MyCircle &) {
//
//}

void MyCircle::setCenter(int x, int y) {
  x_ = x;
  y_ = y;
}

void MyCircle::setRadius(int radius) {
  radius_ = radius;
}

void MyCircle::Draw() {
  std::cout << x_ << " " << y_ << " "<< radius_ << std::endl;
  std::cout << r_ << " " << g_ << " " << b_ << std::endl;
}
