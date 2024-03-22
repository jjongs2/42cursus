#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(void) : raw_bits_(0) {}

Fixed::Fixed(const int value) : raw_bits_(value << num_of_fractional_bits_) {}

Fixed::Fixed(const float value)
    : raw_bits_(roundf(value * (1 << num_of_fractional_bits_))) {}

Fixed::Fixed(const Fixed& origin) { *this = origin; }

Fixed& Fixed::operator=(const Fixed& origin) {
  if (this != &origin) {
    this->raw_bits_ = origin.getRawBits();
  }
  return *this;
}

Fixed::~Fixed(void) {}

bool Fixed::operator>(const Fixed& right) const {
  return (this->raw_bits_ > right.getRawBits());
}

bool Fixed::operator<(const Fixed& right) const {
  return (this->raw_bits_ < right.getRawBits());
}

bool Fixed::operator>=(const Fixed& right) const {
  return (this->raw_bits_ >= right.getRawBits());
}

bool Fixed::operator<=(const Fixed& right) const {
  return (this->raw_bits_ <= right.getRawBits());
}

bool Fixed::operator==(const Fixed& right) const {
  return (this->raw_bits_ == right.getRawBits());
}

bool Fixed::operator!=(const Fixed& right) const {
  return (this->raw_bits_ != right.getRawBits());
}

Fixed Fixed::operator+(const Fixed& right) const {
  return Fixed(this->toFloat() + right.toFloat());
}

Fixed Fixed::operator-(const Fixed& right) const {
  return Fixed(this->toFloat() - right.toFloat());
}

Fixed Fixed::operator*(const Fixed& right) const {
  return Fixed(this->toFloat() * right.toFloat());
}

Fixed Fixed::operator/(const Fixed& right) const {
  return Fixed(this->toFloat() / right.toFloat());
}

Fixed& Fixed::operator++(void) {
  this->raw_bits_ += 1;
  return *this;
}

Fixed& Fixed::operator--(void) {
  this->raw_bits_ -= 1;
  return *this;
}

const Fixed Fixed::operator++(int) {
  const Fixed before(*this);
  ++(*this);
  return before;
}

const Fixed Fixed::operator--(int) {
  const Fixed before(*this);
  --(*this);
  return before;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) { return (f2 < f1 ? f2 : f1); }

Fixed& Fixed::max(Fixed& f1, Fixed& f2) { return (f2 > f1 ? f2 : f1); }

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
  return (f2 < f1 ? f2 : f1);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
  return (f2 > f1 ? f2 : f1);
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
