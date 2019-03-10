//
// Created by zhulingfeng on 19-2-4.
//

#ifndef MY_CIRCLE_H
#define MY_CIRCLE_H

#include "Screen.h"
#include "MyShape.h"

class MyCircle : public MyShape {
 public:
  MyCircle(int x, int y, int radius);
  MyCircle();
//  MyCircle(const MyCircle&);
  void setRadius(int radius);
  void setCenter(int x, int y);
  virtual void Draw();

 private:
  int x_;
  int y_;
  int radius_;

  /**
   * @brief initialize function tobe called by constructor.
   */
  void init(int x, int y, int radius);
};

#endif //MY_CIRCLE_H
