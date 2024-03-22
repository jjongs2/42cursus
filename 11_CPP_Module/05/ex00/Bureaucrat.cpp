#include "Bureaucrat.hpp"

#include "constant.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "Grade is too low.";
}

Bureaucrat::Bureaucrat() : name_(kUndefined), grade_(kDefault) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name_(name) {
  this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) { *this = origin; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin) {
  if (this != &origin) {
    const_cast<std::string&>(this->name_) = origin.getName();
    this->setGrade(origin.getGrade());
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName(void) const { return this->name_; }

int Bureaucrat::getGrade(void) const { return this->grade_; }

void Bureaucrat::setGrade(const int grade) {
  if (grade < kGradeRange[kHigh]) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > kGradeRange[kLow]) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade_ = grade;
}

void Bureaucrat::increaseGrade(void) { this->setGrade(this->grade_ - 1); }

void Bureaucrat::decreaseGrade(void) { this->setGrade(this->grade_ + 1); }

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
      << ".";
  return out;
}
