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
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& origin);
  Fixed& operator=(const Fixed& origin);
  ~Fixed(void);

  Fixed& operator++(void);
  Fixed& operator--(void);
  const Fixed operator++(int);
  const Fixed operator--(int);

  static Fixed& min(Fixed& f1, Fixed& f2);
  static Fixed& max(Fixed& f1, Fixed& f2);
  static const Fixed& min(const Fixed& f1, const Fixed& f2);
  static const Fixed& max(const Fixed& f1, const Fixed& f2);

  int getRawBits(void) const;
  void setRawBits(const int raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  static const int num_of_fractional_bits_ = 8;
  int raw_bits_;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

bool operator>(const Fixed& left, const Fixed& right);
bool operator<(const Fixed& left, const Fixed& right);
bool operator>=(const Fixed& left, const Fixed& right);
bool operator<=(const Fixed& left, const Fixed& right);
bool operator==(const Fixed& left, const Fixed& right);
bool operator!=(const Fixed& left, const Fixed& right);

Fixed operator+(const Fixed& left, const Fixed& right);
Fixed operator-(const Fixed& left, const Fixed& right);
Fixed operator*(const Fixed& left, const Fixed& right);
Fixed operator/(const Fixed& left, const Fixed& right);

#endif
