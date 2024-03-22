#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  Bureaucrat();
  Bureaucrat(const std::string& name, const int grade);
  Bureaucrat(const Bureaucrat& origin);
  Bureaucrat& operator=(const Bureaucrat& origin);
  virtual ~Bureaucrat();

  const std::string& getName(void) const;
  int getGrade(void) const;

  void setGrade(const int grade);

  void increaseGrade(void);
  void decreaseGrade(void);
  void signForm(AForm& form) const;
  void executeForm(const AForm& form) const;

 private:
  const std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
