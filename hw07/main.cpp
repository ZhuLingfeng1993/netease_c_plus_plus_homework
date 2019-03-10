//
// Created by zhulingfeng on 19-3-2.
//
#include <iostream>
#include <string>
#include <fstream>

#include "Screen.h"

using namespace std;

/**
 * 用 string 对象保存文件名 "screen.txt"；然后创建 fstream 对象，再调用open函数，使用读写模式打开文件。

使用读写模式打开的文件，如果文件不存在，则会打开失败。在这种情况下需要使用单独的“写模式”打开文件然后再关闭该文件，即可创建一个长度为0的空文件。然后再以读写模式打开该文件。

从打开的文件中，读取屏幕的宽和高。如果读取失败，则从键盘读入屏幕的宽和高。同时，要清除文件流的状态位，否则后面的所有文件操作代码均会失败。

保留原 main() 函数中的代码：

    screen = Screen::getInstance(width, height);
    screen = Screen::getInstance();

 5. 在文件的头部开始，写入屏幕的宽(screen->getWidth())和屏幕的高度(screen->getHeight())

 6. 如果写文件出错，则提示错误信息然后关闭文件并返回-1

 7. 从文件中读取刚刚写入的屏幕的宽和高，然后显示到屏幕上

 8. 最后关闭文件
 * @return
 */
int main() {
  int width, height;

  std::string screenFile = "screen.txt";
  fstream fs;

  // Try open file.
  fs.open(screenFile.c_str(), ios::in | ios::out);
  if (fs.fail()) {
    // Create empty file and reopen.
    fs.open(screenFile.c_str(), ios::out);
    fs.close();
    cout << "File not exits, create new one: " << screenFile << endl;
    fs.open(screenFile.c_str(), ios::in | ios::out);
  }
  // Try read from file.
  // fs.seekg(ios::end);
  fs >> width >> height;
  if (fs.fail()) {
    // Clear stream state bit
    cout << "Can't read from file." << endl;
    fs.clear();
    // Read from console.
    cout << "Please input width and height: " ;
    cin >> width >> height;
  } else
    cout << "Read from file successful." << endl;

  // Get Screen instance.
  Screen* screen = 0;
  screen = Screen::getInstance(width, height);
  screen = Screen::getInstance();

  // Try write to file.
  fs.seekp(ios::beg);
  // fs << screen->getWidth() << " " << screen->getHeight();
  fs << 1;
  if (fs.fail()) {
    cout << "Write failed" << endl;
    fs.close();
    return -1;
  } else
    cout << "Write to file successful!" << endl;

  // Try read from file.
  fs.seekg(ios::beg);
  cout << "Read from file: ";
  fs >> width >> height;
  cout << screen->getWidth() << " " <<
      screen->getHeight() << endl;

  fs.close();

// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
// #if ( defined(__DEBUG__) || defined(_DEBUG) )
//   cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     cin.get();
// #endif

  return 0;
}