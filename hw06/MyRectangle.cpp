#include <iostream>
#include <opencv2/opencv.hpp>

#include "Screen.h"
#include "MyRectangle.h"

MyRectangle::MyRectangle(int x1, int y1,
                         int x2, int y2)
    : MyShape(), x1_(x1), y1_(y1), x2_(x2), y2_(y2){
  std::cout << "myRectangle\n";
}

MyRectangle::MyRectangle() {
  // initialize by copying from an anonymous object.
  *this = MyRectangle(10, 10, 100, 100);
}

void MyRectangle::setCoordinates(int x1, int y1, int x2, int y2) {
  x1_ = x1;
  y1_ = y1;
  x2_ = x2;
  y2_ = y2;
}

void MyRectangle::Draw() {
  int r = this -> getR();
  int g = this -> getG();
  int b = this -> getB();
  std::cout << "Draw rectangle: \n";
  std::cout << "(r,g,b) = " << r << " " << g << " " << b << std::endl;

  int w = x2_ - x1_;
  int h = y2_ - y1_;
  std::cout << "coordinates = " <<
            cv::Rect(x1_, y1_, w, h) << std::endl;

  this -> setScreen(*Screen::getInstance());
  const Screen* screen = this -> getScreen();
  cv::Mat graph(screen->getHeight(), screen->getWidth(),
                CV_8UC3, cv::Scalar(0, 0, 0));
  cv::rectangle(graph, cv::Point(x1_, y1_),
                cv::Point(x2_, y2_),
                cv::Scalar(b, g, r));
  screen->showGraph(graph);
}
