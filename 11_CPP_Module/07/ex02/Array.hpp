#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

#include "constant.hpp"

template <typename T>
class Array {
 public:
  Array() : size_(kDefault), array_(new T[kDefault]) {}

  explicit Array(const unsigned int n) : size_(n), array_(new T[this->size_]) {}

  Array(const Array& origin) : size_(0), array_(NULL) { *this = origin; }

  Array& operator=(const Array& origin) {
    if (this != &origin) {
      const unsigned int origin_size = origin.size();
      if (this->size_ != origin_size) {
        this->size_ = origin_size;
        delete[] this->array_;
        this->array_ = new T[origin_size];
      }
      for (unsigned int i = 0; i < this->size_; ++i) {
        this->array_[i] = origin[i];
      }
    }
    return *this;
  }

  virtual ~Array() {
    delete[] this->array_;
    this->array_ = NULL;
  }

  T& operator[](const unsigned int index) {
    if (index >= this->size_) {
      throw std::out_of_range(kErrors[kRANGE]);
    }
    return this->array_[index];
  }

  const T& operator[](const unsigned int index) const {
    if (index >= this->size_) {
      throw std::out_of_range(kErrors[kRANGE]);
    }
    return this->array_[index];
  }

  unsigned int size(void) const { return this->size_; }

  bool empty(void) const { return (this->size_ == 0) ? true : false; }

  void print(const std::string& title,
             unsigned int max_print = kMaxPrint) const {
    std::cout << "[ " << title << " ]" << '\n';
    const unsigned int size =
        (this->size_ > max_print) ? max_print : this->size_;
    for (unsigned int i = 0; i < size; ++i) {
      std::cout << this->array_[i];
      if (i == size - 1) break;
      std::cout << ", ";
    }
    std::cout << "\n\n";
  }

 private:
  unsigned int size_;
  T* array_;
};

#endif
