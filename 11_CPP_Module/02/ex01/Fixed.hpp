#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>
#include <string>

enum IndexOfMessages {
  kDefaultConstructor,
  kIntConstructor,
  kFloatConstructor,
  kCopyConstructor,
  kCopyAssignmentOperator,
  kDestructor,
  kGetter,
};

const int kNumOfMessages = 7;

const std::string kMessages[kNumOfMessages] = {
    "Default constructor",       "Int constructor",
    "Float constructor",         "Copy constructor",
    "Copy assignment operator",  "Destructor",
    "getRawBits member function"};
const std::string kPostfix = " called";

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(const int value);
  explicit Fixed(const float value);
  explicit Fixed(const Fixed& origin);
  Fixed& operator=(const Fixed& origin);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(const int raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  static const int num_of_fractional_bits_ = 8;
  int raw_bits_;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
