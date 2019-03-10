#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

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
        std::cout<<name_<<std::endl;

        cv::namedWindow(name_);
        cv::Mat graph(height_, width_, CV_8U, cv::Scalar(0,0,0));
        showGraph(graph);

    }

    Screen(){
        Screen(640, 480);
    }

    ~Screen(){
        cv::destroyWindow(name_);
    }

    int getWidth() const{
        return width_;
    }

    int getHeight() const{
        return height_;
    }

    void showGraph(const cv::Mat& graph) const{
        cv::imshow(name_, graph);
        cv::waitKey(0);
    }
private:
    int width_;
    int height_;
    std::string name_ = "screen";
};

#endif