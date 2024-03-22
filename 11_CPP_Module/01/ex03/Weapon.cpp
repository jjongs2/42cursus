#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {}

const std::string& Weapon::getType(void) const { return this->type_; }

void Weapon::setType(const std::string& type) { this->type_ = type; }
