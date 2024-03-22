#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum DefaultValues {
  kClapHP = 10,
  kClapEP = 10,
  kClapAD = 0,
  kScavHP = 100,
  kScavEP = 50,
  kScavAD = 20,
};
enum IndexOfMessages {
  kDefaultConstructor,
  kNameConstructor,
  kCopyConstructor,
  kCopyAssignmentOperator,
  kDestructor,
};
enum IndexOfStatus {
  kName,
  kHP,
  kEP,
};
enum IndexOfTraps {
  kClap,
  kScav,
};

const int kNumOfMessages = 5;
const int kNumOfStatus = 3;
const int kNumOfTraps = 2;

const std::string kSuffix = " called";
const std::string kUndefined = "undefined";
const std::string kMessages[kNumOfMessages] = {
    "Default constructor", "Name Constructor", "Copy constructor",
    "Copy assignment operator", "Destructor"};
const std::string kStatus[kNumOfStatus] = {"[", "] HP: ", ", EP: "};
const std::string kTraps[kNumOfTraps] = {"ClapTrap ", "ScavTrap "};

#endif
