#include <iostream>

#include "PhoneBook.hpp"
#include "constant.hpp"
#include "util.hpp"

int main(void) {
  PhoneBook phonebook;
  while (true) {
    std::cout << kMessages[kDefault] << '\n';
    std::string command = SafeGetline();
    std::cout << '\n';
    if (command == kCommands[kAdd]) {
      phonebook.Add();
    } else if (command == kCommands[kSearch]) {
      phonebook.Search();
    } else if (command == kCommands[kExit]) {
      phonebook.Exit();
    } else {
      std::cout << kMessages[kCommandError] << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}
