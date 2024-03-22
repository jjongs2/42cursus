#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <stdexcept>

#include "constant.hpp"

namespace ft {

class out_of_range : public std::out_of_range {
 public:
  explicit out_of_range(const int container_type)
      : std::out_of_range(kErrors[kPrefix] + kContainerTypes[container_type] +
                          kErrors[kInfix] + kErrors[kRange]) {}
};

class length_error : public std::length_error {
 public:
  explicit length_error(const int container_type)
      : std::length_error(kErrors[kPrefix] + kContainerTypes[container_type] +
                          kErrors[kInfix] + kErrors[kLength]) {}
};

}  // namespace ft

#endif
