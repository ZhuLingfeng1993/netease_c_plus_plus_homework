#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen{
 public:
  int getWidth() const;

  int getHeight() const;

  static Screen* getInstance(int width = 640, int height = 480);

  static void deleteInstance();

 private:
  static int width_;
  static int height_;
  static Screen* instance_;
  std::string enter_;
  std::string leave_;

  Screen();

  Screen(const Screen&);

  ~Screen();

};

#endif