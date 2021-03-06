#ifndef MY_RECTANGLE_H
#define MY_RECTANGLE_H

#include <iostream>
#include "Screen.h"

class MyRectangle{
private:
    const Screen* screen_;
    int x1_;
    int y1_;
    int x2_;
    int y2_;

public:
    MyRectangle(int x1, int y1, int x2, int y2, Screen* screen)
            :x1_(x1), y1_(y1), x2_(x2), y2_(y2), screen_(screen){
        std::cout<<"myRectangle\n";
    }

    MyRectangle(){
        MyRectangle(0, 0, 0, 0, NULL);
    }

    void setCoordinates(int x1, int y1, int x2, int y2){
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
    }

    void setScreen(const Screen& screen){
        screen_ = &screen;
    }

    void Draw(){
        bool isValid = false;

        // 左上顶点和右上顶点相对位置是否合理
        if(x1_ < x2_ && y1_ < y2_) {
            // screen对象是否为空
            if (screen_ != 0) {
                // rectangle与screen是否相交
                if (x1_ > 0 && y1_ > 0 &&
                    x2_ < screen_->getWidth() &&
                    y2_ < screen_->getHeight())
                    isValid = true;
            }
        }

        if(isValid){
            int w = x2_ - x1_;
            int h = y2_ - y1_;
            std::cout<<x1_<<" "<<y1_<<" "<<
                     w<<" "<<h<<std::endl;
        }
        else
            std::cout<<"invalid myRectangle"<<std::endl;
    }
};

#endif