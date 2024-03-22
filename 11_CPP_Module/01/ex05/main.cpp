#include <iostream>

#include "Harl.hpp"

int main(void) {
  Harl harl;
  for (int i = kNumOfLevels - 1; i >= 0; --i) {
    harl.complain(kLevels[i]);
    if (i == 0) break;
    std::cout << '\n';
  }
  return 0;
}
