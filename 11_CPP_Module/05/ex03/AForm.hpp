#ifndef AFORM_HPP_
#define AFORM_HPP_

#include "Bureaucrat.hpp"

class AForm {
 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class NotSignedException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class FileOpenFailedException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  virtual AForm* clone(const std::string& target) const = 0;

  AForm();
  AForm(const std::string& target, const int grade_to_sign_,
        const int grade_to_exec_);
  AForm(const AForm& origin);
  AForm& operator=(const AForm& origin);
  virtual ~AForm();

  const std::string& getTarget(void) const;
  const std::string& getType(void) const;
  int getGradeToSign(void) const;
  int getGradeToExec(void) const;
  bool getSign(void) const;

  void setSign(const bool sign);

  void beSigned(const Bureaucrat& bureaucrat);
  void validate(const Bureaucrat& executor) const;
  virtual void execute(const Bureaucrat& executor) const = 0;

 protected:
  void setTarget(const std::string& target);
  void setType(const std::string& type);
  void setRequiredGrade(const int index, const int grade);

 private:
  const std::string target_;
  const std::string type_;
  const int grade_to_sign_;
  const int grade_to_exec_;
  bool sign_;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
