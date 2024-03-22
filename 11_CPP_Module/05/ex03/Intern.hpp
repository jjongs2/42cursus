#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"
#include "constant.hpp"

class Intern {
 public:
  class InvalidFormNameException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  AForm* makeForm(const std::string& name, const std::string& target);

  Intern();
  Intern(const Intern& origin);
  Intern& operator=(const Intern& origin);
  virtual ~Intern();

 private:
  AForm* (*clones[kNumOfFormTypes])(const std::string& target);
};

#endif
