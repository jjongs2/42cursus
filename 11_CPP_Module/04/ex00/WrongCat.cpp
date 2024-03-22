#include "WrongCat.hpp"

#include <iostream>

#include "constant.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  this->type_ = kAnimalTypes[kCat];
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

WrongCat::WrongCat(const WrongCat& origin) : WrongAnimal() {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  *this = origin;
}

WrongCat& WrongCat::operator=(const WrongCat& origin) {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << kAnimalTypes[kCat] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kCat] << '\n';
}
