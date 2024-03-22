#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

enum IndexOfContactFields {
  kFirstName,
  kLastName,
  kNickname,
  kPhoneNumber,
  kDarkestSecret,
};

const int kNumOfContactFields = 5;

const std::string kEmptyField =
    "입력값이 존재하지 않습니다. 다시 입력해 주세요.";
const std::string kContactFields[kNumOfContactFields] = {
    "first name: ", "last name: ", "nickname: ", "phone number: ",
    "darkest secret: "};

class Contact {
 public:
  void Input(void);
  void DisplayInColumn(int index) const;
  void DisplayVertical(void) const;

 private:
  std::string contents_[kNumOfContactFields];
};

#endif
