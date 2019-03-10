#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

#include "Screen.h"

int Screen::width_ = 0;
int Screen::height_ = 0;
Screen* Screen::instance_ = 0;

Screen::Screen() {
  enter_ = "enter screen";
  leave_ = "leave screen";
  std::cout << enter_ << std::endl;

  cv::namedWindow(name_);
  cv::Mat graph(height_, width_, CV_8U, cv::Scalar(0,0,0));
  showGraph(graph);
}

Screen::Screen(const Screen&){

}

Screen::~Screen() {
  std::cout<< leave_ << std::endl;
  cv::destroyWindow(name_);
}

int Screen::getWidth() const {
  return width_;
}

int Screen::getHeight() const {
  return height_;
}

Screen* Screen::getInstance(int width, int height) {
  if(instance_ == 0){
    if (width <= 0 || width > 1024 ||
        height <= 0 || height > 1024) {
      std::cout << "invalid screen size" << std::endl;
      exit(0);
    }

    width_ = width;
    height_ = height;

    instance_ = new Screen();
  }

  return instance_;
}

void Screen::deleteInstance(){
  delete instance_;
}

void Screen::showGraph(const cv::Mat& graph) const{
  cv::imshow(name_, graph);
  cv::waitKey(0);
}