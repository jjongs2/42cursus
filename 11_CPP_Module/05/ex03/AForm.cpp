#include "AForm.hpp"

#include "constant.hpp"

const char* AForm::GradeTooHighException::what(void) const throw() {
  return "grade is too high";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
  return "grade is too low";
}

const char* AForm::NotSignedException::what(void) const throw() {
  return "the form is not signed";
}

const char* AForm::FileOpenFailedException::what(void) const throw() {
  return "file open failed";
}

AForm::AForm()
    : target_(kUndefined),
      type_(kUndefined),
      grade_to_sign_(kDefault),
      grade_to_exec_(kDefault),
      sign_(false) {}

AForm::AForm(const std::string& target, const int grade_to_sign_,
             const int grade_to_exec_)
    : target_(target),
      type_(kUndefined),
      grade_to_sign_(kDefault),
      grade_to_exec_(kDefault),
      sign_(false) {
  this->setRequiredGrade(kGradeToSign, grade_to_sign_);
  this->setRequiredGrade(kGradeToExec, grade_to_exec_);
}

AForm::AForm(const AForm& origin)
    : grade_to_sign_(kDefault), grade_to_exec_(kDefault) {
  *this = origin;
}

AForm& AForm::operator=(const AForm& origin) {
  if (this != &origin) {
    const_cast<std::string&>(this->target_) = origin.getTarget();
    this->setType(origin.getType());
    this->setRequiredGrade(kGradeToSign, origin.getGradeToSign());
    this->setRequiredGrade(kGradeToExec, origin.getGradeToExec());
    this->sign_ = origin.getSign();
  }
  return *this;
}

AForm::~AForm() {}

const std::string& AForm::getTarget(void) const { return this->target_; }

const std::string& AForm::getType(void) const { return this->type_; }

bool AForm::getSign(void) const { return this->sign_; }

int AForm::getGradeToSign(void) const { return this->grade_to_sign_; }

int AForm::getGradeToExec(void) const { return this->grade_to_exec_; }

void AForm::setSign(const bool sign) { this->sign_ = sign; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->grade_to_sign_) {
    throw AForm::GradeTooLowException();
  }
  this->sign_ = true;
}

void AForm::validate(const Bureaucrat& executor) const {
  if (!this->sign_) {
    throw AForm::NotSignedException();
  }
  if (executor.getGrade() > this->grade_to_exec_) {
    throw AForm::GradeTooLowException();
  }
}

void AForm::setTarget(const std::string& target) {
  const_cast<std::string&>(this->target_) = target;
}

void AForm::setType(const std::string& type) {
  const_cast<std::string&>(this->type_) = type;
}

void AForm::setRequiredGrade(const int index, const int grade) {
  if (grade < kGradeRange[kHigh]) {
    throw AForm::GradeTooHighException();
  }
  if (grade > kGradeRange[kLow]) {
    throw AForm::GradeTooLowException();
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

std::ostream& operator<<(std::ostream& out, const AForm& form) {
  out << std::boolalpha << "[ " << form.getType() << " form ]\n"
      << kFormInfo[kTarget] << form.getTarget() << '\n'
      << kFormInfo[kSign] << form.getSign() << '\n'
      << kFormInfo[kGradeToSign] << form.getGradeToSign() << '\n'
      << kFormInfo[kGradeToExec] << form.getGradeToExec() << '\n';
  return out;
}
