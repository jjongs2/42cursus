#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfLevels {
  kDebug,
  kInfo,
  kWarning,
  kError,
  kNothing,
};
enum IndexOfTitleFormats {
  kPrefix,
  kPostfix,
};

const int kNumOfLevels = 4;
const int kNumOfTitleFormats = 2;

const std::string kEINVAL = "Invalid argument";
const std::string kLevels[kNumOfLevels] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const std::string kMessages[kNumOfLevels + 1] = {
    "I love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!",
    "I cannot believe adding extra bacon costs more money. You didn't put "
    "enough bacon in my burger! If you did, I wouldn't be asking for more!",
    "I think I deserve to have some extra bacon for free. I've been coming for "
    "years whereas you started working here since last month.",
    "This is unacceptable! I want to speak to the manager now.",
    "Probably complaining about insignificant problems"};
const std::string kTitleFormats[kNumOfTitleFormats] = {"[ ", " ]"};

#endif
