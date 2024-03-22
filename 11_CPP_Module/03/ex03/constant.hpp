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
  kFragHP = 100,
  kFragEP = 100,
  kFragAD = 30,
};
enum IndexOfMessages {
  kDefaultConstructor,
  kNameConstructor,
  kCopyConstructor,
  kCopyAssignmentOperator,
  kDestructor,
};
enum IndexOfPrefix {
  kMyName,
  kMyClapName,
};
enum IndexOfStatus {
  kName,
  kHP,
  kEP,
};
enum IndexOfSuffix {
  kMessage,
  kClapName,
};
enum IndexOfTraps {
  kClap,
  kScav,
  kFrag,
  kDiamond,
};

const int kNumOfMessages = 5;
const int kNumOfPrefix = 2;
const int kNumOfStatus = 3;
const int kNumOfSuffix = 2;
const int kNumOfTraps = 4;

const std::string kUndefined = "undefined";
const std::string kMessages[kNumOfMessages] = {
    "Default constructor", "Name Constructor", "Copy constructor",
    "Copy assignment operator", "Destructor"};
const std::string kPrefix[kNumOfPrefix] = {"My name is ",
                                           "My ClapTrap name is "};
const std::string kStatus[kNumOfStatus] = {"[", "] HP: ", ", EP: "};
const std::string kSuffix[kNumOfSuffix] = {" called", "_clap_name"};
const std::string kTraps[kNumOfTraps] = {"ClapTrap ", "ScavTrap ", "FragTrap ",
                                         "DiamondTrap "};

#endif
