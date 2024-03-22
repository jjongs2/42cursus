#include "Harl.hpp"

#include <iostream>

#include "constant.hpp"

void Harl::complain(const std::string& level) {
  int index;
  for (index = 0; index < kNumOfLevels; ++index) {
    if (level == kLevels[index]) break;
  }
  switch (index) {
    case kDebug: {
      this->debug();
      std::cout << '\n';
      __attribute__((fallthrough));
    }
    case kInfo: {
      this->info();
      std::cout << '\n';
      __attribute__((fallthrough));
    }
    case kWarning: {
      this->warning();
      std::cout << '\n';
      __attribute__((fallthrough));
    }
    case kError: {
      this->error();
      break;
    }
    default: {
      this->nothing();
      break;
    }
  }
}

void Harl::debug(void) {
  std::cout << kTitleFormats[kPrefix] << kLevels[kDebug]
            << kTitleFormats[kPostfix] << '\n'
            << kMessages[kDebug] << '\n';
}

void Harl::info(void) {
  std::cout << kTitleFormats[kPrefix] << kLevels[kInfo]
            << kTitleFormats[kPostfix] << '\n'
            << kMessages[kInfo] << '\n';
}

void Harl::warning(void) {
  std::cout << kTitleFormats[kPrefix] << kLevels[kWarning]
            << kTitleFormats[kPostfix] << '\n'
            << kMessages[kWarning] << '\n';
}

void Harl::error(void) {
  std::cout << kTitleFormats[kPrefix] << kLevels[kError]
            << kTitleFormats[kPostfix] << '\n'
            << kMessages[kError] << '\n';
}

void Harl::nothing(void) {
  std::cout << kTitleFormats[kPrefix] << kMessages[kNothing]
            << kTitleFormats[kPostfix] << '\n';
}
