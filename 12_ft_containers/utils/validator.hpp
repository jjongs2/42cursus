#ifndef VALIDATOR_HPP_
#define VALIDATOR_HPP_

#include <stdexcept>
#include <string>

#include "exception.hpp"

namespace ft {

struct validator {
  template <typename T>
  static void vector_range(const T& index, const T& size) {
    if (index >= size) {
      throw out_of_range(kVector);
    }
  }

  template <typename T>
  static void vector_capacity(const T& capacity, const T& max_size) {
    if (capacity > max_size) {
      throw length_error(kVector);
    }
  }
};

}  // namespace ft

#endif
