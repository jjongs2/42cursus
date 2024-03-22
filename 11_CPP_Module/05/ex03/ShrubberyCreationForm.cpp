#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <sstream>

#include "constant.hpp"

static void copyContent(const char* filename_in, const char* filename_out) {
  std::ifstream infile(filename_in);
  if (!infile.is_open()) {
    throw AForm::FileOpenFailedException();
  }
  std::ostringstream content;
  content << infile.rdbuf();
  infile.close();

  std::ofstream outfile(filename_out);
  if (!outfile.is_open()) {
    throw AForm::FileOpenFailedException();
  }
  outfile << content.str();
  outfile.close();
}

AForm* ShrubberyCreationForm::clone(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
  this->setType(kFormTypes[kSC]);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, kSignSC, kExecSC) {
  this->setType(kFormTypes[kSC]);
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& origin)
    : AForm(origin) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& origin) {
  if (this != &origin) {
    this->setTarget(origin.getTarget());
    this->setSign(origin.getSign());
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
  this->validate(executor);
  const std::string filename = this->getTarget() + "_shrubbery";
  copyContent("Pepe.txt", filename.c_str());
}
