#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfAnimalTypes {
  kAnimal,
  kCat,
  kDog,
};
enum IndexOfMessages {
  kDefaultConstructor,
  kCopyConstructor,
  kCopyAssignmentOperator,
  kDestructor,
};

const int kNumOfAnimalTypes = 3;
const int kNumOfMessages = 4;

const std::string kSuffix = " called";
const std::string kUndefined = "undefined";
const std::string kAnimalTypes[kNumOfAnimalTypes] = {"Animal ", "Cat ", "Dog "};
const std::string kAnimalSounds[kNumOfAnimalTypes] = {kUndefined, "애옹",
                                                      "옭옭"};
const std::string kMessages[kNumOfMessages] = {
    "Default constructor", "Copy constructor", "Copy assignment operator",
    "Destructor"};

#endif
