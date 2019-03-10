#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <cstdlib>

class Screen{
public:
    Screen(int width, int height){
        if(width <=0 || width > 1024 ||
            height <=0 || height > 1024){
            std::cout<<"invalid screen size"<<std::endl;
            exit(0);
        }

        width_ = width;
        height_ = height;
        std::cout<<"screen"<<std::endl;
    }

    Screen(){
        Screen(640, 480);
    }

    int getWidth() const{
        return width_;
    }

    int getHeight() const{
        return height_;
    }

private:
    int width_;
    int height_;
};

#endif