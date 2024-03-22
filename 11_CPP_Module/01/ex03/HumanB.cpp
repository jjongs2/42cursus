#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon) { this->weapon_ = &weapon; }

void HumanB::attack(void) const {
  std::cout << this->name_ << kAttackMessageB << this->weapon_->getType()
            << '\n';
}
