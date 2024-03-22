#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name_(name), weapon_(weapon) {}

void HumanA::attack(void) const {
  std::cout << this->name_ << kAttackMessageA << this->weapon_.getType()
            << '\n';
}
