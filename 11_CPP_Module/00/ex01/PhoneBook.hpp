#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "Contact.hpp"

const int kMaxContacts = 8;

const std::string kNoContact =
    "연락처가 존재하지 않습니다. 먼저 연락처를 추가해 주세요.";

class PhoneBook {
 public:
  PhoneBook();
  void Add(void);
  void Search(void) const;
  void Exit(void) const;

 private:
  Contact contacts_[kMaxContacts];
  int index_;
  int count_;
};

#endif
