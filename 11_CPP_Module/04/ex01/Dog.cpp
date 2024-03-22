#include "Dog.hpp"

#include <iostream>

#include "constant.hpp"

Dog::Dog() : Animal() {
  this->type_ = kAnimalTypes[kDog];
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
  this->brain_ = new Brain();
}

Dog::Dog(const Dog& origin) : Animal() {
  std::cout << kAnimalTypes[kDog] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  this->brain_ = new Brain();
  *this = origin;
}

Dog& Dog::operator=(const Dog& origin) {
  std::cout << kAnimalTypes[kDog] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
    *this->brain_ = *origin.getBrain();
  }
  return *this;
}

Dog::~Dog() {
  delete this->brain_;
  this->brain_ = NULL;
  std::cout << kAnimalTypes[kDog] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

Brain* Dog::getBrain(void) const { return this->brain_; }

void Dog::setBrain(Brain* brain) { this->brain_ = brain; }

void Dog::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kDog] << '\n';
}
