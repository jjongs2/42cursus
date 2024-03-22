#include "Ice.hpp"

#include <iostream>

#include "constant.hpp"

AMateria* Ice::clone(void) const { return new Ice(); }

Ice::Ice() : AMateria(kTypes[kIce]) {}

Ice::Ice(const Ice& origin) : AMateria() { *this = origin; }

Ice& Ice::operator=(const Ice& origin) {
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

Ice::~Ice() {}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
