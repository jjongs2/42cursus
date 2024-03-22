#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"

class Form {
 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  Form();
  Form(const std::string& target, const int grade_to_sign,
       const int grade_to_exec);
  Form(const Form& origin);
  Form& operator=(const Form& origin);
  virtual ~Form();

  const std::string& getName(void) const;
  int getGradeToSign(void) const;
  int getGradeToExec(void) const;
  bool getSign(void) const;

  void setSign(const bool sign);

  void beSigned(const Bureaucrat& bureaucrat);

 private:
  void setRequiredGrade(const int index, const int grade);

  const std::string name_;
  const int grade_to_sign_;
  const int grade_to_exec_;
  bool sign_;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
