#include "util.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "constant.hpp"

void DisplayHead(void) {
  for (int col = 0; col < kNumOfColumns; ++col) {
    std::cout << std::setfill(' ') << std::setw(kColumnWidth)
              << kDisplayFields[col];
    if (col < kNumOfColumns - 1) {
      std::cout << kFieldSeparator;
    } else {
      std::cout << '\n';
    }
  }
}

std::string SafeGetline(bool prompt) {
  if (prompt) {
    std::cout << "$ ";
  }
  std::string input;
  std::getline(std::cin, input);
  if (std::cin.eof()) {
    std::cout << "\n\n" << kCommandMessages[kExit] << std::endl;
    exit(EXIT_SUCCESS);
  }
  return input;
}

int StrictStoi(int max_value, const std::string& input) {
  if (input.size() != 1) {
    return kError;
  }
  int c = input.at(0) - '0';
  if (0 < c && c <= max_value) {
    return c;
  }
  return kError;
}
