#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
  this->functions[kDebug] = &Harl::debug;
  this->functions[kInfo] = &Harl::info;
  this->functions[kWarning] = &Harl::warning;
  this->functions[kError] = &Harl::error;
}

void Harl::complain(const std::string& level) {
  for (int i = 0; i < kNumOfLevels; ++i) {
    if (level == kLevels[i]) {
      (this->*functions[i])();
      return;
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
