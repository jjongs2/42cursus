#include "PresidentialPardonForm.hpp"

#include "constant.hpp"

AForm* PresidentialPardonForm::clone(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
  this->setType(kFormTypes[kPP]);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, kSignPP, kExecPP) {
  this->setType(kFormTypes[kPP]);
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& origin)
    : AForm(origin) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& origin) {
  if (this != &origin) {
    this->setTarget(origin.getTarget());
    this->setSign(origin.getSign());
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
  this->validate(executor);
  std::cout << this->getTarget()
            << " has been pardoned by Zaphod Beeblebrox.\n";
}
