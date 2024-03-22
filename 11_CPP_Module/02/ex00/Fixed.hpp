#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <string>

enum IndexOfMessages {
  kDefaultConstructor,
  kCopyConstructor,
  kCopyAssignmentOperator,
  kDestructor,
  kGetter,
};

const int kNumOfMessages = 5;

const std::string kMessages[kNumOfMessages] = {
    "Default constructor", "Copy constructor", "Copy assignment operator",
    "Destructor", "getRawBits member function"};
const std::string kPostfix = " called";

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(const Fixed& origin);
  Fixed& operator=(const Fixed& origin);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(const int raw);

 private:
  static const int fractional_bits_ = 8;
  int raw_bits_;
};

#endif
