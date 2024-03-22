#include "Animal.hpp"

#include <iostream>

#include "constant.hpp"

Animal::Animal() : type_(kAnimalTypes[kAnimal]) {
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

Animal::Animal(const Animal& origin) {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kCopyConstructor] << kSuffix
            << '\n';
  *this = origin;
}

Animal& Animal::operator=(const Animal& origin) {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kCopyAssignmentOperator]
            << kSuffix << '\n';
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

Animal::~Animal() {
  std::cout << kAnimalTypes[kAnimal] << kMessages[kDestructor] << kSuffix
            << std::endl;
}

const std::string& Animal::getType(void) const { return this->type_; }

void Animal::setType(const std::string& type) { this->type_ = type; }

void Animal::makeSound(void) const {
  std::cout << this->type_ << "makes sound: " << kAnimalSounds[kAnimal] << '\n';
}
