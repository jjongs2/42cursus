#include "PhoneBook.hpp"

#include <cstdlib>
#include <iostream>

#include "constant.hpp"
#include "util.hpp"

PhoneBook::PhoneBook() : index_(-1), count_(0) {}

void PhoneBook::Add(void) {
  std::cout << kCommandMessages[kAdd] << '\n';
  this->index_ = (this->index_ + 1) % kMaxContacts;
  this->contacts_[this->index_].Input();
  if (this->count_ < kMaxContacts) {
    this->count_ += 1;
  }
}

void PhoneBook::Search(void) const {
  if (this->count_ == 0) {
    std::cout << kNoContact << '\n';
    return;
  }
  std::cout << kCommandMessages[kSearch] << '\n';
  DisplayHead();
  for (int row = 1; row <= this->count_; ++row) {
    int index = this->count_ < kMaxContacts
                    ? row - 1
                    : (this->index_ + row) % kMaxContacts;
    this->contacts_[index].DisplayInColumn(row);
  }
  while (true) {
    int row = StrictStoi(this->count_, SafeGetline());
    if (row != kError) {
      int index = this->count_ < kMaxContacts
                      ? row - 1
                      : (this->index_ + row) % kMaxContacts;
      this->contacts_[index].DisplayVertical();
      break;
    }
    std::cout << '\n' << kMessages[kInputError] << '\n';
  }
}

void PhoneBook::Exit(void) const {
  std::cout << kCommandMessages[kExit] << std::endl;
  exit(EXIT_SUCCESS);
}
