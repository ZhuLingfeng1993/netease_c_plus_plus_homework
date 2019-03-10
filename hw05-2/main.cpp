#include <iostream>

#include "Screen.h"
#include "MyRectangle.h"
#include "MyCircle.h"
using namespace std;
/*
1000 1000
 100 100 200 200
 100 200 300
 */
int main() {
    int width, height;
    cin >> width >> height;
    Screen::getInstance(width, height);
    Screen::getInstance();

    int leftX, leftY, rightX, rightY;
    cin >> leftX >> leftY >> rightX >> rightY;
    MyRectangle myRectangle(leftX, leftY, rightX, rightY);
    myRectangle.setColor(0, 0, 0xff);
    myRectangle.Draw();

    int centerX, centerY, radius;
    cin >> centerX >> centerY >> radius;
    MyCircle myCircles[2];
    (myCircles + 1)->setCenter(centerX, centerY);
    myCircles[1].setRadius(radius);
    myCircles[0].Draw();
    myCircles[1].Draw();

    MyCircle myCircle(myCircles[1]);
    myCircle.Draw();

    Screen::deleteInstance();

    cin.get();
    return 0;
}