#include "Dog.hpp"

#include <iostream>

#include "constant.hpp"

Dog::Dog() : Animal() {
  this->type_ = kAnimalTypes[kDog];
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

Dog::Dog(const Dog& origin) : Animal() {
  std::cout << kAnimalTypes[kDog] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  *this = origin;
}

Dog& Dog::operator=(const Dog& origin) {
  std::cout << kAnimalTypes[kDog] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

Dog::~Dog() {
  std::cout << kAnimalTypes[kDog] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

void Dog::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kDog] << '\n';
}
