#include <iostream>
#include <opencv2/opencv.hpp>

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

void MyRectangle::
setColor(int r, int g, int b) {
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
  std::cout << "myRectangle: " <<
            cv::Rect(x1_, y1_, w, h) << std::endl;

  setScreen(*Screen::getInstance());
  cv::Mat graph(screen_->getHeight(), screen_->getWidth(),
                CV_8UC3, cv::Scalar(0, 0, 0));
  cv::rectangle(graph, cv::Point(x1_, y1_),
                cv::Point(x2_, y2_),
                cv::Scalar(b_, g_, r_));
  screen_->showGraph(graph);
  cv::waitKey(0); // need this even if there's one in showGraph

  std::cout << r_ << " " << g_ << " " << b_ << std::endl;

}
