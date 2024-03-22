#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfErrors {
  kPrefix,
  kNOENT,
};

const int kNumOfErrors = 2;

const std::string kErrors[kNumOfErrors] = {"Error: ", "No such element"};

#endif
