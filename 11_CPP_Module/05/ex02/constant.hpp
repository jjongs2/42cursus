#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfFormInfo {
  kTarget,
  kSign,
  kGradeToSign,
  kGradeToExec,
};
enum IndexOfFormTypes {
  kSC,
  kRR,
  kPP,
};
enum IndexOfRange {
  kHigh,
  kLow,
};
enum RequiredGrades {
  kSignSC = 145,
  kExecSC = 137,
  kSignRR = 72,
  kExecRR = 45,
  kSignPP = 25,
  kExecPP = 5,
};

const int kDefault = 0;
const int kHighLow = 2;
const int kNumOfFormInfo = 4;
const int kNumOfFormTypes = 3;
const int kGradeRange[kHighLow] = {1, 150};

const std::string kDrillingNoise =
    "VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR!";
const std::string kUndefined = "undefined";
const std::string kFormInfo[kNumOfFormInfo] = {
    "Target: ", "Sign: ", "Required Grade to Sign: ",
    "Required Grade to Execute: "};
const std::string kFormTypes[kNumOfFormTypes] = {
    "Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

#endif
