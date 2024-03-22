#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  AForm* clone(const std::string& target) const;

  PresidentialPardonForm();
  explicit PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& origin);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
  virtual ~PresidentialPardonForm();

  void execute(const Bureaucrat& executor) const;
};

#endif
