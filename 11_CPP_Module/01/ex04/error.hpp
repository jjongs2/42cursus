#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

enum IndexOfErrors {
  kArgument,
  kOpen,
};

const int kNumOfErrors = 2;

const std::string kErrorMessages[kNumOfErrors] = {"Invalid argument",
                                                  "File open failed"};

#endif
