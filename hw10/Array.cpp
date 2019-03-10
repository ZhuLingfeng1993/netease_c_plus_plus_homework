//
// Created by zhulingfeng on 19-3-10.
//

#include "Array.h"

template<typename T>
void Array<T>::sort() {

}

template<typename T>
int Array<T>::seek(T key) {
  return 0;
}

// explicit instantiation
template class Array<int>;
template class Array<double>;
template class Array<char>;