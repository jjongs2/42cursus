#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(void) : raw_bits_(0) {
  std::cout << kMessages[kDefaultConstructor] << kPostfix << '\n';
}

Fixed::Fixed(const int value) : raw_bits_(value << num_of_fractional_bits_) {
  std::cout << kMessages[kIntConstructor] << kPostfix << '\n';
}

Fixed::Fixed(const float value)
    : raw_bits_(roundf(value * (1 << num_of_fractional_bits_))) {
  std::cout << kMessages[kFloatConstructor] << kPostfix << '\n';
}

Fixed::Fixed(const Fixed& origin) {
  std::cout << kMessages[kCopyConstructor] << kPostfix << '\n';
  *this = origin;
}

Fixed& Fixed::operator=(const Fixed& origin) {
  std::cout << kMessages[kCopyAssignmentOperator] << kPostfix << '\n';
  if (this != &origin) {
    this->raw_bits_ = origin.getRawBits();
  }
  return *this;
}

Fixed::~Fixed(void) {
  std::cout << kMessages[kDestructor] << kPostfix << std::endl;
}

int Fixed::getRawBits(void) const { return this->raw_bits_; }

void Fixed::setRawBits(const int raw) { this->raw_bits_ = raw; }

float Fixed::toFloat(void) const {
  return ((float)this->raw_bits_ / (1 << num_of_fractional_bits_));
}

int Fixed::toInt(void) const {
  return (this->raw_bits_ >> num_of_fractional_bits_);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
  out << fixed.toFloat();
  return out;
}
