#ifndef ITER_HPP_
#define ITER_HPP_

#include <iostream>

template <typename T>
void iter(T array[], int size, void (*function)(T&)) {
  for (int i = 0; i < size; ++i) {
    function(array[i]);
  }
}

template <typename T>
void iter(const T array[], int size, void (*function)(const T&)) {
  for (int i = 0; i < size; ++i) {
    function(array[i]);
  }
}

template <typename T>
void print(const T array[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i];
  }
  std::cout << '\n';
}

#endif
