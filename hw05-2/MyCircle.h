//
// Created by zhulingfeng on 19-2-4.
//

#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "Screen.h"

class MyCircle {
 public:
  MyCircle(int x, int y, int radius);
  MyCircle();
//  MyCircle(const MyCircle&);
  void setColor(int r, int g, int b);
  void setRadius(int radius);
  void setCenter(int x, int y);
  void setScreen(const Screen &screen);
  void Draw();

 private:
  int x_;
  int y_;
  int radius_;

  int r_;
  int g_;
  int b_;

  const Screen* screen_;

  // solution 2:
  void init(int x, int y, int radius);
};

#endif //MYCIRCLE_H
