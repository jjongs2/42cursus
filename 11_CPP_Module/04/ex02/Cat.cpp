#include "Cat.hpp"

#include <iostream>

#include "constant.hpp"

Cat::Cat() : Animal() {
  this->type_ = kAnimalTypes[kCat];
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
  this->brain_ = new Brain();
}

Cat::Cat(const Cat& origin) : Animal() {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  this->brain_ = new Brain();
  *this = origin;
}

Cat& Cat::operator=(const Cat& origin) {
  std::cout << kAnimalTypes[kCat] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
    *this->brain_ = *origin.getBrain();
  }
  return *this;
}

Cat::~Cat() {
  delete this->brain_;
  this->brain_ = NULL;
  std::cout << kAnimalTypes[kCat] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

Brain* Cat::getBrain(void) const { return this->brain_; }

void Cat::setBrain(Brain* brain) { this->brain_ = brain; }

void Cat::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kCat] << '\n';
}
