#include "Contact.hpp"

#include <iomanip>
#include <iostream>

#include "constant.hpp"
#include "util.hpp"

void Contact::Input(void) {
  for (int i = 0; i < kNumOfContactFields; ++i) {
    while (true) {
      std::cout << kContactFields[i];
      std::string content = SafeGetline(false);
      if (!content.empty()) {
        this->contents_[i] = content;
        break;
      }
      std::cout << '\n' << kEmptyField << '\n';
    }
  }
}

void Contact::DisplayInColumn(int index) const {
  std::cout << std::setfill(' ') << std::setw(kColumnWidth) << index;
  for (int i = kFirstName; i <= kNickname; ++i) {
    std::cout << kFieldSeparator;
    std::string content = this->contents_[i];
    std::string truncated =
        content.size() > kColumnWidth ? content.substr(0, 9) + "." : content;
    std::cout << std::setfill(' ') << std::setw(kColumnWidth) << truncated;
  }
  std::cout << '\n';
}

void Contact::DisplayVertical(void) const {
  std::cout << '\n';
  for (int i = 0; i < kNumOfContactFields; ++i) {
    std::cout << kContactFields[i] << this->contents_[i] << '\n';
  }
}
