#include "AMateria.hpp"

#include "constant.hpp"

AMateria::AMateria() : type_(kUndefined) {}

AMateria::AMateria(const std::string& type) : type_(type) {}

AMateria::AMateria(const AMateria& origin) { *this = origin; }

AMateria& AMateria::operator=(const AMateria& origin) {
  if (this != &origin) {
    this->type_ = origin.getType();
  }
  return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType(void) const { return this->type_; }

void AMateria::setType(const std::string& type) { this->type_ = type; }
