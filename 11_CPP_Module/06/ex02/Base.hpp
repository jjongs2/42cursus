#ifndef BASE_HPP_
#define BASE_HPP_

#include <string>

const std::string kPrefix = "Actual type: ";

class Base {
 public:
  virtual ~Base() {}
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
