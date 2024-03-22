#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

#include "constant.hpp"

AForm* RobotomyRequestForm::clone(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm() {
  this->setType(kFormTypes[kRR]);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, kSignRR, kExecRR) {
  this->setType(kFormTypes[kRR]);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
    : AForm(origin) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& origin) {
  if (this != &origin) {
    this->setTarget(origin.getTarget());
    this->setSign(origin.getSign());
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
  this->validate(executor);
  std::cout << kDrillingNoise << '\n';
  std::srand(std::clock());
  if (std::rand() & 1) {
    std::cout << this->getTarget() << " has been robotomized successfully!\n";
  } else {
    std::cout << "The robotomy failed.\n";
  }
}
