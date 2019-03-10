#ifndef SCREEN_H
#define SCREEN_H

class Screen{
 public:
  Screen(int width, int height);

  Screen();

  int getWidth() const;

  int getHeight() const;

 private:
  int width_;
  int height_;
};

#endif