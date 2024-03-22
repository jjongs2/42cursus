#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : raw_bits_(0) {
  std::cout << kMessages[kDefaultConstructor] << kPostfix << '\n';
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

int Fixed::getRawBits(void) const {
  std::cout << kMessages[kGetter] << kPostfix << '\n';
  return this->raw_bits_;
}

void Fixed::setRawBits(const int raw) { this->raw_bits_ = raw; }
