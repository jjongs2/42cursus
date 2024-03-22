#include "Cat.hpp"

#include <iostream>

#include "constant.hpp"

Cat::Cat() : Animal() {
  this->type_ = kAnimalTypes[kCat];
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

Cat::Cat(const Cat& origin) : Animal() {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  *this = origin;
}

Cat& Cat::operator=(const Cat& origin) {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

Cat::~Cat() {
  std::cout << kAnimalTypes[kCat] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

void Cat::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kCat] << '\n';
}
