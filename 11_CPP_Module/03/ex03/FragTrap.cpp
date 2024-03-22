#include "FragTrap.hpp"

#include <iostream>

#include "constant.hpp"

FragTrap::FragTrap() : ClapTrap() {
  this->type_ = kTraps[kFrag];
  this->hit_points_ = kFragHP;
  this->energy_points_ = kFragEP;
  this->attack_damage_ = kFragAD;
  std::cout << this->type_ << kMessages[kDefaultConstructor]
            << kSuffix[kMessage] << '\n';
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  this->type_ = kTraps[kFrag];
  this->hit_points_ = kFragHP;
  this->energy_points_ = kFragEP;
  this->attack_damage_ = kFragAD;
  std::cout << this->type_ << kMessages[kNameConstructor] << kSuffix[kMessage]
            << '\n';
}

FragTrap::FragTrap(const FragTrap& origin) : ClapTrap() {
  std::cout << kTraps[kFrag] << kMessages[kCopyConstructor] << kSuffix[kMessage]
            << '\n';
  *this = origin;
}

FragTrap& FragTrap::operator=(const FragTrap& origin) {
  std::cout << kTraps[kFrag] << kMessages[kCopyAssignmentOperator]
            << kSuffix[kMessage] << '\n';
  if (this != &origin) {
    this->name_ = origin.getName();
    this->hit_points_ = origin.getHitPoints();
    this->energy_points_ = origin.getEnergyPoints();
    this->attack_damage_ = origin.getAttackDagmage();
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << kTraps[kFrag] << kMessages[kDestructor] << kSuffix[kMessage]
            << std::endl;
}

void FragTrap::highFivesGuys(void) {
  if (this->hit_points_ == 0 || this->energy_points_ == 0) return;
  this->energy_points_ -= 1;
  std::cout << this->type_ << this->name_ << " requests positive high fives!\n";
  this->displayStatus();
}
