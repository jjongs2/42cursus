#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfRange {
  kHigh,
  kLow,
};

const int kDefault = 0;
const int kHighLow = 2;
const int kGradeRange[kHighLow] = {1, 150};

const std::string kUndefined = "undefined";

#endif
