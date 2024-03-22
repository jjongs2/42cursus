#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#include <iostream>
#include <sstream>

#include "constant.hpp"

class Convert {
 public:
  Convert();
  explicit Convert(const std::string& input);
  Convert(const Convert& origin);
  Convert& operator=(const Convert& origin);
  virtual ~Convert();

  const std::string& getLiteral(void) const;
  double getValue(void) const;
  char* getLiteralEnd(void) const;
  std::string getConverted(void) const;

  void toChar(void);
  void toInt(void);
  void toFloat(void);
  void toDouble(void);

  void resetConverted(void);
  void validate(void);

 private:
  const std::string literal_;
  const double value_;
  char* literal_end_;
  std::ostringstream converted_;
};

std::ostream& operator<<(std::ostream& out, const Convert& convert);

#endif
