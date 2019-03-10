//
// Created by zhulingfeng on 19-2-4.
//
#include <iostream>
#include "MyCircle.h"
#include "Screen.h"

void MyCircle::init(int x, int y, int radius){
  x_ = x;
  y_ = y;
  radius_ = radius;
  std::cout << "my circle" << std::endl;
}

MyCircle::MyCircle(int x, int y, int radius) : MyShape() {
  init(x, y, radius);
}

MyCircle::MyCircle() : MyShape() {
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
  std::cout << "Draw circle: \n";
  std::cout << "(x,y,radius) = " << x_ << " " << y_ << " "<< radius_ << std::endl;
  int r = this -> getR();
  int g = this -> getG();
  int b = this -> getB();
  std::cout << "(r,g,b)= " << r << " " << g << " " << b << std::endl;

  this -> setScreen(*Screen::getInstance());
  const Screen* screen = this -> getScreen();
  cv::Mat graph(screen->getHeight(), screen->getWidth(),
                CV_8UC3, cv::Scalar(0, 0, 0));
  cv::circle(graph, cv::Point(x_, y_), radius_, cv::Scalar(b, g, r));
  screen->showGraph(graph);
}
