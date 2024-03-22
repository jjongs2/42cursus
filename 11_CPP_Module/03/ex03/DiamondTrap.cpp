#include "DiamondTrap.hpp"

#include <iostream>

#include "constant.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap(), FragTrap(), ScavTrap(), name_(kUndefined) {
  this->type_ = kTraps[kDiamond];
  this->hit_points_ = kFragHP;
  this->energy_points_ = kScavEP;
  this->attack_damage_ = kFragAD;
  std::cout << this->type_ << kMessages[kDefaultConstructor]
            << kSuffix[kMessage] << '\n';
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + kSuffix[kClapName]), FragTrap(), ScavTrap(), name_(name) {
  this->type_ = kTraps[kDiamond];
  this->hit_points_ = kFragHP;
  this->energy_points_ = kScavEP;
  this->attack_damage_ = kFragAD;
  std::cout << this->type_ << kMessages[kNameConstructor] << kSuffix[kMessage]
            << '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin)
    : ClapTrap(), FragTrap(), ScavTrap() {
  std::cout << kTraps[kDiamond] << kMessages[kCopyConstructor]
            << kSuffix[kMessage] << '\n';
  *this = origin;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin) {
  std::cout << kTraps[kDiamond] << kMessages[kCopyAssignmentOperator]
            << kSuffix[kMessage] << '\n';
  if (this != &origin) {
    ClapTrap::name_ = origin.getName() + kSuffix[kClapName];
    this->name_ = origin.getName();
    this->hit_points_ = origin.getHitPoints();
    this->energy_points_ = origin.getEnergyPoints();
    this->attack_damage_ = origin.getAttackDagmage();
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << kTraps[kDiamond] << kMessages[kDestructor] << kSuffix[kMessage]
            << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << kPrefix[kMyName] << this->name_ << ".\n"
            << kPrefix[kMyClapName] << ClapTrap::name_ << ".\n\n";
}
