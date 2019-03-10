//
// Created by zhulingfeng on 19-3-10.
//

#ifndef NETEASEC_HOMEWORK_ARRAY_H
#define NETEASEC_HOMEWORK_ARRAY_H

#include <iostream>
#include <vector>

template <typename T>
class Array {
 public:
  Array(std::vector<T> v) {
    size_ = v.size();
    data_ = static_cast<T*> (new T[size_]);
    for (int i = 0; i < size_; i++) {
      data_[i] = v[i];
    }
  }

  ~Array() {
    for (int i = 0; i < size_; ++i) {
      delete (data_+i);
      // delete []data_;
    }
  }

  void sort();
  int seek(T key);

  void display() {
    int i;
    for (i = 0; i < size_; i++) {
      std::cout << data_[i];
      if (i != size_ - 1)
        std::cout << " ";  // 输出一个空格
    }
  }
 private:
  T* data_;
  int size_;
};


#endif //NETEASEC_HOMEWORK_ARRAY_H
