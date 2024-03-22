#include "WrongAnimal.hpp"

#include <iostream>

#include "constant.hpp"

WrongAnimal::WrongAnimal() : type_(kAnimalTypes[kAnimal]) {
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& origin) {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  *this = origin;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origin) {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

const std::string& WrongAnimal::getType(void) const { return this->type_; }

void WrongAnimal::setType(const std::string& type) { this->type_ = type; }

void WrongAnimal::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kAnimal] << '\n';
}
