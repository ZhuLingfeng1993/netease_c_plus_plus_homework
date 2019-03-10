#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <opencv2/opencv.hpp>

class Screen{
 public:
  int getWidth() const;

  int getHeight() const;

  static Screen* getInstance(int width = 640, int height = 480);

  static void deleteInstance();
  void showGraph(const cv::Mat& graph) const;
 private:
  static int width_;
  static int height_;
  static Screen* instance_;
  std::string name_ = "screen";
  std::string enter_;
  std::string leave_;

  Screen();

  Screen(const Screen&);

  ~Screen();

};

#endif