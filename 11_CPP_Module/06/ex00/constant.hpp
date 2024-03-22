#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfErrors {
  kPrefix,
  kINVAL,
};
enum IndexOfMessages {
  kNotPrintable,
  kImpossible,
};
enum IndexOfTypes {
  kChar,
  kInt,
  kFloat,
  kDouble,
};

const int kDefault = 0;
const int kNumOfErrors = 2;
const int kNumOfMessages = 2;
const int kNumOfTypes = 4;

const std::string kFloatSuffix = "f";
const std::string kUndefined = "undefined";
const std::string kErrors[kNumOfErrors] = {"Error: ", "Invalid argument"};
const std::string kMessages[kNumOfMessages] = {"Non displayable", "impossible"};
const std::string kTypes[kNumOfTypes] = {
    "char: ", "int: ", "float: ", "double: "};

#endif
