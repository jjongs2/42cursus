#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfErrors {
  kPrefix,
  kRANGE,
};

const int kArraySize = 750;
const int kDefault = 0;
const int kMaxPrint = 10;
const int kNumOfErrors = 2;

const std::string kErrors[kNumOfErrors] = {"Error: ",
                                           "Array index out of range"};

#endif
