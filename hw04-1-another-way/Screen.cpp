#include <iostream>
#include <cstdlib>

#include "Screen.h"

Screen::Screen(int width, int height) {
  if (width <= 0 || width > 1024 ||
      height <= 0 || height > 1024) {
    std::cout << "invalid screen size" << std::endl;
    exit(0);
  }

  width_ = width;
  height_ = height;
  std::cout << "screen" << std::endl;
}

Screen::Screen() {
  Screen(640, 480);
}

int Screen::getWidth() const {
  return width_;
}

int Screen::getHeight() const {
  return height_;
}
