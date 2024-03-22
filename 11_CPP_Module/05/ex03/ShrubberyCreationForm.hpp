#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  AForm* clone(const std::string& target) const;

  ShrubberyCreationForm();
  explicit ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& origin);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
  virtual ~ShrubberyCreationForm();

  void execute(const Bureaucrat& executor) const;
};

#endif
