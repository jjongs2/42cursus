#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  AForm* clone(const std::string& target) const;

  RobotomyRequestForm();
  explicit RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& origin);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
  virtual ~RobotomyRequestForm();

  void execute(const Bureaucrat& executor) const;
};

#endif
