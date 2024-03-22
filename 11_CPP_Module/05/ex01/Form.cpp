#include "Form.hpp"

#include "constant.hpp"

const char* Form::GradeTooHighException::what(void) const throw() {
  return "grade is too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
  return "grade is too low";
}

Form::Form()
    : name_(kUndefined),
      grade_to_sign_(kDefault),
      grade_to_exec_(kDefault),
      sign_(false) {}

Form::Form(const std::string& name, const int grade_to_sign,
           const int grade_to_exec)
    : name_(name),
      grade_to_sign_(kDefault),
      grade_to_exec_(kDefault),
      sign_(false) {
  this->setRequiredGrade(kGradeToSign, grade_to_sign);
  this->setRequiredGrade(kGradeToExec, grade_to_exec);
}

Form::Form(const Form& origin)
    : grade_to_sign_(kDefault), grade_to_exec_(kDefault) {
  *this = origin;
}

Form& Form::operator=(const Form& origin) {
  if (this != &origin) {
    const_cast<std::string&>(this->name_) = origin.getName();
    this->setRequiredGrade(kGradeToSign, origin.getGradeToSign());
    this->setRequiredGrade(kGradeToExec, origin.getGradeToExec());
    this->sign_ = origin.getSign();
  }
  return *this;
}

Form::~Form() {}

const std::string& Form::getName(void) const { return this->name_; }

bool Form::getSign(void) const { return this->sign_; }

int Form::getGradeToSign(void) const { return this->grade_to_sign_; }

int Form::getGradeToExec(void) const { return this->grade_to_exec_; }

void Form::setSign(const bool sign) { this->sign_ = sign; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->grade_to_sign_) {
    throw Form::GradeTooLowException();
  }
  this->sign_ = true;
}

void Form::setRequiredGrade(const int index, const int grade) {
  if (grade < kGradeRange[kHigh]) {
    throw Form::GradeTooHighException();
  }
  if (grade > kGradeRange[kLow]) {
    throw Form::GradeTooLowException();
  }
  switch (index) {
    case kGradeToSign: {
      const_cast<int&>(this->grade_to_sign_) = grade;
      return;
    }
    case kGradeToExec: {
      const_cast<int&>(this->grade_to_exec_) = grade;
      return;
    }
    default: {
      return;
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
  out << std::boolalpha << kFormInfo[kTitle] << '\n'
      << kFormInfo[kName] << form.getName() << '\n'
      << kFormInfo[kSign] << form.getSign() << '\n'
      << kFormInfo[kGradeToSign] << form.getGradeToSign() << '\n'
      << kFormInfo[kGradeToExec] << form.getGradeToExec() << '\n';
  return out;
}
