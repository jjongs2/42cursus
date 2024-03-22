#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

namespace ft {

enum ContainerIndex {
  kVector,
  kMap,
};
enum ErrorIndex {
  kPrefix,
  kInfix,
  kRange,
  kLength,
};

const int kNumOfContainers = 2;
const int kNumOfErrors = 4;

const std::string kContainerTypes[kNumOfContainers] = {"vector", "map"};
const std::string kErrors[kNumOfErrors] = {"Error: ", " ", "index out of range",
                                           "exceed length limit"};

}  // namespace ft

#endif
