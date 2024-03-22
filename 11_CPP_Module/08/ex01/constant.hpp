#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfErrors {
  kPrefix,
  kRange,
  kOverflow,
  kNoSpan,
  kReverse,
};

const int kNumOfErrors = 5;
const int kSpanSize = 42004;

const std::string kErrors[kNumOfErrors] = {
    "Error: ", "Container index out of range", "Container size overflow",
    "No span can be found", "Last is not reachable from first"};

#endif
