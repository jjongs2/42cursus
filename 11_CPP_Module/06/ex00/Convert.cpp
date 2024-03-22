#include "Convert.hpp"

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cfloat>
Convert::Convert() : literal_(kUndefined), value_(kDefault) {}

Convert::Convert(const std::string& input)
    : literal_(input), value_(std::strtod(input.c_str(), &this->literal_end_)) {
  this->validate();
  this->toChar();
  this->toInt();
  this->converted_ << std::setprecision(1) << std::fixed;
  this->toFloat();
  this->toDouble();
}

Convert::Convert(const Convert& origin) : value_(kDefault) { *this = origin; }

Convert& Convert::operator=(const Convert& origin) {
  if (this != &origin) {
    const_cast<std::string&>(this->literal_) = origin.getLiteral();
    const_cast<double&>(this->value_) = origin.getValue();
    this->literal_end_ = origin.getLiteralEnd();
    this->converted_.str(origin.getConverted());
  }
  return *this;
}

Convert::~Convert() {}

const std::string& Convert::getLiteral(void) const { return this->literal_; }

double Convert::getValue(void) const { return this->value_; }

char* Convert::getLiteralEnd(void) const { return this->literal_end_; }

std::string Convert::getConverted(void) const { return this->converted_.str(); }

void Convert::toChar(void) {
  this->converted_ << kTypes[kChar];
  if (std::isinf(this->value_) || std::isnan(this->value_) ||
      this->value_ < std::numeric_limits<char>::min() ||
      this->value_ > std::numeric_limits<char>::max() || errno == ERANGE) {
    this->converted_ << kMessages[kImpossible] << '\n';
    return;
  }
  const char literal = static_cast<char>(this->value_);
  if (!std::isprint(literal)) {
    this->converted_ << kMessages[kNotPrintable] << '\n';
    return;
  }
  this->converted_ << "'" << literal << "'\n";
}

void Convert::toInt(void) {
  this->converted_ << kTypes[kInt];
  if (std::isinf(this->value_) || std::isnan(this->value_) ||
      this->value_ < std::numeric_limits<int>::min() ||
      this->value_ > std::numeric_limits<int>::max() || errno == ERANGE) {
    this->converted_ << kMessages[kImpossible] << '\n';
    return;
  }
  this->converted_ << static_cast<int>(this->value_) << '\n';
}

void Convert::toFloat(void) {
  this->converted_ << kTypes[kFloat];
  if (errno == ERANGE) {
    this->converted_ << kMessages[kImpossible] << '\n';
    return;
  }
  if (std::isinf(this->value_) || std::isnan(this->value_)) {
    this->converted_ << this->value_ << "f\n";
    return;
  }
  if (this->value_ < -std::numeric_limits<float>::max() ||
      this->value_ > std::numeric_limits<float>::max()) {
    this->converted_ << kMessages[kImpossible] << '\n';
    return;
  }
  this->converted_ << this->value_ << "f\n";
}

void Convert::toDouble(void) {
  this->converted_ << kTypes[kDouble];
  if (errno == ERANGE) {
    this->converted_ << kMessages[kImpossible] << '\n';
    return;
  }
  if (std::isinf(this->value_) || std::isnan(this->value_)) {
    this->converted_ << this->value_ << '\n';
    return;
  }
  this->converted_ << this->value_ << '\n';
}

void Convert::resetConverted(void) { this->converted_.str(""); }

void Convert::validate(void) {
  if (this->literal_.size() == 1) {
    const char literal = this->literal_.at(0);
    if (!std::isprint(literal)) {
      throw std::invalid_argument(kErrors[kINVAL]);
    }
    if (*this->literal_end_) {
      const_cast<double&>(this->value_) = literal;
    }
    return;
  }
  if (*this->literal_end_ == 'f') {
    this->literal_end_ += 1;
  }
  if (*this->literal_end_) {
    throw std::invalid_argument(kErrors[kINVAL]);
  }
}

std::ostream& operator<<(std::ostream& out, const Convert& convert) {
  out << convert.getConverted();
  return out;
}
