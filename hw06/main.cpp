#include <iostream>
#include <typeinfo>

#include "Screen.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include "MyShape.h"

#define HW07

#ifdef HW07
#include <fstream>
#endif

using namespace std;

MyShape* createShape(char shapeType) {
  if (shapeType == 'c')
    return new MyCircle;
  if (shapeType == 'r')
    return new MyRectangle;
  return 0;
}
#ifdef HW07
bool readShapes(fstream& binaryFs, std::vector<MyShape*>& shapes) {
  // Input check.
  if (binaryFs.fail()) {
    cout << "Input param binaryFs is failed.\n";
    return false;
  }

  char temp;
  binaryFs.read(&temp, 1);
  if (binaryFs.fail()) {
    cout << "Input param binaryFs is empty file. \n";
    return false;
  }
  binaryFs.seekg(-1L, ios::cur);

  if (shapes.size() != 0) {
    cout << "Input param shapes is not empty.\n";
    return false;
  }

  char shapeType;

  // Read shape one by one
  while (!binaryFs.eof()) {
    // Read shape type
    // binaryFs.read(reinterpret_cast<char*>(&shapeType), sizeof(shapeType));
    binaryFs.read(&shapeType, 1);
    if (binaryFs.fail()) {
      cout << "EOF. \n";
      return true;
    }

    // Create shape and add in shapes.
    MyShape* shape = createShape(shapeType);
    if (!shape) {
      cout << "Invalid shape type: " << shapeType << endl;
      return false;
    }
    shapes.push_back(shape);

    if (shapeType == 'r') { // Read rectangle.
      binaryFs.read(reinterpret_cast<char* >(&shape), sizeof(MyRectangle));
    } else if (shapeType == 'c') { // Read circle
      binaryFs.read(reinterpret_cast<char* >(&shape), sizeof(MyCircle));
    } else {
      cout << "Invalid shape type: " << shapeType << endl;
      return false;
    }
    if (binaryFs.fail()) {
      cout << "Failed to read shape. \n";
      return false;
    }
  }

  return true;
}

bool writeShapes(fstream& binaryFs, std::vector<MyShape*>& shapes) {
  // Input check.
  if (binaryFs.fail()) {
    cout << "Input param binaryFs is failed.\n";
    return false;
  }
  // if (shapes.empty()) {
  //   cout << "Intput param shapes is empty.\n";
  //   return false;
  // }

  char shapeType;
  MyCircle* mycircle;
  MyRectangle* myrectangle;

  // Write shape one by one
  for (int i = 0; i < shapes.size(); ++i) {
    // Try cast shape
    mycircle = dynamic_cast<MyCircle*>(shapes[i]);
    myrectangle = dynamic_cast<MyRectangle*>(shapes[i]);

    if (mycircle != 0 || myrectangle != 0) { // cast shape success.
      // if (typeid(*shapes[i]) == typeid(MyCircle)) {
      if (mycircle != 0) { // write circle
        shapeType = 'c';
        binaryFs.write(&shapeType, 1);
        binaryFs.write(reinterpret_cast<char*>(&mycircle), sizeof(MyCircle));
      } else { // write rectangle
        shapeType = 'r';
        binaryFs.write(&shapeType, 1);
        binaryFs.write(reinterpret_cast<char*>(&myrectangle), sizeof
            (MyRectangle));
      }
      if (binaryFs.fail()) {
        cout << "Failed to write shape. \n";
        return false;
      }
    } else {
      cout << "Invalid shape type.\n";
      return false;
    }
  }

  return true;
}

void drawShapes(std::vector<MyShape*> shapes) {
  Screen::getInstance();
  Screen::getInstance();

  MyRectangle* myrectangle;
  MyCircle* mycircle;
  for (int i = 0; i < shapes.size(); i++) {
    mycircle = dynamic_cast<MyCircle*>(shapes[i]);
    myrectangle = dynamic_cast<MyRectangle*>(shapes[i]);
    if ((mycircle != 0) || (myrectangle != 0)) {
      shapes[i]
          ->setColor(100 + i, 100 + 20 * i, 100 + 30 * i);
      // if (typeid(*shapes[i]) == typeid(MyRectangle)) {
      if (myrectangle != 0) {
        myrectangle->setCoordinates(10 + 50 * i, 10 + 50 * i, 400 + 50 * i,
                                    200 + 50 * i);
      } else {
        mycircle->setCenter(200 + 50 * i, 200 + 50 * i);
        mycircle->setRadius(50 + 20 * i);
      }
      shapes[i]->Draw();
    } else {
      cout << "Invalid shape when cast shape." << endl;
    }
  }

  Screen::deleteInstance();
}

int main() {
  std::string shapeFile = "shapes.data";
  fstream fs;

  // Try open file.
  fs.open(shapeFile.c_str(), ios::in | ios::out | ios::binary);
  if (fs.fail()) {
    cout << "File not exits, create new one: " << shapeFile << endl;
    // Create new file.
    fs.open(shapeFile.c_str(), ios::out);
    fs.close();
    fs.open(shapeFile.c_str(), ios::in | ios::out | ios::binary);
  }

  // Try read shape from file.
  fs.seekg(ios::beg);
  std::vector<MyShape*> shapes;
  if (readShapes(fs, shapes)) {
    cout << "Read shape from file successful." << endl;
  } else {
    // Clear stream state bit
    cout << "Read shape from file failed." << endl;
    fs.clear();
    // Read shapes from console.
    char shapeType = 's';
    do { // input 'e' to finish input
      cout << "input shape type(c or r): " << endl;
      cin >> shapeType;
      MyShape* shape = createShape(shapeType);
      if (!shape) {
        cout << "Invalid shape type: " << shapeType << endl;
        continue;
      }
      shapes.push_back(shape);
    } while (shapeType != 'e');

    cout << "Read shape from console finished.\n\n";
  }

  drawShapes(shapes);
  cout << endl;

  // Try write shapes to file.
  fs.seekp(ios::beg);
  if (writeShapes(fs, shapes)) {
    cout << "Write shapes to file successful!" << endl;
  } else {
    cout << "Write shapes to file failed" << endl;
    fs.close();
    return -1;
  }

  for (int i = 0; i < shapes.size(); i++) {
    delete shapes[i];
  }

  std::vector<MyShape*> shapesFromFile;

  // Try read from file.
  fs.seekg(ios::beg);
  if (readShapes(fs, shapesFromFile)) {
    // print shapes
    cout << "Read shape from file successful." << endl;
  } else {
    cout << "Read shape from file failed." << endl;
  }

  fs.close();

  cin.get();
  return 0;

}
#endif

#ifdef HW06
int main() {
  const int SHAPE_NUMBER = 5;
  Screen::getInstance();
  Screen::getInstance();

  char shapeType = 's';
  MyShape* shapes[SHAPE_NUMBER];
  for (int i = 0; i < SHAPE_NUMBER; i++) {
    cout << "input shape type(c or r)" << endl;
    cin >> shapeType;
    shapes[i] = createShape(shapeType);
  }

  MyRectangle* myrectangle;
  MyCircle* mycircle;
  for (int i = 0; i < SHAPE_NUMBER; i++) {
    mycircle = dynamic_cast<MyCircle*>(shapes[i]);
    myrectangle = dynamic_cast<MyRectangle*>(shapes[i]);
    if ((mycircle != 0) || (myrectangle != 0)) {
      shapes[i]
          ->setColor(shapeType + i, shapeType + 20 * i, shapeType + 30 * i);
      // if (typeid(*shapes[i]) == typeid(MyRectangle)) {
      if (myrectangle != 0) {
        myrectangle->setCoordinates(10 + 50 * i, 10 + 50 * i, 400 + 50 * i,
                                    200 + 50 * i);
      } else {
        mycircle->setCenter(200 + 50 * i, 200 + 50 * i);
        mycircle->setRadius(50 + 20 * i);
      }
      shapes[i]->Draw();
    } else {
      cout << "invalid shape" << endl;
    }
  }

  for (int i = 0; i < SHAPE_NUMBER; i++) {
    delete shapes[i];
  }

  Screen::deleteInstance();

  cin.get();
  return 0;
}
#endif