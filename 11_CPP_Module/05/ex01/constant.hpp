#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfFormInfo {
  kTitle,
  kName,
  kSign,
  kGradeToSign,
  kGradeToExec,
};
enum IndexOfRange {
  kHigh,
  kLow,
};

const int kDefault = 0;
const int kHighLow = 2;
const int kNumOfFormInfo = 5;
const int kGradeRange[kHighLow] = {1, 150};

const std::string kUndefined = "undefined";
const std::string kFormInfo[kNumOfFormInfo] = {
    "[ Form ]", "Name: ", "Sign: ", "Required Grade to Sign: ",
    "Required Grade to Execute: "};

#endif
