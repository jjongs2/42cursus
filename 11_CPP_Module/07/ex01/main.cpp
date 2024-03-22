#include <cctype>
#include <iostream>

#include "iter.hpp"

static void toUpper(char& c) { c = std::toupper(c); }

int main(void) {
  char str[] = "Hello, world!";
  const int size = sizeof(str) / sizeof(*str);

  std::cout << "[before] ";
  ::print(str, size);

  std::cout << " [after] ";
  ::iter(str, size, toUpper);
  ::print(str, size);
  return 0;
}
