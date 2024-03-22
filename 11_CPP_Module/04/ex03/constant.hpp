#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfTypes {
  kIce,
  kCure,
};

const int kNumOfMaterias = 4;
const int kNumOfTypes = 2;

const std::string kUndefined = "undefined";
const std::string kTypes[kNumOfTypes] = {"ice", "cure"};

#endif
