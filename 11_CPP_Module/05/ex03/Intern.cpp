#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static AForm* makeFormSC(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

static AForm* makeFormRR(const std::string& target) {
  return new RobotomyRequestForm(target);
}

static AForm* makeFormPP(const std::string& target) {
  return new PresidentialPardonForm(target);
}

const char* Intern::InvalidFormNameException::what(void) const throw() {
  return "The form name passed as parameter doesn't exist.";
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
  int index;
  for (index = 0; index < kNumOfFormTypes; ++index) {
    if (name == kFormTypes[index]) {
      std::cout << "Intern creates " << name << '\n';
      return (this->clones[index])(target);
    }
  }
  throw Intern::InvalidFormNameException();
}

Intern::Intern() {
  this->clones[kSC] = makeFormSC;
  this->clones[kRR] = makeFormRR;
  this->clones[kPP] = makeFormPP;
}

Intern::Intern(const Intern& origin) { static_cast<void>(origin); }

Intern& Intern::operator=(const Intern& origin) {
  static_cast<void>(origin);
  return *this;
}

Intern::~Intern() {}
