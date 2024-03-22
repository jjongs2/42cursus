#include "Cure.hpp"

#include <iostream>

#include "constant.hpp"

AMateria* Cure::clone(void) const { return new Cure(); }

Cure::Cure() : AMateria(kTypes[kCure]) {}

Cure::Cure(const Cure& origin) : AMateria() { *this = origin; }

Cure& Cure::operator=(const Cure& origin) {
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

Cure::~Cure() {}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
