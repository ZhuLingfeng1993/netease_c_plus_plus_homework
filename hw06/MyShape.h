//
// Created by zhulingfeng on 19-2-5.
//

#ifndef MYSHAPE_H
#define MYSHAPE_H

#include "Screen.h"

class MyShape {
 public:
  MyShape();
  void setColor(int r, int g, int b);
  void setScreen(const Screen &screen);
  virtual void Draw() = 0;
  int getR() const;
  int getG() const;
  int getB() const;
  const Screen *getScreen() const;
 private:
  const Screen* screen_; /**< screen to be draw shape */

  int r_;
  int g_;
  int b_;

  std::string enter_;
  std::string leave_;
};

#endif //MYSHAPE_H
